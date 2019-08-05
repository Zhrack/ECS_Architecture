#include "pch.h"
#include "RenderProcessor.h"

#include "EntityManager.h"
#include "Components.h"

#include "Events.h"


RenderProcessor::RenderProcessor(EntityManager* manager, sf::RenderWindow* win) :
    BaseProcessor(manager, {
        CompType::COMP_TRANSFORM,
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
        auto transform = e.getAs<TransformComponent>(CompType::COMP_TRANSFORM);
        auto render = e.getAs<RenderComponent>(CompType::COMP_RENDER);

        // update sprite transform
        render->setPosition(transform->getPosition());
        render->setRotation(transform->getRotation());
        render->setScale(transform->getScale());

        // render it
        mWindow->draw(*render);
    }

    mWindow->display();
}

void RenderProcessor::onNotify(const Event & event)
{
    // first check standard events
    BaseProcessor::onNotify(event);

    // not check the rest

}