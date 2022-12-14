#pragma once
#include <SDL_stdinc.h>

class Actor;

class Component
{
public:
	Component(Actor* ownerP, int updateOrderP = 100);
	Component() = delete;
	virtual ~Component();
	Component(const Component&) = delete;
	Component& operator=(const Component&) = delete;

	int getUpdateOrder() const { return updateOrder; }
	bool getActive() const { return isActive; }

	void setActive(bool isActiveP);
	virtual void processInput(const Uint8* keyState);
	virtual void update(float dt);

protected:
	Actor& owner;
	int updateOrder;
	bool isActive;
};
