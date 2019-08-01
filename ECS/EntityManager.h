#ifndef ENTITY_MANAGER_H_
#define ENTITY_MANAGER_H_

#include <stack>

#include "EntityIDPool.h"

#include "RenderProcessor.h"

#include <SFML/Graphics.hpp>


class EntityManager
{
public:
    EntityManager(unsigned long entityPool, sf::RenderWindow* win);
    ~EntityManager();

    std::vector<Dependency> intersection(const std::vector<CompType>& deps);

private:
    std::vector<ComponentList>  mComponents;

    EntityIDPool                mEntityIDPool;

    unsigned long               mMaxEntities;

    sf::RenderWindow*           mRenderWindow;

    // Processors
    RenderProcessor             mRenderProcessor;

};


#endif // !ENTITY_MANAGER_H_