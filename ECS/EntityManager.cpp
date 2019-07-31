#include "pch.h"
#include "EntityManager.h"


EntityManager::EntityManager(unsigned long entityPool):
    mComponents(CompType::COMP_COUNT),
    mEntityIDPool(entityPool),
    mMaxEntities(entityPool)
{
    // register types
    for (size_t i = 0; i < CompType::COMP_COUNT; ++i)
    {
        mComponents[i].resize(entityPool);
    }
}


EntityManager::~EntityManager()
{
}

std::vector<EntityID> EntityManager::intersection(const std::vector<CompType>& deps)
{
    std::vector<EntityID> result;
    std::uint32_t counter = 0;
    auto depsSize = deps.size();

    // simple implementation for now, also deps size will be < 10 most of the time, pratically O(n)
    for (EntityID id = 0; id < mMaxEntities; id++)
    {
        counter = 0;

        for (size_t i = 0; i < CompType::COMP_COUNT; ++i)
        {
            if (mComponents[deps[i]][id] != nullptr)
            {
                counter++;
            }
        }

        if (counter == depsSize)
        {
            result.push_back(id);
        }
    }

    return result;
}
