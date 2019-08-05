#ifndef PLAYER_INPUT_PROCESSOR_H_
#define PLAYER_INPUT_PROCESSOR_H_

#include "BaseProcessor.h"

#include <SFML/Graphics.hpp>

class PlayerInputProcessor :
    public BaseProcessor
{
public:
    PlayerInputProcessor(EntityManager* manager, sf::RenderWindow* win);
    virtual ~PlayerInputProcessor();

    // Inherited via BaseProcessor
    virtual void update(float elapsed) override;

private:
    sf::RenderWindow* mWindow;
};


#endif // !PLAYER_INPUT_PROCESSOR_H_
