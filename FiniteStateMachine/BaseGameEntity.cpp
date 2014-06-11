#include "stdafx.h"
#include "BaseGameEntity.h"


BaseGameEntity::BaseGameEntity(int id)
{
	SetId(id);
}

BaseGameEntity::~BaseGameEntity(void)
{
}

int BaseGameEntity::GetId() const
{
	return m_Id;
}
