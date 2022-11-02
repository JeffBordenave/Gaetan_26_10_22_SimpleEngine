#include "Component.h"
#include "Actor.h"

Component::Component(Actor* ownerP, int updateOrderP) :
	owner(*ownerP),
	updateOrder(updateOrderP)
{
	owner.addComponent(this);
	isActive = true;
}

Component::~Component()
{
	owner.removeComponent(this);
}

void Component::setActive(bool isActiveP)
{
	isActive = isActiveP;
}

void Component::processInput(const Uint8* keyState)
{
}

void Component::update(float dt)
{
}