#include "pch.h"
#include "EntityIDPool.h"


EntityIDPool::EntityIDPool(unsigned long entityPool) :
    mEntityIDPool(),
    mCurrentMax(0)
{
    // insert it backwards so that when popping values, they come in ascending order
    for (unsigned long i = entityPool - 1; i >= 0; i--)
    {
        mEntityIDPool.push(i);
    }
}


EntityIDPool::~EntityIDPool()
{
}

EntityID EntityIDPool::generateID()
{
    auto id = mEntityIDPool.top();
    mEntityIDPool.pop();
    mCurrentMax++;
    return id;
}

void EntityIDPool::freeID(EntityID id)
{
    mEntityIDPool.push(id);
}

EntityID EntityIDPool::currentMax() const
{
    return mCurrentMax;
}
