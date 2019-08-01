#include "pch.h"
#include "EntityManager.h"


EntityManager::EntityManager(unsigned long entityPool, sf::RenderWindow* win):
    mComponents(CompType::COMP_COUNT),
    mEntityIDPool(entityPool),
    mMaxEntities(entityPool),
    mRenderProcessor(this, win),
    mRenderWindow(win)
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

std::vector<Dependency> EntityManager::intersection(const std::vector<CompType>& deps)
{
    std::vector<Dependency> result;
    std::uint32_t counter = 0;
    auto depsSize = deps.size();

    // simple implementation for now, also deps size will be < 10 most of the time, pratically O(n)
    ;

    for (auto entIDIter = mEntityIDPool.getUsedIDsIter();
        entIDIter != mEntityIDPool.endUsedIDsIter();
        entIDIter++)
    {
        std::unordered_map<CompType, BaseComponent*> comps;
        counter = 0;

        for (size_t i = 0; i < CompType::COMP_COUNT; ++i)
        {
            auto& c = mComponents[deps[i]][*entIDIter];
            if (c != nullptr)
            {
                comps[(CompType)i] = c.get();
                counter++;
            }
        }

        if (counter == depsSize)
        {
            result.emplace_back(*entIDIter, comps);
        }
    }

    return result;
}
