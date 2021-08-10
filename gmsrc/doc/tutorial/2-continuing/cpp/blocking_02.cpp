#include "Windows.h"
#include "stdafx.h"
#include <iostream>
#include "gmThread.h"
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>

namespace gmNPCLib
{
	bool Bind(gmMachine *a_machine);
};

enum
{
	MT_GOTO,
	MT_GOTO_SUCCESS,
	MT_GOTO_FAILED,
};

enum
{
	LOC_UNKNOWN,
	LOC_TOWER_ONE,
	LOC_TOWER_TWO,
};

enum
{
	SM_SUCCESS,
	SM_FAILED,
};

struct GameMessage
{
	GameMessage(int a_MessageType) : MessageType(a_MessageType) { }
	int MessageType;
};

struct NPCGotoMessage : GameMessage
{
	NPCGotoMessage(int a_npc, int a_threadid, int a_loc) : GameMessage(MT_GOTO), NPCId(a_npc), ScriptThreadId(a_threadid), Location(a_loc) { }

	int ScriptThreadId;
	int NPCId;
	int Location;
};

struct NPCArrivalMessage : GameMessage
{
	NPCArrivalMessage(int a_npc, int a_threadid, int a_loc) : GameMessage(MT_GOTO_SUCCESS), NPCId(a_npc), ScriptThreadId(a_threadid), Location(a_loc) { }

	int ScriptThreadId;
	int NPCId;
	int Location;
};

struct IMessageHandler
{
	virtual ~IMessageHandler() {}
	virtual void HandleMessage(GameMessage *a_msg) = 0;
};

class MessageSystem
{
public:
	MessageSystem() : _ActiveQueue(0) { }

	void PushMessage(GameMessage *a_msg)
	{
		_MessageQueues[_ActiveQueue].push_back( a_msg );
	}

	void AddHandler(IMessageHandler *a_handler)
	{
		_Handlers.push_back(a_handler);
	}

	void DespatchMessages()
	{
		// Flip queues
		char InactiveQueue = _ActiveQueue;
		_ActiveQueue = 1 - _ActiveQueue;

		MessageListItr it = _MessageQueues[InactiveQueue].begin();
		for(;it != _MessageQueues[InactiveQueue].end(); ++it)
		{
			GameMessage *msg = (*it);
			
			// Iterate each handler and despatch
			HandlerListItr hit = _Handlers.begin();
			for(; hit != _Handlers.end(); ++hit)
			{
				(*hit)->HandleMessage(msg);
			}

			// finished
			delete msg;
		}
		_MessageQueues[InactiveQueue].clear();
	}

protected:
	typedef std::list<IMessageHandler *> HandlerList;
	typedef HandlerList::iterator		 HandlerListItr;

	typedef std::list<GameMessage*> MessageList;
	typedef MessageList::iterator	MessageListItr;

	HandlerList	_Handlers;

	MessageList _MessageQueues[2];
	char _ActiveQueue;
};


class Entity
{
public:
	enum State
	{
		ES_WAITING,
		ES_WALKING,
	};

	int _ScriptThreadId;
	int _Id;
	int _State;
	int _Destination;
};

class EntityManager : public IMessageHandler
{
public:
	EntityManager() : _EntityIds(0), _Dur(0) { }
	
	Entity &CreateEntity(int &a_entityid)
	{
		a_entityid = ++_EntityIds;
		Entity e;
		e._Id = a_entityid;
		_Entities.push_back(e);
		return _Entities[a_entityid - 1];
	}

	Entity &GetEntity(int a_entityid)
	{
		return _Entities[a_entityid - 1];		
	}

	void HandleMessage(GameMessage *a_msg)
	{
		if (a_msg->MessageType == MT_GOTO)
		{
			NPCGotoMessage *msg = reinterpret_cast<NPCGotoMessage*>(a_msg);
			// Set entity state to walking
			Entity &ent = GetEntity(msg->NPCId);
			ent._State = Entity::ES_WALKING;
		}
	}

	void Update(float a_delta);

protected:
	typedef std::vector<Entity>		EntityList;
	typedef EntityList::iterator	EntityListItr;

	EntityList _Entities;
	float _Dur;
	int _EntityIds;

	
};

class ScriptManager : public IMessageHandler
{
public:

	void Init()
	{
		BindNPCLib();

		LoadScript("blocking_02.gm");
	}

	bool LoadScript(const char *a_filename)
	{
		std::ifstream file(a_filename);
		if (!file)
			return false;
		
		std::string fileString = std::string(std::istreambuf_iterator<char>(file),
											 std::istreambuf_iterator<char>());
		file.close();
		return (_Machine.ExecuteString(fileString.c_str()) == 0);
	}

