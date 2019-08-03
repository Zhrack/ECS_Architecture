#ifndef COMPONENT_DEFS_H_
#define COMPONENT_DEFS_H_

#include <vector>
#include <memory>

#include "BaseComponent.h"

using EntityID = std::uint64_t;


using BaseComponentPtr = std::unique_ptr<BaseComponent>;

using ComponentList = std::vector<BaseComponentPtr>;

enum CompType
{
    COMP_TRANSFORM = 0,
    COMP_VELOCITY,
    COMP_RENDER,
    COMP_PLAYER_INPUT,

    COMP_COUNT // keep last
};

using EntityComponentList = std::vector<std::pair<CompType, BaseComponent*>>;

#endif // !COMPONENT_DEFS_H_
