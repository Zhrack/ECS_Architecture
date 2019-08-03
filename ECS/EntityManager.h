#ifndef ENTITY_MANAGER_H_
#define ENTITY_MANAGER_H_

#include <stack>
#include <iostream>

#include "EntityIDPool.h"

#include "RenderProcessor.h"

#include <SFML/Graphics.hpp>


class EntityManager
{
public:
    EntityManager(unsigned long entityPool, sf::RenderWindow* win);
    ~EntityManager();

    void update(float elapsed);

    std::vector<Dependency> intersection(const std::vector<CompType>& deps);

    EntityID createEntity();
    EntityID createEntity(const std::vector<CompType>& deps);

    void removeEntity(EntityID id);

    template<class T>
    void addComponent(CompType type, EntityID id);

    void removeComponent(CompType type, EntityID id);

    template<class T>
    T* getComponent(CompType type, EntityID id);

    /// <summary>
    /// Gets the component list of the given EntityID.
    /// </summary>
    /// <param name="id">The identifier.</param>
    /// <returns></returns>
    std::vector<std::pair<CompType, BaseComponent*>> getComponents(EntityID id);

private:
    std::vector<ComponentList>  mComponents;

    EntityIDPool                mEntityIDPool;

    unsigned long               mMaxEntities;

    sf::RenderWindow*           mRenderWindow;

    // Processors
    RenderProcessor             mRenderProcessor;

};


#endif // !ENTITY_MANAGER_H_

template<class T>
inline void EntityManager::addComponent(CompType type, EntityID id)
{
    if (mComponents[type][id] != nullptr)
    {
        std::cout << "Component already present!" << std::endl;
        return;
    }

    static_assert(std::is_base_of<BaseComponent, T>::value, "T must derive from BaseComponent");

    mComponents[type][id].reset(new T());

    // TODO notify processors of new component

}

template<class T>
inline T * EntityManager::getComponent(CompType type, EntityID id)
{
    static_assert(std::is_base_of<BaseComponent, T>::value, "T must derive from BaseComponent");


    return static_cast<T*>(mComponents[type][id].get());
}
