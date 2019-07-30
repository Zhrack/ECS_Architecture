#ifndef ENTITY_MANAGER_H_
#define ENTITY_MANAGER_H_

#include <stack>

#include "Components.h"

using EntityID = unsigned long;

class EntityManager
{
public:
    EntityManager(int entityPool);
    ~EntityManager();

private:
    Components              mComponents;

    std::stack<EntityID>    mEntityIDPool;
};


#endif // !ENTITY_MANAGER_H_
