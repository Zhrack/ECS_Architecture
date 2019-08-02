#ifndef BASE_COMPONENT_H_
#define BASE_COMPONENT_H_

#include <mutex>

struct BaseComponent
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
