#ifndef BASE_PROCESSOR_H_
#define BASE_PROCESSOR_H_

#include <vector>

#include "ComponentDefs.h"

#include "EntityManager.h"

class BaseProcessor
{
public:
    BaseProcessor(EntityManager* manager, const std::vector<CompType>& deps);
    virtual ~BaseProcessor();

    void updateIntersection(std::vector<EntityID>& newEntities);

    virtual void update(float elapsed) = 0;

protected:
    std::vector<CompType>   mDependenciesComps;
    std::vector<EntityID>   mCurrentEntities;

    EntityManager*          mEntityMngr;
};


#endif // !BASE_PROCESSOR_H_