	void HandleMessage(GameMessage *a_msg)
	{
		if (a_msg->MessageType == MT_GOTO_SUCCESS)
		{
			NPCArrivalMessage *msg = reinterpret_cast<NPCArrivalMessage*>(a_msg);
			// Fire signal on thread
			_Machine.Signal( gmVariable(SM_SUCCESS), msg->ScriptThreadId, 0 );
		}

	}

	void Update(float a_delta)
	{
		_Machine.Execute(a_delta * 1000.0f);
	}

protected:

	bool BindNPCLib()
	{
		return gmNPCLib::Bind(&_Machine);
	}

	gmMachine _Machine;
};

class Game
{
public:

	void Init()
	{
		_ScriptManager.Init();
		_MessageSystem.AddHandler(&_ScriptManager);
		_MessageSystem.AddHandler(&_EntityManager);
		_Running = true;
	}

	void Run()
	{
		while(_Running)
		{
			float delta = 0.01f;
			_MessageSystem.DespatchMessages();

			_ScriptManager.Update(delta);
			_EntityManager.Update(delta);
		}
	}

	EntityManager &GetEntityManager() { return _EntityManager; }
	MessageSystem &GetMessageSystem() { return _MessageSystem; }
	ScriptManager &GetScriptManager() { return _ScriptManager; }

protected:
	bool _Running;

	ScriptManager _ScriptManager;
	EntityManager _EntityManager;
	MessageSystem _MessageSystem;
};

/////// Global variable for game class
Game s_Game;


/// Implementation
void EntityManager::Update(float a_delta)
{
	EntityListItr it = _Entities.begin();
	for(; it != _Entities.end(); ++it)
	{
		Entity &ent = (*it);

		if (ent._State == Entity::ES_WALKING)
		{
			_Dur+=a_delta;
			if (_Dur >= 2500.0f)	// Simulate time passing
			{
				NPCArrivalMessage *msg = new NPCArrivalMessage(ent._Id, ent._ScriptThreadId, ent._Destination);
				s_Game.GetMessageSystem().PushMessage(msg);
				ent._State = Entity::ES_WAITING;	// Go back to waiting state
				_Dur = 0;
			}
		}
	}


}

namespace gmNPCLib
{
	gmType s_type;

	int GM_CDECL gmNPCGoto(gmThread *a_thread)
	{
		GM_CHECK_NUM_PARAMS(2);
		// Get entity
		GM_CHECK_INT_PARAM(a_entity, 0);
		GM_CHECK_INT_PARAM(a_location, 1);
		
		// Push message to Game Message queue
		NPCGotoMessage *msg = new NPCGotoMessage( a_entity, a_thread->GetId(), a_location );
		s_Game.GetMessageSystem().PushMessage( msg );

		// Set up blocks on thread for either success message or failure message
		gmVariable blocks[] = { gmVariable(SM_SUCCESS), gmVariable(SM_FAILED) };
		int res = a_thread->GetMachine()->Sys_Block( a_thread, 2, blocks );
		if (res == -1)
		{
			return GM_SYS_BLOCK;
		}
		a_thread->Push( blocks[res] );
		return GM_OK;
	}

	int GM_CDECL gmCreateNPC(gmThread *a_thread)
	{
		int entity = 0;
		Entity &ent = s_Game.GetEntityManager().CreateEntity(entity);
		ent._ScriptThreadId = a_thread->GetId();
		ent._Destination = LOC_UNKNOWN;
		ent._State = Entity::ES_WAITING;
		a_thread->PushInt(entity);
		return GM_OK;
	}

	gmFunctionEntry s_lib[] = {

		{ "CreateNPC", gmCreateNPC, NULL },
		/// NPCGoto( npc, location )
		{ "NPCGoto", gmNPCGoto, NULL },
	};

	bool Bind(gmMachine *a_machine)
	{
		a_machine->RegisterLibrary( s_lib, sizeof(s_lib) / sizeof(gmFunctionEntry) );

		// Bind location info
		gmTableObject *location = a_machine->AllocTableObject();
		location->Set( a_machine, "TOWER_ONE", gmVariable(LOC_TOWER_ONE) );
		location->Set( a_machine, "TOWER_TWO", gmVariable(LOC_TOWER_TWO) );
		a_machine->GetGlobals()->Set(a_machine, "Location", gmVariable(location) );


		gmTableObject *event = a_machine->AllocTableObject();
		event->Set( a_machine, "SUCCESS", gmVariable(SM_SUCCESS) );
		event->Set( a_machine, "FAILED", gmVariable(SM_FAILED) );
		a_machine->GetGlobals()->Set(a_machine, "Event", gmVariable(event) );

		return true;
	}

};

int main(int argc, char* argv[])
{
/*
	
	gm.ExecuteString(
		"NPCGoto(1, Location.TOWER_ONE);"
		"print(123456);"
		);
*/
	s_Game.Init();
	s_Game.Run();

	return 0;
}

