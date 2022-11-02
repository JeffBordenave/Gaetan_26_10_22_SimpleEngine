#include "Laser.h"
#include "SpriteComponent.h"
#include "Assets.h"

#include "Game.h"
#include "Astroid.h"

Laser::Laser() :
	Actor(),
	deathTimer(3.0f),
	collision(nullptr)
{
	new SpriteComponent(this, Assets::getTexture("Laser"));
	mc = new MoveComponent(this);
	collision = new CircleCollisionComponent(this);
	collision->setRadius(11.0f);

	mc->setForwardSpeed(305.0f);
	/*mc->setMass(100);
	mc->setForce(0);*/
}

void Laser::updateActor(float dt)
{
	//mc->setVelocity(getForward() * 10);
	deathTimer -= dt;
	if (deathTimer <= 0.0f)
	{
		setState(Actor::ActorState::Dead);
	}
	else
	{
		auto astroids = getGame().getAstroids();
		for (auto astroid : astroids)
		{
			if (Intersect(*collision, astroid->getCollision()))
			{
				setState(ActorState::Dead);
				astroid->setState(ActorState::Dead);
				break;
			}
		}
	}
}