#include "pch.h"
#include "EntityManager.h"


EntityManager::EntityManager(int entityPool):
    mComponents(entityPool),
    mEntityIDPool(entityPool)
{

}


EntityManager::~EntityManager()
{
}
