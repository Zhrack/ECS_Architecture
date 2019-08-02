#include "pch.h"
#include "Components.h"


void TransformComponent::setPosition(const sf::Vector2f& pos)
{
    std::lock_guard<std::mutex> lock(mMutex);
    mTransform.setPosition(pos);
}

void TransformComponent::setRotation(float angle)
{
    std::lock_guard<std::mutex> lock(mMutex);
    mTransform.setRotation(angle);
}

void TransformComponent::setScale(const sf::Vector2f& factors)
{
    std::lock_guard<std::mutex> lock(mMutex);
    mTransform.setScale(factors);
}

sf::Vector2f TransformComponent::getPosition()
{
    std::lock_guard<std::mutex> lock(mMutex);
    return mTransform.getPosition();
}

float TransformComponent::getRotation()
{
    std::lock_guard<std::mutex> lock(mMutex);
    return mTransform.getRotation();
}

sf::Vector2f TransformComponent::getScale()
{
    std::lock_guard<std::mutex> lock(mMutex);
    return mTransform.getScale();
}

void TransformComponent::move(const sf::Vector2f & offset)
{
    std::lock_guard<std::mutex> lock(mMutex);
    mTransform.move(offset);
}

void TransformComponent::rotate(float angle)
{
    std::lock_guard<std::mutex> lock(mMutex);
    mTransform.rotate(angle);
}

void TransformComponent::scale(const sf::Vector2f & factor)
{
    std::lock_guard<std::mutex> lock(mMutex);
    mTransform.scale(factor);
}


void VelocityComponent::setVelocity(const sf::Vector2f& vel)
{
    std::lock_guard<std::mutex> lock(mMutex);
    mVel = vel;
}

sf::Vector2f VelocityComponent::getVelocity()
{
    std::lock_guard<std::mutex> lock(mMutex);
    return mVel;
}