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
        switch (event.type)
        {
        case sf::Event::Closed:
            mWindow->close();
            break;
        //case sf::Event::KeyPressed:
        //    if (mGameStatus == GameStatus::GAME_NORMAL)
        //    {
        //        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        //        {
        //            mPaddleBehaviorComp->onFireButtonPressed();
        //        }
        //    }
        //    else
        //    {
        //        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        //        {
        //            // go to MENU
        //            mWorld->changeState(new MenuState(mWorld, mTree));
        //            return;
        //        }
        //        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        //        {
        //            restartGame();
        //        }
        //    }
        }
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
