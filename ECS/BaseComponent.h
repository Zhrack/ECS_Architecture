#ifndef BASE_COMPONENT_H_
#define BASE_COMPONENT_H_

#include <mutex>

#include "EntityDefs.h"
#include "Observable.h"

struct BaseComponent : public Observable
{
    BaseComponent() = delete;

    BaseComponent(EntityID id) :
        mEntityID(id) {}

    virtual ~BaseComponent() {}

    EntityID getEntityID() const { return mEntityID; }

protected:
    /// <summary>
    /// Used to regulate access to this component.
    /// </summary>
    std::mutex  mMutex;

    // ID of this component
    EntityID    mEntityID;
};

#endif // !BASE_COMPONENT_H_
