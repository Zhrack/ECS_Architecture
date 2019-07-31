#include "pch.h"
#include "EntityIDPool.h"


EntityIDPool::EntityIDPool(int entityPool)
{
    // insert it backwards so that when popping values, they come in ascending order
    for (int i = entityPool - 1; i >= 0; i--)
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
    return id;
}

void EntityIDPool::freeID(EntityID id)
{
    mEntityIDPool.push(id);
}
