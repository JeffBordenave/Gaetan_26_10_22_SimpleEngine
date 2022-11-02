#include "Ship.h"
#include "Assets.h"
#include "Maths.h"
#include "Laser.h"
#include "Game.h"

Ship::Ship() : Actor()
{
	laserCooldown = 0.0f;
	deathCounter = 0.0f;
	deathCooldown = 1.0f;

	sc = new SpriteComponent(this, Assets::getTexture("Ship"));
	ic = new InputComponent(this);
	ic->setMaxForwardSpeed(300.0f);
	ic->setMaxAngularSpeed(Maths::twoPi);
	/*ic->setMass(100);
	ic->setForce(1000);*/
	collision = new CircleCollisionComponent(this);
	collision->setRadius(20.0f);
	setRotation(Maths::toRadians(90));
}

void Ship::actorInput(const Uint8* keyState)
{
	if (keyState[SDL_SCANCODE_SPACE] && laserCooldown <= 0.0f && ic->getActive())
	{
		Laser* laser = new Laser();
		laser->setPosition(getPosition());
		laser->setRotation(getRotation() - Maths::toRadians(90));
		laserCooldown = 0.2f;
	}
}

void Ship::updateActor(float dt)
{
	laserCooldown -= dt;
	auto astroids = getGame().getAstroids();
	for (auto astroid : astroids)
	{
		if (Intersect(*collision, astroid->getCollision()))
		{
			isHit = true;
			ic->setActive(false);
			sc->setActive(false);
			break;
		}
	}

	deathCD(dt);
}

void Ship::deathCD(float dt)
{
	if (isHit == true)
	{
		deathCounter += dt;
		if (deathCounter >= deathCooldown) 
		{
			ic->setActive(true);
			sc->setActive(true);
			isHit = false;
			setPosition(Vector2(100, 100));
			setRotation(0);
			//ic->setVelocity(Vector2::zero);
			deathCounter = 0;
		}
	}
}
