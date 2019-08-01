#include "pch.h"
#include "RenderProcessor.h"

#include "EntityManager.h"
#include "TransformComponent.h"
#include "RenderComponent.h"


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
        render->mSprite.setPosition(transform->getPosition());
        render->mSprite.setRotation(transform->getRotation());
        render->mSprite.setScale(transform->getScale());

        // render it
        mWindow->draw(render->mSprite);
    }

    mWindow->display();
}
