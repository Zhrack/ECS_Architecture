#include "pch.h"
#include "EntityManager.h"

#include <cassert>


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

void EntityManager::update(float elapsed)
{
    mRenderProcessor.update(elapsed);
}

std::vector<Dependency> EntityManager::intersection(const std::vector<CompType>& deps)
{
    std::vector<Dependency> result;
    std::uint32_t counter = 0;
    auto depsSize = deps.size();

    // simple implementation for now, also deps size will be < 10 most of the time, pratically O(n)
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

EntityID EntityManager::createEntity()
{
    auto id = mEntityIDPool.generateID();

    // TODO notify processors

    return id;
}

EntityID EntityManager::createEntity(const std::vector<CompType>& deps)
{
    auto id = createEntity();

    // TODO add components and notify processors of new components

    return id;
}

void EntityManager::removeEntity(EntityID id)
{
    mEntityIDPool.freeID(id);

    // TODO notify processors
}

void EntityManager::removeComponent(CompType type, EntityID id)
{
    if (mComponents[type][id] == nullptr)
    {
        std::cout << "Component could not be removed, already nullptr!" << std::endl;
        return;
    }

    mComponents[type][id].reset(nullptr);

    // TODO notify processors of component

}

std::vector<std::pair<CompType, BaseComponent*>> EntityManager::getComponents(EntityID id)
{
    std::vector<std::pair<CompType, BaseComponent*>> result;

    for (int t = 0; t < CompType::COMP_COUNT; ++t)
    {
        auto p = std::make_pair((CompType)t, mComponents[t][id].get());
        result.push_back(p);
    }

    return result;
}


