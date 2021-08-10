#include "stdafx.h"
#include <iostream>
#include "gmThread.h"
#include <vector>
#include <string>
#include <sstream>

struct ScriptEntity;
struct Entity;

struct Entity
{
	Entity() : Id(0), X(0), Y(0), ScriptObject(NULL) { }
	Entity(int id) : Id(id), X(0), Y(0), ScriptObject(NULL) { }
	int Id, X, Y;
	ScriptEntity *ScriptObject;
};

struct ScriptEntity
{
	ScriptEntity(Entity &ent) : EntityObject(ent), ScriptProperties(NULL) { }
	Entity &EntityObject;
	gmTableObject *ScriptProperties;
};


class EntityManager 
{
public:
	EntityManager() : _EntityIds(0) { }
	
	Entity &CreateEntity(int &a_entityid)
	{
		Entity e(++_EntityIds);
		a_entityid = e.Id;
		_Entities.push_back(e);
		return _Entities[a_entityid - 1];
	}

	Entity &GetEntity(int a_entityid)
	{
		return _Entities[a_entityid - 1];		
	}

protected:
	typedef std::vector<Entity>		EntityList;
	typedef EntityList::iterator	EntityListItr;

	EntityList _Entities;
	int _EntityIds;

};

//// Global entity manager
static EntityManager s_EntityManager;

namespace gmEntityLib
{
	gmType s_entitytype = GM_NULL;
	gmMemFixed s_scriptents( sizeof(ScriptEntity) );

	// The entity is passed as this
	int GM_CDECL gmEntityInfo(gmThread *a_thread)
	{
		ScriptEntity *sent = reinterpret_cast<ScriptEntity*>(a_thread->ThisUserCheckType(s_entitytype));
		if (sent == NULL)
		{
			a_thread->GetMachine()->GetLog().LogEntry("gmEntityInfo: Expected entity type as this");
			return GM_EXCEPTION;
		}
		std::stringstream infotext;
		infotext << "EntityId: ";
		infotext << sent->EntityObject.Id;
		infotext << " - Postition("; infotext << sent->EntityObject.X; infotext << ","; infotext << sent->EntityObject.Y; infotext << ") - Name: ";
		// Get name from table and pass to object
		gmVariable namevar = sent->ScriptProperties->Get(a_thread->GetMachine(), "name");
		if (namevar.IsNull() || namevar.m_type != GM_STRING)
		{
			infotext << " [No name]";
		}
		else
		{
			infotext << namevar.GetStringObjectSafe()->GetString();
		}
		std::cout << infotext.str() << std::endl;
		return GM_OK;
	}

	int GM_CDECL gmCreateEntity(gmThread *a_thread)
	{
		// Create an entity from the manager
		int entityId = 0;
		Entity &ent = s_EntityManager.CreateEntity(entityId);
		// Allocate a script entity & construct it
		ScriptEntity *sent = reinterpret_cast<ScriptEntity*>(s_scriptents.Alloc());
		GM_PLACEMENT_NEW( ScriptEntity(ent), sent );
		// Tie back to entity
		ent.ScriptObject = sent;
		// Create a property table
		sent->ScriptProperties = a_thread->GetMachine()->AllocTableObject();
		// Tell GM how much memory we're using
		int memadjust = sizeof(gmTableObject) + sizeof(Entity) + sizeof(ScriptEntity);
		a_thread->GetMachine()->AdjustKnownMemoryUsed(memadjust);

		// Bind an additional method to the entity's prop table
		sent->ScriptProperties->Set(a_thread->GetMachine(), "ShowInfo", gmVariable( a_thread->GetMachine()->AllocFunctionObject(gmEntityInfo) ) );

		// return to client
		a_thread->PushNewUser( sent, s_entitytype );
		return GM_OK;
	}


	//// Dot Operators
	void GM_CDECL gmOpGetDot(gmThread *a_thread, gmVariable *a_operands)
	{
		if (a_operands[0].m_type != s_entitytype)
		{
			a_thread->GetMachine()->GetLog().LogEntry( "gmEntity:OpSetDot invalid type passed" );
			a_operands[0] = gmVariable::s_null;
			return;
		}
		
		// Get scriptentity back
		ScriptEntity *sent = reinterpret_cast<ScriptEntity*>(a_operands[0].GetUserSafe(s_entitytype));

		// Get name of 'get' prop
		std::string propname = a_operands[1].GetCStringSafe();
		
		// Test for our known properties and return their values back immediately
		if (propname == "X")
		{
			a_operands[0] = gmVariable(sent->EntityObject.X);
		}
		else if (propname == "Y")
		{
			a_operands[0] = gmVariable(sent->EntityObject.Y);
		}
		else if (propname == "Id")
		{
			a_operands[0] = gmVariable(sent->EntityObject.Id);
		}
		else
		{
			// Otherwise, return the value from the table!
			a_operands[0] = sent->ScriptProperties->Get(a_thread->GetMachine(), propname.c_str());
		}
	}

