#pragma once
#include "Actor.h"
#include <SDL_stdinc.h>
#include "CircleCollisionComponent.h"
#include "InputComponent.h"
#include "SpriteComponent.h"

class Ship : public Actor
{
public:
	Ship();

	void actorInput(const Uint8* keyState) override;
	void updateActor(float dt) override;
	void deathCD(float dt);

	CircleCollisionComponent& getCollision() { return *collision; }

private:
	CircleCollisionComponent* collision;
	InputComponent* ic;
	SpriteComponent* sc;
	float laserCooldown;
	float deathCooldown;
	float deathCounter;
	bool isHit = false;
};
