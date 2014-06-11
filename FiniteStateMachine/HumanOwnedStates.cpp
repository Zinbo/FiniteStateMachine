#include "stdafx.h"
#include "HumanOwnedStates.h"
#include "Human.h"

#include <iostream>

Walk* Walk::Instance()
{
	static Walk instance;
	return &instance;
}

void Walk::Enter(Human* pHuman)
{
	std::cout << "Starting to wander..." << std::endl;
}

void Walk::Execute(Human* pHuman)
{
	pHuman->IncreaseTiredness();
	pHuman->IncreaseHunger();

	if(pHuman->Hungry())
	{
		pHuman->GetFSM()->ChangeState(LookForFood::Instance());
	}

	if(pHuman->Tired())
	{
		pHuman->GetFSM()->ChangeState(Sleep::Instance());
	}
}

void Walk::Exit(Human* pHuman)
{
	std::cout << "Human is stopping wander." << std::endl;
}

bool Walk::OnMessage(Human* pHuman, const Telegram& msg)
{
	return false;
}

//***********************************************************************************************

Sleep* Sleep::Instance()
{
	static Sleep instance;
	return & instance;
}

void Sleep::Enter(Human* pHuman)
{
	std::cout << "Entering the sleep state..." << std::endl;
}

void Sleep::Execute(Human* pHuman)
{
	std::cout << "ZZZ..." << std::endl;
	pHuman->Sleep();
	if(pHuman->GetTiredness() == 0)
	{
		pHuman->GetFSM()->ChangeState(Walk::Instance());
	}
}

void Sleep::Exit(Human* pHuman)
{
	std::cout << "Waking up now" << std::endl;
}

bool Sleep::OnMessage(Human * pHuman, const Telegram& msg)
{
	return false;
}

//***********************************************************************************************

Eat* Eat::Instance()
{
	static Eat instance;
	return & instance;
}

void Eat::Enter(Human* pHuman)
{
	std::cout << "Entering the Eat state..." << std::endl;
}

void Eat::Execute(Human* pHuman)
{
	std::cout << "Om nom nom" << std::endl;
	pHuman->Eat();

	if(pHuman->GetHunger() == 0)
	{
		pHuman->GetFSM()->ChangeState(Walk::Instance());
	}

	if(pHuman->FoodStashEmpty())
	{
		pHuman->GetFSM()->ChangeState(LookForFood::Instance());
	}

}

void Eat::Exit(Human* pHuman)
{
	std::cout << "Stopping eating" << std::endl;
}

bool Eat::OnMessage(Human * pHuman, const Telegram& msg)
{
	return false;
}

//***********************************************************************************************

LookForFood* LookForFood::Instance()
{
	static LookForFood instance;
	return & instance;
}

void LookForFood::Enter(Human* pHuman)
{
	std::cout << "Entering the Looking for food state..." << std::endl;
}

void LookForFood::Execute(Human* pHuman)
{
	pHuman->IncreaseTiredness();
	pHuman->IncreaseHunger();

	std::cout << "Looking for food..." << std::endl;
	if ( rand() <= foodProb )
	{
		std::cout << "Found some food!" << std::endl;
		pHuman->IncreaseFoodStash();
		if(pHuman->FoodStashFull())
		{
			pHuman->GetFSM()->ChangeState(Walk::Instance());
		}
	}

	if(pHuman->Hungry() && !(pHuman->FoodStashEmpty()))
	{
		pHuman->GetFSM()->ChangeState(Eat::Instance());
	}

	if(pHuman->Tired())
	{
		pHuman->GetFSM()->ChangeState(Sleep::Instance());
	}

}

void LookForFood::Exit(Human* pHuman)
{
	std::cout << "Stopping looking for food" << std::endl;
}

bool LookForFood::OnMessage(Human * pHuman, const Telegram& msg)
{
	return false;
}