#ifndef ENTITY_MANAGER_H_
#define ENTITY_MANAGER_H_

#include <stack>

#include "Components.h"

#include "EntityIDPool.h"


class EntityManager
{
public:
    EntityManager(int entityPool);
    ~EntityManager();

private:
    Components      mComponents;

    EntityIDPool    mEntityIDPool;
};


#endif // !ENTITY_MANAGER_H_
