#include "pch.h"
#include "Components.h"

#define LOCK std::lock_guard<std::mutex> lock(mMutex)

PhysicsComponent::PhysicsComponent(EntityID id, b2World* world, b2BodyType type, const b2Vec2& position, float rotation) :
    BaseComponent(id),
    mBody(nullptr)
{
    b2BodyDef bodyDef;
    bodyDef.type = type;
    bodyDef.position = position;
    bodyDef.angle = rotation;
    bodyDef.userData = this;

    mBody = world->CreateBody(&bodyDef);
}

PhysicsComponent::~PhysicsComponent()
{
    mBody->GetWorld()->DestroyBody(mBody);
}

void PhysicsComponent::beginCallbacks(PhysicsComponent * other)
{
    for (auto cb : mBeginContactCallbacks) 
    {
        cb(other);
    }
}

void PhysicsComponent::endCallbacks(PhysicsComponent * other)
{
    for (auto cb : mEndContactCallbacks)
    {
        cb(other);
    }
}

RenderComponent::RenderComponent(EntityID id) :
    BaseComponent(id)
{
}

void RenderComponent::setPosition(const sf::Vector2f & pos)
{
    LOCK;
    mSprite.setPosition(pos);
}

void RenderComponent::setRotation(float angle)
{
    LOCK;
    mSprite.setRotation(angle);
}

void RenderComponent::setScale(const sf::Vector2f & factors)
{
    LOCK;
    mSprite.setScale(factors);
}

sf::Vector2f RenderComponent::getPosition()
{
    LOCK;
    return mSprite.getPosition();
}

float RenderComponent::getRotation()
{
    LOCK;
    return mSprite.getRotation();
}

sf::Vector2f RenderComponent::getScale()
{
    LOCK;
    return mSprite.getScale();
}

void RenderComponent::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}

PlayerInputComponent::PlayerInputComponent(EntityID id) :
    BaseComponent(id)
{
}
