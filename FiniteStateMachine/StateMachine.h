#pragma once
#include "State.h"
#include <assert.h>

template <class T>
class StateMachine 
{
public:
	StateMachine(T* owner)
		:m_pOwner(owner), m_pCurrentState(NULL), m_pPreviousState(NULL), m_pGlobalState(NULL)
	{};
	
	~StateMachine(void) {};

	void SetCurrentState(State<T>* state)
	{
		m_pCurrentState = state;
	}

	void SetGlobalState(State<T>* state)
	{
		m_pGloblState = state;
	}

	void SetPreviousState(State<T>* state)
	{
		m_pPreviousState = state;
	}

	void Update() const
	{
		if(m_pGlobalState)
		{
			m_pGlobalState->Execute(m_pOwner);
		}

		if(m_pCurrentState)
		{
			m_pCurrentState->Execute(m_pOwner);
		}
	}

	void ChangeState(State<T>* pNewState)
	{
		assert(pNewState && "<StateMachine::ChangeState>: trying to change to a null state!");

		m_pPreviousState = m_pCurrentState;
		m_pCurrentState->Exit(m_pOwner);
		m_pCurrentState = pNewState;
		m_pCurrentState->Enter(m_pOwner);
	}

	bool  HandleMessage(const Telegram& msg)const
  {
    //first see if the current state is valid and that it can handle
    //the message
    if (m_pCurrentState && m_pCurrentState->OnMessage(m_pOwner, msg))
    {
      return true;
    }
  
    //if not, and if a global state has been implemented, send 
    //the message to the global state
    if (m_pGlobalState && m_pGlobalState->OnMessage(m_pOwner, msg))
    {
      return true;
    }

    return false;
  }

	void RevertToPreviousState()
	{
		ChangeState(m_pPreviousState);
	}

	State<T>* GetCurrentState() const
	{
		return m_pCurrentState;
	}

	State<T>* GetGobalState() const
	{
		return m_pGlobalState;
	}

	State<T>* GetPreviousState() const
	{
		return m_pPreviousState;
	}

	bool  isInState(const State<T>& st)const
	{
		return typeid(*m_pCurrentState) == typeid(st);
	}

private:
	T* m_pOwner;
	State<T>* m_pCurrentState;
	State<T>* m_pPreviousState;
	State<T>* m_pGlobalState;

};

