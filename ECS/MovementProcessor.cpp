#include "pch.h"
#include "MovementProcessor.h"

#include "Components.h"

MovementProcessor::MovementProcessor(EntityManager* manager) :
    BaseProcessor(manager, {
        COMP_TRANSFORM,
        COMP_VELOCITY
        })
{
}


MovementProcessor::~MovementProcessor()
{
}

void MovementProcessor::update(float elapsed)
{
    for (auto& e : mCurrentDeps)
    {
        auto transform = e.getAs<TransformComponent>(CompType::COMP_TRANSFORM);
        auto velocity = e.getAs<VelocityComponent>(CompType::COMP_VELOCITY);

        transform->move(velocity->getVelocity());
    }
}
