#ifndef VELOCITY_COMPONENT_H_
#define VELOCITY_COMPONENT_H_

#include "ComponentDefs.h"
#include "BaseComponent.h"

#include <SFML/Graphics.hpp>

/// <summary>
/// The velocity vector.
/// </summary>
struct VelocityComponent : public BaseComponent
{
    sf::Vector2f    mVel;

    VelocityComponent();
    VelocityComponent(sf::Vector2f vec);

    virtual ~VelocityComponent();
};

#endif