	void GM_CDECL gmOpSetDot(gmThread *a_thread, gmVariable *a_operands)
	{
		if (a_operands[0].m_type != s_entitytype)
		{
			a_thread->GetMachine()->GetLog().LogEntry( "gmEntity:OpSetDot invalid type passed" );
			a_operands[0] = gmVariable::s_null;
			return;
		}
		
		// Get scriptentity back
		ScriptEntity *sent = reinterpret_cast<ScriptEntity*>(a_operands[0].GetUserSafe(s_entitytype));

		// Get name of 'get' prop
		std::string propname = a_operands[2].GetCStringSafe();
	
		if (propname.length() == 0)
		{
			a_thread->GetMachine()->GetLog().LogEntry( "gmEntity:OpSetDot invalid property passed" );
			a_operands[0] = gmVariable::s_null;
			return;
		}

		// Test for our known properties and return their values back immediately
		if (propname == "X")
		{
			sent->EntityObject.X = a_operands[1].GetIntSafe();
		}
		else if (propname == "Y")
		{
			sent->EntityObject.Y = a_operands[1].GetIntSafe();
		}
		else if (propname == "Id")
		{
			a_thread->GetMachine()->GetLog().LogEntry( "gmEntity:OpSetDot cannot set Id" );
			a_operands[0] = gmVariable::s_null;
		}
		else
		{
			// Otherwise, store a value in the table
			sent->ScriptProperties->Set(a_thread->GetMachine(), propname.c_str(), a_operands[1]);
		}
	}


	///////////////
	// GC operations
	void GM_CDECL gcDestruct(gmMachine *a_machine, gmUserObject *a_object)
	{
		GM_ASSERT( a_object->m_userType == s_entitytype );
		ScriptEntity *sent = reinterpret_cast<ScriptEntity *>(a_object->m_user);
		// Do we want to tell the entitymanager to destry the object here?
		// this will be implementation dependent, so let's not do anything for now as it's a sample		
		// Free up the script entity
		s_scriptents.Free(sent);
		int memadjust = sizeof(gmTableObject) + sizeof(ScriptEntity); // Note, didn;t add Entity sizeof
		a_machine->AdjustKnownMemoryUsed(-memadjust);
	}

	bool GM_CDECL gcTrace(gmMachine *a_machine, gmUserObject *a_object, gmGarbageCollector *a_gc, const int a_workLeftToGo, int &a_workDone)
	{
		GM_ASSERT( a_object->m_userType == s_entitytype );
		ScriptEntity *sent = reinterpret_cast<ScriptEntity *>(a_object->m_user);
		a_workDone++;
		a_gc->GetNextObject(sent->ScriptProperties);
		a_workDone++;
		return true;
	}


	gmFunctionEntry s_lib[] = {
		{ "createEntity", gmCreateEntity, NULL }
	};

	void Bind(gmMachine *a_machine)
	{
		s_entitytype = a_machine->CreateUserType("entity");

		// Register creation function
		a_machine->RegisterLibrary( s_lib, sizeof(s_lib) / sizeof(gmFunctionEntry) );
		a_machine->RegisterTypeOperator( s_entitytype, O_GETDOT, NULL, gmOpGetDot );
		a_machine->RegisterTypeOperator( s_entitytype, O_SETDOT, NULL, gmOpSetDot );	
		// Register GC callbacks
		a_machine->RegisterUserCallbacks( s_entitytype, gcTrace, gcDestruct, NULL );
	}
};

int main(int argc, char* argv[])
{
	// Create gm virtual machine
	gmMachine	gm;
	gmEntityLib::Bind(&gm);

	gm.ExecuteString(
		"ent = createEntity();"
		"ent.X = 100;"
		"print(ent.X);"
		"ent.name = \"somebody\";"
		"ent.sayname = function() { print( \"My name is: \", .name ); };"
		"ent.sayname();"
		"ent.ShowInfo();"
		);

	return 0;
}

