#ifndef RENDER_COMPONENT_H_
#define RENDER_COMPONENT_H_

#include <SFML/Graphics.hpp>

/// <summary>
/// Encapsulates a sf::Sprite.
/// </summary>
struct RenderComponent
{
    sf::Sprite  mSprite;

    RenderComponent();
    ~RenderComponent();
};

using Renderables = Component<RenderComponent>;

#endif // !RENDER_COMPONENT_H_
