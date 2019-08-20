#ifndef COMPONENT_LIST_H_
#define COMPONENT_LIST_H_

#include "BaseComponent.h"

#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"

/// <summary>
/// A wrapper for a Box2D body.
/// </summary>
struct PhysicsComponent : public BaseComponent
{
    PhysicsComponent() {};
    PhysicsComponent(b2World* bWorld, b2BodyType type, const b2Vec2& position, float rotation);

    virtual ~PhysicsComponent();

    b2Body* getBody() const { return mBody; };

private:
    b2Body* mBody;
    b2World* bWorld;
};

/// <summary>
/// Encapsulates a sf::Sprite.
/// </summary>
struct RenderComponent : public BaseComponent, sf::Drawable
{
    RenderComponent() {}
    virtual ~RenderComponent() {}

    // TODO expose sf::Sprite methods as needed
    void setPosition(const sf::Vector2f& pos);
    void setRotation(float angle);
    void setScale(const sf::Vector2f& factors);

    sf::Vector2f    getPosition();
    float           getRotation();
    sf::Vector2f    getScale();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Sprite  mSprite;
};

/// <summary>
/// A component that tags entities under player control.
/// </summary>
struct PlayerInputComponent : public BaseComponent
{
    PlayerInputComponent() {}
    virtual ~PlayerInputComponent() {}
};

#endif // !COMPONENT_LIST_H_
