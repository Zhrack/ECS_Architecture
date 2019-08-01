#include "pch.h"
#include "BaseProcessor.h"


BaseProcessor::BaseProcessor(EntityManager* manager, const std::vector<CompType>& deps) :
    mWantedTypes(deps),
    mCurrentDeps(),
    mEntityMngr(manager)
{
}


BaseProcessor::~BaseProcessor()
{
}

void BaseProcessor::updateIntersection(std::vector<Dependency>& newEntities)
{
    mCurrentDeps.swap(newEntities);
}
