#include "EnemyChaser.h"
#include "Maths.h"
#include <iostream>
#include "Random.h"
#include "Game.h"

EnemyChaser::EnemyChaser()
{
	collision = new CircleCollisionComponent(this);
	collision->setRadius(20.0f);
	SpriteComponent* sc = new SpriteComponent(this, Assets::getTexture("Ship01"));
	target = nullptr;
	MoveComponent* mc = new MoveComponent(this);
	mc->setForwardSpeed(150);

	Vector2 randPos = Random::getVector(Vector2(WINDOW_WIDTH - 100, 0), Vector2(WINDOW_WIDTH, WINDOW_HEIGHT));
	setPosition(randPos);

	setRotation(Maths::toRadians(180));

	getGame().addEnemyChaser(this);
}

EnemyChaser::~EnemyChaser()
{
	getGame().removeEnemyChaser(this);
}

void EnemyChaser::updateActor(float dt) 
{
	Vector2 selfToTarget = target->getPosition() - getPosition();
	float angleToTarget = Vector2::dot(Vector2::normalize(selfToTarget), getRight());

	if (angleToTarget > 0) setRotation(getRotation() + dt/2);
	else if (angleToTarget < 0) setRotation(getRotation() - dt/2);

	if (Intersect(*collision, target->getCollision())) setState(ActorState::Dead);
	else if (getPosition().x <= target->getPosition().x) setState(ActorState::Dead);
}