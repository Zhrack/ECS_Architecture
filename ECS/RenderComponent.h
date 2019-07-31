#ifndef RENDER_COMPONENT_H_
#define RENDER_COMPONENT_H_

#include <SFML/Graphics.hpp>

#include "ComponentDefs.h"
#include "BaseComponent.h"

/// <summary>
/// Encapsulates a sf::Sprite.
/// </summary>
struct RenderComponent : public BaseComponent
{
    sf::Sprite  mSprite;

    RenderComponent();
    ~RenderComponent();
};

#endif // !RENDER_COMPONENT_H_
