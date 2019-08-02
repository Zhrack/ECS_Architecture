#ifndef COMPONENT_LIST_H_
#define COMPONENT_LIST_H_

#include "BaseComponent.h"

#include <SFML/Graphics.hpp>

/// <summary>
/// Encapsulates a sf::Transform, a position, rotation and scale matrix.
/// </summary>
struct TransformComponent : public BaseComponent
{
    TransformComponent() {}
    virtual ~TransformComponent() {}

    void setPosition(const sf::Vector2f& pos);
    void setRotation(float angle);
    void setScale(const sf::Vector2f& factors);

    sf::Vector2f    getPosition();
    float           getRotation();
    sf::Vector2f    getScale();

    void move(const sf::Vector2f& offset);
    void rotate(float angle);
    void scale(const sf::Vector2f& factor);

private:
    sf::Transformable   mTransform;
};

/// <summary>
/// The velocity vector.
/// </summary>
struct VelocityComponent : public BaseComponent
{
    VelocityComponent() {}
    VelocityComponent(sf::Vector2f vec) : mVel(vec) {}

    virtual ~VelocityComponent() {}

    void setVelocity(const sf::Vector2f& vel);

    sf::Vector2f getVelocity();

private:
    sf::Vector2f    mVel;
};

/// <summary>
/// Encapsulates a sf::Sprite.
/// </summary>
struct RenderComponent : public BaseComponent
{

    RenderComponent() {}
    virtual ~RenderComponent() {}

    // TODO expose sf::Sprite methods as needed

private:
    sf::Sprite  mSprite;
};

/// <summary>
/// An empty component that tags entities under player control.
/// </summary>
struct PlayerInputComponent : public BaseComponent
{
    PlayerInputComponent() {}
    virtual ~PlayerInputComponent() {}
};

#endif // !COMPONENT_LIST_H_
