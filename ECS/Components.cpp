#include "pch.h"
#include "Components.h"

#define LOCK std::lock_guard<std::mutex> lock(mMutex)

void TransformComponent::setPosition(const sf::Vector2f& pos)
{
    LOCK;
    mTransform.setPosition(pos);
}

void TransformComponent::setRotation(float angle)
{
    LOCK;
    mTransform.setRotation(angle);
}

void TransformComponent::setScale(const sf::Vector2f& factors)
{
    LOCK;
    mTransform.setScale(factors);
}

sf::Vector2f TransformComponent::getPosition()
{
    LOCK;
    return mTransform.getPosition();
}

float TransformComponent::getRotation()
{
    LOCK;
    return mTransform.getRotation();
}

sf::Vector2f TransformComponent::getScale()
{
    LOCK;
    return mTransform.getScale();
}

void TransformComponent::move(const sf::Vector2f & offset)
{
    LOCK;
    mTransform.move(offset);
}

void TransformComponent::rotate(float angle)
{
    LOCK;
    mTransform.rotate(angle);
}

void TransformComponent::scale(const sf::Vector2f & factor)
{
    LOCK;
    mTransform.scale(factor);
}


void VelocityComponent::setVelocity(const sf::Vector2f& vel)
{
    LOCK;
    mVel = vel;
}

sf::Vector2f VelocityComponent::getVelocity()
{
    LOCK;
    return mVel;
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
