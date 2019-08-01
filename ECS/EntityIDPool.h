#ifndef ENTITY_ID_POOL_H_
#define ENTITY_ID_POOL_H_

#include <stack>
#include <set>

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

    std::set<EntityID>::iterator getUsedIDsIter();

    std::set<EntityID>::iterator endUsedIDsIter();

private:
    std::stack<EntityID>    mEntityIDPool;
    std::set<EntityID>      mUsedIDs;
    EntityID                mCurrentMax;
};


#endif // !ENTITY_ID_POOL_H_
