#pragma once
#include "State.h"

template <class T>
class StateMachine 
{
public:
	StateMachine(T* owner)
		:m_pOwner(owner), m_pCurrentState(NULL), m_pPreviousState(NULL), m_pGlobalState(NULL)
	{};
	
	~StateMachine(void);

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
			m_pCurrentState->Execute(m_pCurrentState);
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

	bool IsInState(const State<T>& state) const=
private:
	T* m_pOwner;
	State<T>* m_pCurrentState;
	State<T>* m_pPreviousState;
	State<T>* m_pGlobalState;

};

