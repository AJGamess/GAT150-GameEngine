#pragma once
#include "Component.h"

class CollisionComponent : public Component
{
public:
	virtual bool CheckCollision(CollisionComponent* collision) = 0;
};
