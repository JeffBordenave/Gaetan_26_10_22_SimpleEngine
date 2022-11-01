#include "SpriteComponent.h"
#include "Actor.h"
#include "Game.h"

SpriteComponent::SpriteComponent(Actor* ownerP, Texture& textureP, int drawOrderP) :
	Component(ownerP),
	texture(textureP),
	drawOrder(drawOrderP),
	texWidth(textureP.getWidth()),
	texHeight(textureP.getHeight())
{
	owner.getGame().getRenderer().addSprite(this);
	visible = true;
}

SpriteComponent::~SpriteComponent()
{
	owner.getGame().getRenderer().removeSprite(this);
}

void SpriteComponent::setTexture(const Texture& textureP)
{
	texture = textureP;
	texture.updateInfo(texWidth, texHeight);
}

void SpriteComponent::draw(Renderer& renderer)
{
	if (visible == false) 
		return;

	Vector2 origin{ texWidth / 2.f, texHeight / 2.f };
	renderer.drawSprite(owner, texture, Rectangle::nullRect, origin, Renderer::Flip::None);
}
