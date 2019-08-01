#include "pch.h"
#include "EntityIDPool.h"

#include <algorithm>


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
    mUsedIDs.emplace(id);
    return id;
}

void EntityIDPool::freeID(EntityID id)
{
    mEntityIDPool.push(id);

    mUsedIDs.erase(id);
}

EntityID EntityIDPool::currentMax() const
{
    return mCurrentMax;
}

std::set<EntityID>::iterator EntityIDPool::getUsedIDsIter()
{
    return mUsedIDs.begin();
}

std::set<EntityID>::iterator EntityIDPool::endUsedIDsIter()
{
    return mUsedIDs.end();
}
