#ifndef DEPENCENCY_H_
#define DEPENCENCY_H_

#include "ComponentDefs.h"

/// <summary>
/// Stores the information for every entity and the components that are wanted by the concrete class.
/// This way, the structure is updated only when the main structure in EntityManager is updated.
/// The rest of the time, this is iterated instead of the main structure of EntityManager.
/// </summary>
struct Dependency
{
    EntityID mID;

    std::unordered_map<CompType, BaseComponent*> mComponents;

    Dependency(EntityID id, std::unordered_map<CompType, BaseComponent*>& comps) :
        mID(id)
    {
        mComponents.swap(comps);
    }

    template<class T>
    T* getAs(CompType type)
    {
        static_assert(std::is_base_of<BaseComponent, T>::value, "T must derive from BaseComponent");

        return static_cast<T*>(mComponents[type]);
    }
};

#endif // !DEPENCENCY_H_
