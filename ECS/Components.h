#ifndef COMPONENTS_H_
#define COMPONENTS_H_

#include "TransformComponent.h"
#include "VelocityComponent.h"
#include "RenderComponent.h"
#include "PlayerInputComponent.h"

struct Components
{
    Transforms              mTransforms;
    Velocities              mVelocities;
    Renderables             mRenderables;
    PlayerControllable      mPlayerControllable;


    Components(int numEntities) :
        mTransforms(numEntities),
        mVelocities(numEntities),
        mRenderables(numEntities),
        mPlayerControllable(numEntities)
    {}

    Components() = delete;
    Components(Components&) = delete;
    Components(Components&&) = delete;
};

#endif // !COMPONENTS_H_
