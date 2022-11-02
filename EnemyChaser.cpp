#include "EnemyChaser.h"
#include "Maths.h"
#include <iostream>

EnemyChaser::EnemyChaser()
{
	collision = new CircleCollisionComponent(this);
	collision->setRadius(40.0f);
	SpriteComponent* sc = new SpriteComponent(this, Assets::getTexture("Ship01"));
	target = nullptr;
	/*MoveComponent* mc = new MoveComponent(this);
	mc->setForwardSpeed(0.0f);
	mc->setMass(100);
	mc->setForce(100);
	mc->setVelocity(getForward() * 0);*/
}

EnemyChaser::~EnemyChaser()
{
}

void EnemyChaser::updateActor(float dt) 
{
	Vector2 selfToTarget = target->getPosition() - getPosition();
	float angleToTarget = Maths::acos(Vector2::dot(Vector2::normalize(selfToTarget), getForward()));

	//setRotation(Maths::acos((target.length() - getPosition().length()) / getForward().x));
	//setRotation(angleToTarget);
	//std::cout << getRotation() << "\n";
	//std::cout << Vector2::dot(Vector2::normalize(selfToTarget), getForward()) << std::endl;

	float atan2 = Vector2::dot(Vector2::normalize(selfToTarget), getRight());

	if (atan2 > 0) setRotation(getRotation() + dt);
	else if (atan2 < 0) setRotation(getRotation() - dt);

	//setRotation(getRotation() + 90);
}

