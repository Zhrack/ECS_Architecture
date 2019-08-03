#include "pch.h"
#include "RenderProcessor.h"

#include "EntityManager.h"
#include "Components.h"


RenderProcessor::RenderProcessor(EntityManager* manager, sf::RenderWindow* win) :
    BaseProcessor(manager, {
        CompType::COMP_TRANSFORM,
        CompType::COMP_RENDER
        }),
    mWindow(win)
{
    auto a = mEntityMngr->intersection(const_cast<std::vector<CompType>&>(mWantedTypes));
    updateIntersection(a);
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
    auto id = event.mID;

    switch (id)
    {
    case EVENT_COUNT:
    default:
        break;
    }
}
