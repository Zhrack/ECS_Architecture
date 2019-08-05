#include "pch.h"
#include "PlayerInputProcessor.h"

#include "Components.h"

PlayerInputProcessor::PlayerInputProcessor(EntityManager* manager, sf::RenderWindow* win) :
    BaseProcessor(manager, {
        COMP_PLAYER_INPUT,
        COMP_VELOCITY
        }),
    mWindow(win)
{
}


PlayerInputProcessor::~PlayerInputProcessor()
{
}

void PlayerInputProcessor::update(float elapsed)
{
    // poll events
    sf::Event event;
    while (mWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            mWindow->close();
    }

    for (auto& e : mCurrentDeps)
    {
        auto velocity = e.getAs<VelocityComponent>(CompType::COMP_VELOCITY);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            velocity->setVelocity(sf::Vector2f(-10.f, 0.f));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            velocity->setVelocity(sf::Vector2f(10.f, 0.f));
        }
        else
        {
            velocity->setVelocity(sf::Vector2f());
        }

    }
}
