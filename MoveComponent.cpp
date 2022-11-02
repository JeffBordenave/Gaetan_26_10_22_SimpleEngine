#include "MoveComponent.h"
#include "Maths.h"
#include "Actor.h"
#include "Window.h"

MoveComponent::MoveComponent(Actor* ownerP, int updateOrderP)
	: Component(ownerP, updateOrderP), forwardSpeed(0.0f), angularSpeed(0.0f)
{
	/*mass = 0;
	force = Vector2::zero;
	acceleration = Vector2::zero;
	velocity = Vector2::zero;*/
}

void MoveComponent::setForwardSpeed(float forwardSpeedP)
{
	forwardSpeed = forwardSpeedP;
}

void MoveComponent::setAngularSpeed(float angularSpeedP)
{
	angularSpeed = angularSpeedP;
}

//void MoveComponent::setMass(float massP)
//{
//	mass = massP;
//}
//
//void MoveComponent::setForce(float forceP)
//{
//	force = forceP * owner.getForward();
//}
//
//void MoveComponent::setVelocity(Vector2 velocityP)
//{
//	velocity = velocityP;
//}

void MoveComponent::update(float dt)
{
	if (isActive == false)
		return;

	if (!Maths::nearZero(angularSpeed))
	{
		float newRotation = owner.getRotation() + angularSpeed * dt;
		owner.setRotation(newRotation);
	}

	if (!Maths::nearZero(forwardSpeed))
	{
		Vector2 newPosition = owner.getPosition() + owner.getForward() * forwardSpeed * dt;

		if (newPosition.x < 0) { newPosition.x = WINDOW_WIDTH; }
		else if (newPosition.x > WINDOW_WIDTH) { newPosition.x = 0; }
		if (newPosition.y < 0) { newPosition.y = WINDOW_HEIGHT; }
		else if (newPosition.y > WINDOW_HEIGHT) { newPosition.y = 0; }

		owner.setPosition(newPosition);
	}

	/*if (owner.getPosition().x < 0) { owner.setPosition(Vector2(WINDOW_WIDTH,owner.getPosition().y)); }
	else if (owner.getPosition().x > WINDOW_WIDTH) { owner.setPosition(Vector2(0, owner.getPosition().y)); }
	if (owner.getPosition().y < 0) { owner.setPosition(Vector2(owner.getPosition().x,WINDOW_HEIGHT)); }
	else if (owner.getPosition().y > WINDOW_HEIGHT) { owner.setPosition(Vector2(owner.getPosition().x, 0)); }*/
	
	/*owner.setPosition(owner.getPosition() + velocity);

	acceleration = Vector2(force.y / mass, force.x / mass) * -1;
	velocity += acceleration * dt;*/
}