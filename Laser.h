#pragma once
#include "Actor.h"
#include "MoveComponent.h"
#include "CircleCollisionComponent.h"

class Laser : public Actor
{
public:
	Laser();

	void updateActor(float dt) override;

private:
	CircleCollisionComponent* collision;
	float deathTimer;
	MoveComponent* mc;
};
