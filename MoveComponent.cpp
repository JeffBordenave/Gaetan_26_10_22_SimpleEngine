#include "MoveComponent.h"
#include "Maths.h"
#include "Actor.h"
#include "Window.h"

MoveComponent::MoveComponent(Actor* ownerP, int updateOrderP)
	: Component(ownerP, updateOrderP), forwardSpeed(0.0f), angularSpeed(0.0f)
{
}

void MoveComponent::setForwardSpeed(float forwardSpeedP)
{
	forwardSpeed = forwardSpeedP;
}

void MoveComponent::setAngularSpeed(float angularSpeedP)
{
	angularSpeed = angularSpeedP;
}

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

		if (newPosition.x < 0) { newPosition.x = 0; }
		else if (newPosition.x > WINDOW_WIDTH) { newPosition.x = WINDOW_WIDTH; }
		if (newPosition.y < 0) { newPosition.y = 0; }
		else if (newPosition.y > WINDOW_HEIGHT) { newPosition.y = WINDOW_HEIGHT; }

		owner.setPosition(newPosition);
	}
}