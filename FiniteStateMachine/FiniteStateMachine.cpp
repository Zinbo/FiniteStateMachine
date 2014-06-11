// FiniteStateMachine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <time.h>
#include "Human.h"
#include "EntityManager.h"
#include "MessageDispatcher.h"
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned) time(NULL));
	Human* human = new Human(1);

	EntityMgr->RegisterEntity(human);

	for (int i=0; i<30; ++i)
	{ 
		human->Update();

		//dispatch any delayed messages
		Dispatcher->DispatchDelayedMessages();

		Sleep(800);
	}
	system("pause");
	return 0;
}

