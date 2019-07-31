#ifndef ENTITY_ID_POOL_H_
#define ENTITY_ID_POOL_H_

#include <stack>

#include "ComponentDefs.h"

class EntityIDPool
{
public:
    EntityIDPool(int entityPool);
    ~EntityIDPool();

    EntityIDPool() = delete;

    EntityID generateID();

    void freeID(EntityID id);

private:
    std::stack<EntityID>    mEntityIDPool;
};


#endif // !ENTITY_ID_POOL_H_
