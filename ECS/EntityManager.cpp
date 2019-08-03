#include "pch.h"
#include "EntityManager.h"

#include <cassert>

#include "RenderProcessor.h"


EntityManager::EntityManager(unsigned long entityPool, sf::RenderWindow* win):
    mComponents(CompType::COMP_COUNT),
    mEntityIDPool(entityPool),
    mMaxEntities(entityPool),
    mRenderWindow(win)
{
    // register types
    for (size_t i = 0; i < CompType::COMP_COUNT; ++i)
    {
        mComponents[i].resize(entityPool);
    }

    // initialize processors
    mProcessors.emplace_back(new RenderProcessor(this, mRenderWindow));
}


EntityManager::~EntityManager()
{
}

void EntityManager::update(float elapsed)
{
    for (auto it = mProcessors.begin(); it != mProcessors.end(); it++)
    {
        (*it)->updateProcessor(elapsed);
    }
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
    return mEntityIDPool.generateID();
}

EntityID EntityManager::createEntity(const std::vector<CompType>& deps)
{
    auto id = createEntity();

    EntityComponentList comps;

    for (auto dep : deps)
    {
        auto comp = addComponent(dep, id, false);
        comps.emplace_back(dep, comp);
    }

    Event e;
    e.mID = EventID::EVENT_NEW_ENTITY;
    e.newEntityData.id = id;
    e.newEntityData.comps.swap(comps);

    notifyProcessors(e);

    return id;
}

void EntityManager::removeEntity(EntityID id)
{
    mEntityIDPool.freeID(id);

    // TODO notify processors
    Event e;
    e.mID = EventID::EVENT_REMOVE_ENTITY;
    e.removeEntityData.id = id;

    notifyProcessors(e);
}

BaseComponent* EntityManager::addComponent(CompType type, EntityID id, bool notify)
{
    if (mComponents[type][id] != nullptr)
    {
        std::cout << "Component already present!" << std::endl;
        return mComponents[type][id].get();
    }

    mComponents[type][id].reset(getFromType(type));

    if (!notify) return mComponents[type][id].get();

    // notify processors of new component
    Event e;
    e.mID = EventID::EVENT_NEW_COMPONENT;
    e.newCompData.id = id;
    e.newCompData.type = type;
    e.newCompData.comp = mComponents[type][id].get();

    notifyProcessors(e);

    return mComponents[type][id].get();
}

void EntityManager::removeComponent(CompType type, EntityID id)
{
    if (mComponents[type][id] == nullptr)
    {
        std::cout << "Component could not be removed, already nullptr!" << std::endl;
        return;
    }

    mComponents[type][id].reset(nullptr);

    // notify processors of new component
    Event e;
    e.mID = EventID::EVENT_REMOVE_COMPONENT;
    e.removeCompData.id = id;
    e.removeCompData.type = type;

    notifyProcessors(e);
}

EntityComponentList EntityManager::getComponents(EntityID id)
{
    EntityComponentList result;

    for (int t = 0; t < CompType::COMP_COUNT; ++t)
    {
        auto p = std::make_pair((CompType)t, mComponents[t][id].get());
        result.push_back(p);
    }

    return result;
}

void EntityManager::notifyProcessors(const Event & ev)
{
    for (auto& p : mProcessors)
    {
        p->pushEvent(ev);
    }
}


