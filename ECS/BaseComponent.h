#ifndef BASE_COMPONENT_H_
#define BASE_COMPONENT_H_

#include <mutex>
#include "Observable.h"

struct BaseComponent : public Observable
{
    BaseComponent() {}
    virtual ~BaseComponent() {}

protected:
    /// <summary>
    /// Used to regulate access to this component.
    /// </summary>
    std::mutex  mMutex;
};

#endif // !BASE_COMPONENT_H_
