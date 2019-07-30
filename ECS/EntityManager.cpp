#include "pch.h"
#include "EntityManager.h"


EntityManager::EntityManager(int entityPool):
    mComponents(entityPool),
    mEntityIDPool()
{
    for (int i = entityPool - 1; i >= 0; i--)
    {
        mEntityIDPool.push(i);
    }
}


EntityManager::~EntityManager()
{
}
