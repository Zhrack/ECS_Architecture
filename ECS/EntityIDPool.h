#ifndef ENTITY_ID_POOL_H_
#define ENTITY_ID_POOL_H_

#include <stack>

#include "ComponentDefs.h"

class EntityIDPool
{
public:
    EntityIDPool(unsigned long entityPool);
    ~EntityIDPool();

    EntityIDPool() = delete;

    EntityID generateID();

    void freeID(EntityID id);

    EntityID currentMax() const;

private:
    std::stack<EntityID>    mEntityIDPool;
    EntityID                mCurrentMax;
};


#endif // !ENTITY_ID_POOL_H_
