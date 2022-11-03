#pragma once
#include "Actor.h"
#include "CircleCollisionComponent.h"

class Astroid : public Actor
{
public:
	Astroid();
	~Astroid();

	CircleCollisionComponent& getCollision() { return *collision; }

	void updateActor(float dt);

private:
	CircleCollisionComponent* collision;
};
