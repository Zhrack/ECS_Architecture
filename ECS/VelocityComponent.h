#ifndef VELOCITY_COMPONENT_H_
#define VELOCITY_COMPONENT_H_

#include "ComponentDefs.h"

#include <SFML/Graphics.hpp>

/// <summary>
/// The velocity vector.
/// </summary>
struct VelocityComponent
{
    sf::Vector2f    mVel;

    VelocityComponent();
    VelocityComponent(sf::Vector2f vec);

    ~VelocityComponent();
};

using Velocities = Component<VelocityComponent>;

#endif