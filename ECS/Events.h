#ifndef EVENTS_H_
#define EVENTS_H_

#include "ComponentDefs.h"

enum EventID
{
    EVENT_NEW_ENTITY,
    EVENT_REMOVE_ENTITY,
    EVENT_NEW_COMPONENT,
    EVENT_REMOVE_COMPONENT,


    EVENT_COUNT
};

struct Event
{
    // Data structures for events

    // EVENT_NEW_ENTITY
    struct NewEntityEv
    {
        EntityID id;
        EntityComponentList comps;
    };

    // EVENT_REMOVE_ENTITY
    struct RemoveEntityEv
    {
        EntityID id;
    };

    // EVENT_NEW_COMPONENT
    struct NewComponentEv
    {
        EntityID id;
        CompType type;
        BaseComponent* comp;
    };

    // EVENT_REMOVE_COMPONENT
    struct RemoveComponentEv
    {
        EntityID id;
        CompType type;
    };

    EventID mID;

    union
    {
        NewEntityEv newEntityData;
        RemoveEntityEv removeEntityData;
        NewComponentEv newCompData;
        RemoveComponentEv removeCompData;
    };

    Event() {}
    Event(const Event& e) :
        mID(e.mID){}
    ~Event() {}
};


#endif // !EVENTS_H_
