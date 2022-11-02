#pragma once
#include "Actor.h"
#include "CircleCollisionComponent.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Assets.h"
#include "Ship.h"

class EnemyChaser : public Actor
{
public:
	EnemyChaser();
	~EnemyChaser();

	void updateActor(float dt);

	CircleCollisionComponent& getCollision() { return *collision; }

	Ship* target;

private:
	CircleCollisionComponent* collision;
};

