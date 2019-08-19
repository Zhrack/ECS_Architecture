#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "BaseState.h"

#include "BaseComponent.h"

#include "EntityManager.h"

#include <unordered_map>
#include <vector>
#include <memory>
#include <algorithm>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace pt = boost::property_tree;

enum class GameStatus
{
    GAME_NORMAL,
    GAME_LOSE,
    GAME_WIN
};

/// <summary>
/// State that manages the actual game.
/// It acts as a central hub for informations for components.
/// </summary>
/// <seealso cref="BaseState" />
/// <seealso cref="std::enable_shared_from_this{GameState}" />
class GameState :
    public BaseState
{
public:
    GameState(World* world, pt::ptree& tree);
    virtual ~GameState();

    // Inherited via BaseState
    virtual void enter() override;
    virtual void update() override;
    virtual void exit() override;

    pt::ptree& config();

    /////////////////////////////////
    // GAMEPLAY
    /////////////////////////////////

    void increaseScore(long points);

    void decrementPlayerLives();

    int getPlayerLives() const;

    /// <summary>
    /// Manages game over changes.
    /// </summary>
    /// <param name="win">if set to <c>true</c> will be shown a winning text, else a losing text [win].</param>
    void gameOver(bool win);

    void restartGame();

    const sf::RectangleShape& getWalls() const;

private:
    void updateGame(float elapsed);

    void renderGame(float elapsed);

    void buildLevel();

private:

    /// <summary>
    /// General clock for the game.
    /// </summary>
    sf::Clock mClock;

    float mCurrentTime;
    float mPreviousTime;
    float mTimeLag;
    float mMSPerUpdate;

    EntityManager   mEntityMngr;

    GameStatus mGameStatus;

    // general game data
    long mHighScore;
    long mCurrentScore;
    int mRemainingLives;

    sf::Font mFont;

    sf::Text mHighScoreText;
    sf::Text mHighScoreNumberText;
    sf::Text mCurrentScoreText;
    sf::Text mCurrentScoreNumberText;
    sf::Text mRemainingLivesText;
    sf::Text mRemainingLivesNumberText;

    sf::Text mGameOverText;
    sf::Text mGameOverInstructionsText;
    sf::Text mGameOverInstructions2Text;

    sf::Texture mBackgroundTexture;

    sf::RectangleShape mWalls;

    pt::ptree& mTree;
};


#endif // !GAME_STATE_H
