#pragma once

struct Telegram;

template<class T>
class State
{
public:
	virtual void Enter(T*) = 0;
	virtual void Execute(T*) = 0;
	virtual void Exit(T*) = 0;
	virtual bool OnMessage(T*, const Telegram&) = 0;
	virtual ~State(void) {};
};

