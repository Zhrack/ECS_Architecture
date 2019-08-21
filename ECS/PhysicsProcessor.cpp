#include "PhysicsProcessor.h"

#include "Components.h"


PhysicsProcessor::PhysicsProcessor(EntityManager* manager) : 
    BaseProcessor(manager, {
        CompType::COMP_PHYSICS
        }),
    mWorld(new b2World(b2Vec2_zero)),
    mContactListener(new MyContactListener())
{
    mWorld->SetContactListener(mContactListener.get());
}


PhysicsProcessor::~PhysicsProcessor()
{
}

void PhysicsProcessor::update(float elapsed)
{
    // since I'm using a fixed timestep, I can pass it to physics too
    mWorld->Step(elapsed, 10, 8);
    
    mWorld->ClearForces();
}

void PhysicsProcessor::onNotify(const Event & ev)
{    
    // first check standard events
    BaseProcessor::onNotify(ev);

    // not check the rest

}
