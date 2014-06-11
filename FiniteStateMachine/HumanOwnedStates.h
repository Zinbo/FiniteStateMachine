#pragma once

#include "State.h"

class Human;
struct Telegram;

class Walk : public State<Human>
{
public:
	static Walk* Instance();

	virtual void Enter(Human* human);

	virtual void Execute(Human* human);

	virtual void Exit(Human* human);

	virtual bool OnMessage(Human* agent, const Telegram& msg);

private:
	Walk() {};
	Walk(const Walk&);
	Walk& operator=(const Walk&);
};

class Sleep : public State<Human>
{
	public:
	static Sleep* Instance();

	virtual void Enter(Human* human);

	virtual void Execute(Human* human);

	virtual void Exit(Human* human);

	virtual bool OnMessage(Human* agent, const Telegram& msg);

private:
	Sleep() {};
	Sleep(const Sleep&);
	Sleep& operator=(const Sleep&);
};

class Eat : public State<Human>
{
	public:
	static Eat* Instance();

	virtual void Enter(Human* human);

	virtual void Execute(Human* human);

	virtual void Exit(Human* human);

	virtual bool OnMessage(Human* agent, const Telegram& msg);

private:
	Eat() {};
	Eat(const Eat&);
	Eat& operator=(const Eat&);
};

class LookForFood : public State<Human>
{
	public:
	static LookForFood* Instance();

	virtual void Enter(Human* human);

	virtual void Execute(Human* human);

	virtual void Exit(Human* human);

	virtual bool OnMessage(Human* agent, const Telegram& msg);

private:
	LookForFood() {};
	LookForFood(const LookForFood&);
	LookForFood& operator=(const LookForFood&);
};

/*
class Flee : public State<Human>
{
	public:
	static Flee* Instance();

	virtual void Enter(Human* human);

	virtual void Execute(Human* human);

	virtual void Exit(Human* human);

	virtual bool OnMessage(Human* agent, const Telegram& msg);

private:
	Flee() {};
	Flee(const Flee&);
	Flee& operator=(const Flee&);
};

class Attack : public State<Human>
{
	public:
	static Attack* Instance();

	virtual void Enter(Human* human);

	virtual void Execute(Human* human);

	virtual void Exit(Human* human);

	virtual bool OnMessage(Human* agent, const Telegram& msg);

private:
	Attack() {};
	Attack(const Attack&);
	Attack& operator=(const Attack&);
};

class Persue : public State<Human>
{
	public:
	static Persue* Instance();

	virtual void Enter(Human* human);

	virtual void Execute(Human* human);

	virtual void Exit(Human* human);

	virtual bool OnMessage(Human* agent, const Telegram& msg);

private:
	Persue() {};
	Persue(const Persue&);
	Persue& operator=(const Persue&);
};
*/