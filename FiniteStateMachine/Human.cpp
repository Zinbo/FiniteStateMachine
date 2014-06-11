#include "stdafx.h"
#include "Human.h"


bool Human::HandleMessage(const Telegram& msg)
{
  return m_pStateMachine->HandleMessage(msg);
}


void Human::Update()
{ 
  m_pStateMachine->Update();
}

bool Human::Hungry() const
{
	if(GetHunger() > hungerThreshold)
	{
		return true;
	}
	return false;
}

bool Human::Tired() const
{
	if(GetTiredness() > fatigueThreshold)
	{
		return true;
	}
	return false;
}

void Human::IncreaseTiredness()
{
	m_Tiredness++;
}

void Human::IncreaseHunger()
{
	m_Hunger++;
}

void Human::Sleep()
{
	m_Tiredness -= 2;
	if(m_Tiredness < 0)
	{
		m_Tiredness = 0;
	}
}

void Human::Eat()
{
	m_Hunger -= 2;
	m_AmountOfFood -= 1;
	if(m_Hunger < 0)
	{
		m_Hunger = 0;
	}
}

int Human::GetAmountOfFood()
{
	return m_AmountOfFood;
}

bool Human::FoodStashFull()
{
	return (maxFoodStash == GetAmountOfFood());
}

bool Human::FoodStashEmpty()
{
	return (maxFoodStash == 0);
}

void Human::IncreaseFoodStash()
{
	m_AmountOfFood += 2;
	if(m_AmountOfFood > maxFoodStash)
	{
		m_AmountOfFood = maxFoodStash;
	}
}