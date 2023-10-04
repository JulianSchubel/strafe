#pragma once
#include "../lib/lib.h"

class GameState
{
public:
    GameState();
    GameState(GameState &&) = default;
    GameState(const GameState &) = default;
    GameState &operator=(GameState &&) = default;
    GameState &operator=(const GameState &) = default;
    ~GameState() = default;

    /* run: the main game loop */
    void run();

private:
    /* processEvents: handles user input. Will close the window if a sf::Event::Closed event occurs */
    void processEvents();
    void update();
    void render();

    /* handlePlayerInput: handles player input from keyboard */
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;
};
