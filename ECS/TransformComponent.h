#ifndef TRANSFORM_COMPONENT_H_
#define TRANSFORM_COMPONENT_H_

#include "ComponentDefs.h"

class TransformComponent
{
public:
    TransformComponent();
    ~TransformComponent();
};

using Transforms = Component<TransformComponent>;

#endif // !TRANSFORM_COMPONENT_H_
