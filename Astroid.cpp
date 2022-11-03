#include "Astroid.h"
#include "Random.h"
#include "Window.h"
#include "Maths.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Assets.h"
#include "Game.h"

Astroid::Astroid() : Actor(), collision(nullptr)
{
	Vector2 randPos = Random::getVector(Vector2(WINDOW_WIDTH - 100, 0), Vector2(WINDOW_WIDTH, WINDOW_HEIGHT));
	setPosition(randPos);

	setRotation(Maths::toRadians(180));

	SpriteComponent* sc = new SpriteComponent(this, Assets::getTexture("Astroid"));
	MoveComponent* mc = new MoveComponent(this);
	mc->setForwardSpeed(200.0f);

	collision = new CircleCollisionComponent(this);
	collision->setRadius(40.0f);

	getGame().addAstroid(this);
}

Astroid::~Astroid()
{
	getGame().removeAstroid(this);
}

void Astroid::updateActor(float dt)
{
	if (getPosition().x < 10) setState(ActorState::Dead);
}