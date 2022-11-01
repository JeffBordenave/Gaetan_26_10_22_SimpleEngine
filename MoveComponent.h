#pragma once
#include "Component.h"
#include "Vector2.h"

class MoveComponent : public Component
{
public:
	MoveComponent(Actor* ownerP, int updateOrder = 10); // By default, update before other components
	MoveComponent() = delete;
	MoveComponent(const MoveComponent&) = delete;
	MoveComponent& operator=(const MoveComponent&) = delete;

	float getForwardSpeed() const { return forwardSpeed; }
	float getAngularSpeed() const { return angularSpeed; }
	float getMass() const { return mass; }
	Vector2 getForce() const { return force; }
	bool getIsActive() const { return isActive; }

	void setForwardSpeed(float forwardSpeedP);
	void setAngularSpeed(float angularSpeedP);
	void setMass(float massP);
	void setForce(float forceP);
	void setVelocity(Vector2 velocityP);

	void update(float dt) override;
	void activate();
	void deactivate();


private:
	float forwardSpeed;
	float angularSpeed;
	bool isActive;

	float mass;
	Vector2 force;
	Vector2 acceleration;
	Vector2 velocity;

};
