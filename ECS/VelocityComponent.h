#ifndef VELOCITY_COMPONENT_H_
#define VELOCITY_COMPONENT_H_

#include "ComponentDefs.h"

class VelocityComponent
{
public:
    VelocityComponent();
    ~VelocityComponent();
};

using Velocities = Component<VelocityComponent>;

#endif