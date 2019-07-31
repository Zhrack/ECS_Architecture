#ifndef TRANSFORM_COMPONENT_H_
#define TRANSFORM_COMPONENT_H_

#include "ComponentDefs.h"

#include <SFML/Graphics.hpp>

/// <summary>
/// Encapsulates a sf::Transform, a position, rotation and scale matrix.
/// </summary>
/// <seealso cref="sf::Transformable" />
struct TransformComponent : public sf::Transformable
{
    TransformComponent();
    ~TransformComponent();
};

using Transforms = Component<TransformComponent>;

#endif // !TRANSFORM_COMPONENT_H_
