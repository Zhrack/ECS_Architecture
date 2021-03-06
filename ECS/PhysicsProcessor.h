#ifndef PHYSICS_PROCESSOR_H_
#define PHYSICS_PROCESSOR_H_

#include "BaseProcessor.h"

#include "Box2D/Box2D.h"

#include <memory>

class MyContactListener;

class PhysicsProcessor :
    public BaseProcessor
{
public:
    PhysicsProcessor(EntityManager* manager);
    virtual ~PhysicsProcessor();

    // Inherited via BaseProcessor
    virtual void update(float elapsed) override;

private:
    // Inherited via BaseProcessor
    virtual void onNotify(const Event & event) override;

private:
    std::unique_ptr<b2World>            mWorld;

    std::unique_ptr<MyContactListener>  mContactListener;
};

class MyContactListener : public b2ContactListener
{
    void BeginContact(b2Contact* contact);

    void EndContact(b2Contact* contact);
};


#endif // !PHYSICS_PROCESSOR_H_
