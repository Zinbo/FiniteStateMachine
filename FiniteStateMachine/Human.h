#pragma once
#include "BaseGameEntity.h"
#include "HumanOwnedStates.h"
#include "StateMachine.h"

template <class T> class State; //pre-fixed with "template <class entity_type> " for vs8 compatibility

struct Telegram;

const int fatigueThreshold = 5;
const int hungerThreshold = 5;

const int maxFoodStash = 5;
const float foodProb = 0.7;

class Human : public BaseGameEntity
{

public:
	
	Human(int id)
		:m_Tiredness(0),
		 m_Hunger(0),
		 BaseGameEntity(id)
	{
		m_pStateMachine = new StateMachine<Human>(this);
		m_pStateMachine->SetCurrentState(Walk::Instance());
	};


	~Human(void) { delete m_pStateMachine;};

	void Update();

	virtual bool HandleMessage(const Telegram& msg);

	StateMachine<Human>* GetFSM()const{return m_pStateMachine;}



	int GetTiredness() const { return m_Tiredness; };
	int GetHunger() const {return m_Hunger; };

	bool Hungry() const;
	bool Tired() const;

	void IncreaseTiredness();
	void IncreaseHunger();

	void Sleep();
	void Eat();

	int GetAmountOfFood();

	bool FoodStashFull();

	bool FoodStashEmpty();

	void IncreaseFoodStash();


private:
	StateMachine<Human> * m_pStateMachine;

	int m_Tiredness;
	int m_Hunger;
	int m_AmountOfFood;
};

