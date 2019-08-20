#ifndef ENTITY_MANAGER_H_
#define ENTITY_MANAGER_H_

#include <stack>
#include <iostream>

#include "EntityIDPool.h"
#include "Events.h"

#include "Components.h"
#include "BaseProcessor.h"

#include <SFML/Graphics.hpp>

#include "Box2D/Box2D.h"


class EntityManager
{
public:
    EntityManager(unsigned long entityPool, sf::RenderWindow* win);
    ~EntityManager();

    bool initialize();

    void update(float elapsed);

    bool terminate();

    std::vector<Dependency> intersection(const std::vector<CompType>& deps);

    EntityID createEntity(const std::vector<CompType>& deps);

    void removeEntity(EntityID id);

    template<class ...Args>
    BaseComponent* addComponent(CompType type, EntityID id, bool notify = true, Args... args);

    void removeComponent(CompType type, EntityID id);

    template<class T>
    T* getComponent(CompType type, EntityID id);

    /// <summary>
    /// Gets the component list of the given EntityID.
    /// </summary>
    /// <param name="id">The identifier.</param>
    /// <returns></returns>
    EntityComponentList getComponents(EntityID id);

    void notifyProcessors(const Event& ev);

private:
    EntityID createEntity();

    template<class ...Args>
    BaseComponent* getFromType(CompType type, Args... args);

private:
    std::vector<ComponentList>      mComponents;

    EntityIDPool                    mEntityIDPool;

    unsigned long                   mMaxEntities;

    sf::RenderWindow*               mRenderWindow;

    // Processors
    std::vector<BaseProcessorPtr>   mProcessors;
};


#endif // !ENTITY_MANAGER_H_

template<class T>
inline T * EntityManager::getComponent(CompType type, EntityID id)
{
    static_assert(std::is_base_of<BaseComponent, T>::value, "T must derive from BaseComponent");


    return static_cast<T*>(mComponents[type][id].get());
}

template<class ...Args>
inline BaseComponent* EntityManager::addComponent(CompType type, EntityID id, bool notify, Args... args)
{
    if (mComponents[type][id] != nullptr)
    {
        std::cout << "Component already present!" << std::endl;
        return mComponents[type][id].get();
    }

    mComponents[type][id].reset(getFromType(type, args...));

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

template<class ...Args>
inline BaseComponent * EntityManager::getFromType(CompType type, Args... args)
{
    BaseComponent* comp = nullptr;

    switch (type) {
    case COMP_PHYSICS:
        comp = new PhysicsComponent(args...);
        break;
    case COMP_RENDER:
        comp = new RenderComponent(args...);
        break;
    case COMP_PLAYER_INPUT:
        comp = new PlayerInputComponent(args...);
        break;
    case COMP_COUNT:
    default:
        break;
    }

    return comp;
}
