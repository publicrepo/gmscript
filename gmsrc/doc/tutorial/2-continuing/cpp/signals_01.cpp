#include "Windows.h"
#include "stdafx.h"
#include <iostream>
#include "gmThread.h"


enum QuestDialog
{
	QD_DECLINE,
	QD_ACCEPT
};

// This function simulates a modal quest dialog
int GM_CDECL gmShowQuestDialog(gmThread *a_thread)
{
	std::cout << "A princess is in danger, do you wish to save her?" << std::endl << "[Accept | Decline]" << std::endl;
	return GM_OK;
}

void HandleUserAcceptQuest(gmMachine &gm, int threadid, QuestDialog response)
{
	// Fire signal to thread to indicate user's choice	
	gm.Signal( gmVariable( (int)response ), threadid, 0 );
}

int main(int argc, char* argv[])
{
	// Create gm virtual machine
	gmMachine	gm;
	// Bind ShowQuestDialog function to script
	gm.GetGlobals()->Set( &gm, "ShowQuestDialog", gmVariable(gm.AllocFunctionObject( gmShowQuestDialog )) );
	// Create a global table to hold Ids for QuestAccept/Decline
	gmTableObject *dialogResponses = gm.AllocTableObject();
	dialogResponses->Set( &gm, "Accept", gmVariable(QD_ACCEPT) );	// Accept = 0
	dialogResponses->Set( &gm, "Decline", gmVariable(QD_DECLINE) );	// Decline = 0
	gm.GetGlobals()->Set( &gm, "QuestDialog", gmVariable( dialogResponses ) );
	// Run an example script that calls dialog and blocks on response
	const char *script = "ShowQuestDialog(); \n"
			"response = block( QuestDialog.Accept, QuestDialog.Decline ); \n"
			"if (response == QuestDialog.Accept) { print(\"[Quest accepted]\"); } else { print(\"[Quest declined]\"); }";
	int threadid = 0;
	// Run script and capture thread it's running on
	gm.ExecuteString( script, &threadid );
	Sleep(5000);	// Wait for 5 seconds to simulate user deciding to accept
	HandleUserAcceptQuest(gm, threadid, QD_ACCEPT);
	// Tick the machine along
	gm.Execute(0);
	return 0;
}

