#include "pch.h"
#include "BaseProcessor.h"

#include "EntityManager.h"

BaseProcessor::BaseProcessor(EntityManager* manager, const std::vector<CompType>& deps) :
    mWantedTypes(deps),
    mCurrentDeps(),
    mEntityMngr(manager)
{
}


BaseProcessor::~BaseProcessor()
{
}

void BaseProcessor::updateIntersection(std::vector<Dependency>& newEntities)
{
    mCurrentDeps.swap(newEntities);
}

void BaseProcessor::updateProcessor(float elapsed)
{
    Observer::update();

    update(elapsed);
}

void BaseProcessor::onNewComponent(const Event & event)
{
    const auto& data = event.newCompData;

    // check if the new component is wanted
    auto iter = std::find(mWantedTypes.begin(), mWantedTypes.end(), data.type);
    if (iter == mWantedTypes.end()) return;

    // check if entity has all other components needed
    const auto& list = mEntityMngr->getComponents(data.id);

    // not enough components on this entity
    if (list.size() < mWantedTypes.size()) return;

    size_t counter = 0;
    std::unordered_map<CompType, BaseComponent*> comps;

    for (auto& e : list)
    {
        for (auto it = mWantedTypes.begin(); it != mWantedTypes.end(); it++)
        {
            if (e.first == *it)
            {
                counter++;
                comps[e.first] = e.second;
                it = mWantedTypes.end();
            }
        }
    }

    if (counter == mWantedTypes.size())
    {
        mCurrentDeps.emplace_back(data.id, comps);
    }
}

void BaseProcessor::onRemoveComponent(const Event & event)
{
    const auto& data = event.removeCompData;

    // check if the new component was wanted
    auto iter = std::find(mWantedTypes.begin(), mWantedTypes.end(), data.type);
    if (iter == mWantedTypes.end()) return;

    // check if the entity is present
    auto iter2 = std::find(mCurrentDeps.begin(), mCurrentDeps.end(), [this, &data](Dependency& dep) {
        return dep.mID == data.id;
    });
    if (iter2 == mCurrentDeps.end()) return;

    // TODO remove from currentDeps
}

void BaseProcessor::onNewEntity(const Event & event)
{
    const auto& data = event.newEntityData;
}

void BaseProcessor::onRemoveEntity(const Event & event)
{
    const auto& data = event.removeEntityData;
}

void BaseProcessor::onNotify(const Event & event)
{
    auto eventID = event.mID;

    switch (eventID)
    {
    case EVENT_NEW_COMPONENT:
        onNewComponent(event);
        break;
    case EVENT_REMOVE_COMPONENT:
        onRemoveComponent(event);
        break;
    case EVENT_NEW_ENTITY:
        onNewEntity(event);
        break;
    case EVENT_REMOVE_ENTITY:
        onRemoveEntity(event);
        break;
    default:
        break;
    }
}