#ifndef ENTITY_MANAGER_H_
#define ENTITY_MANAGER_H_

#include <stack>

#include "EntityIDPool.h"


class EntityManager
{
public:
    EntityManager(unsigned long entityPool);
    ~EntityManager();

    std::vector<EntityID> intersection(const std::vector<CompType>& deps);

    template<class T>
    T* getComponent(CompType type, EntityID id);

private:
    std::vector<ComponentList>  mComponents;

    EntityIDPool                mEntityIDPool;

    unsigned long               mMaxEntities;
};


#endif // !ENTITY_MANAGER_H_

template<class T>
inline T * EntityManager::getComponent(CompType type, EntityID id)
{
    static_assert(std::is_base_of<BaseComponent, T>::value, "T must derive from BaseComponent");

    return static_cast<T*>(mComponents[type][id].get());
}
