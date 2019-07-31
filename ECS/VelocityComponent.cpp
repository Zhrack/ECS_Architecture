#include "pch.h"
#include "VelocityComponent.h"


VelocityComponent::VelocityComponent() :
    mVel()
{
}

VelocityComponent::VelocityComponent(sf::Vector2f vec) :
    mVel(vec)
{
}


VelocityComponent::~VelocityComponent()
{
}
