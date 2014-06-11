#pragma once
class BaseGameEntity
{
public:
	BaseGameEntity(int id);
	virtual ~BaseGameEntity(void);
	virtual void Update() = 0;
	int GetId() const;

private:
	int m_Id;
	static int m_nextValidId;
	void SetId(int id);
};

