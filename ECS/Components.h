#ifndef COMPONENT_LIST_H_
#define COMPONENT_LIST_H_

#include "BaseComponent.h"

#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"

#include <functional>
#include <vector>

/// <summary>
/// A wrapper for a Box2D body.
/// </summary>
struct PhysicsComponent : public BaseComponent
{
    using beginContactCallbackType = std::function<void(b2Contact*, PhysicsComponent*)>;
    using endContactCallbackType = std::function<void(b2Contact*, PhysicsComponent*)>;

    PhysicsComponent(EntityID id) : BaseComponent(id) {}
    PhysicsComponent(EntityID id, b2World* bWorld, b2BodyType type, const b2Vec2& position, float rotation);

    virtual ~PhysicsComponent();

    b2Body* getBody() const { return mBody; };

    void addBeginContactListener(beginContactCallbackType func);
    void removeBeginContactListener(beginContactCallbackType func);

    void addEndContactListener(endContactCallbackType func);
    void removeEndContactListener(endContactCallbackType func);

    /// <summary>
    /// Call all begin callbacks after a begin contact event.
    /// </summary>
    void beginCallbacks(b2Contact* contact, PhysicsComponent* other);
    /// <summary>
    /// Call all end callbacks after a end contact event.
    /// </summary>
    void endCallbacks(b2Contact* contact, PhysicsComponent* other);

private:
    b2Body* mBody;

    /// <summary>
    /// It stores the callbacks for every other processor who needs collision logic
    /// TODO choose arguments
    /// Probably needs a unordered_map to use processor names or IDs as keys.
    /// </summary>
    std::vector<beginContactCallbackType>   mBeginContactCallbacks;

    std::vector<endContactCallbackType>   mEndContactCallbacks;
};

/// <summary>
/// Encapsulates a sf::Sprite.
/// </summary>
struct RenderComponent : public BaseComponent, sf::Drawable
{
    RenderComponent(EntityID id);
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
    PlayerInputComponent(EntityID id);
    virtual ~PlayerInputComponent() {}
};

#endif // !COMPONENT_LIST_H_
