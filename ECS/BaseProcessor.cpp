#include "pch.h"
#include "BaseProcessor.h"


BaseProcessor::BaseProcessor(EntityManager* manager, const std::vector<CompType>& deps) :
    mDependenciesComps(deps),
    mCurrentEntities(),
    mEntityMngr(manager)
{
}


BaseProcessor::~BaseProcessor()
{
}

void BaseProcessor::updateIntersection(std::vector<EntityID>& newEntities)
{
    mCurrentEntities.swap(newEntities);
}
