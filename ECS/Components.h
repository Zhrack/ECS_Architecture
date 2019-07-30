#ifndef COMPONENTS_H_
#define COMPONENTS_H_

#include "TransformComponent.h"
#include "VelocityComponent.h"

struct Components
{
    Transforms mTransforms;
    Velocities mVelocities;


    Components(int numEntities) :
        mTransforms(numEntities, nullptr),
        mVelocities(numEntities, nullptr)
    {}

    Components() = delete;
    Components(Components&) = delete;
    Components(Components&&) = delete;
};

#endif // !COMPONENTS_H_
