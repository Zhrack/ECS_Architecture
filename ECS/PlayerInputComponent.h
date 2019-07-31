#ifndef PLAYER_INPUT_COMPONENT_H_
#define PLAYER_INPUT_COMPONENT_H_

/// <summary>
/// An empty component that tags entities under player control.
/// </summary>
struct PlayerInputComponent
{
    PlayerInputComponent();
    ~PlayerInputComponent();
};

using PlayerControllable = Component<PlayerInputComponent>;

#endif // !PLAYER_INPUT_COMPONENT_H_
