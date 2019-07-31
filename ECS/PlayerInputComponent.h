#ifndef PLAYER_INPUT_COMPONENT_H_
#define PLAYER_INPUT_COMPONENT_H_

#include "ComponentDefs.h"
#include "BaseComponent.h"

/// <summary>
/// An empty component that tags entities under player control.
/// </summary>
struct PlayerInputComponent : public BaseComponent
{
    PlayerInputComponent();
    ~PlayerInputComponent();
};

#endif // !PLAYER_INPUT_COMPONENT_H_
