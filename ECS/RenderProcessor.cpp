#include "pch.h"
#include "RenderProcessor.h"

#include "EntityManager.h"
#include "Components.h"

#include "Events.h"


RenderProcessor::RenderProcessor(EntityManager* manager, sf::RenderWindow* win) :
    BaseProcessor(manager, {
        CompType::COMP_PHYSICS,
        CompType::COMP_RENDER
        }),
    mWindow(win)
{
}


RenderProcessor::~RenderProcessor()
{
}

void RenderProcessor::update(float elapsed)
{
    mWindow->clear();

    for (auto& e : mCurrentDeps)
    {
        auto physics = e.getAs<PhysicsComponent>(CompType::COMP_PHYSICS);
        auto render = e.getAs<RenderComponent>(CompType::COMP_RENDER);
        b2Body* body = physics->getBody();

        b2Vec2 pos = body->GetPosition();
        float rotation = body->GetAngle();
        // update sprite transform
        render->setPosition(sf::Vector2f(pos.x, pos.y));
        render->setRotation(rotation);

        // render it
        mWindow->draw(*render);
    }

    mWindow->display();
}

void RenderProcessor::onNotify(const Event & ev)
{
    // first check standard events
    BaseProcessor::onNotify(ev);

    // not check the rest

}