#include "./game_state.h"
#include "../lib/lib.h"

GameState::GameState() : mWindow(sf::VideoMode(640, 480), "SFML Application"),
                        mPlayer()
{
    mPlayer.setRadius(PRELUDE::BASE_PLAYER_RADIUS);
    mPlayer.setPosition(PRELUDE::BASE_PLAYER_X, PRELUDE::BASE_PLAYER_Y);
    mPlayer.setFillColor(PRELUDE::BASE_PLAYER_COLOR);
}

/* run: the main game loop */
void GameState::run() {
    /* each iteration is a frame / tick. FPS = iterations per second */
    while(mWindow.isOpen()) {
        /* process input events */
        processEvents();
        /* update game state */
        update();
        /* render game state */
        render();
    }
}
                        
/* processEvents: handles user input. Will close the window if a sf::Event::Closed event occurs */
void GameState::processEvents() {
    sf::Event event;
    while(mWindow.pollEvent(event)) {
        /* handle key presses; are enums so can just switch */
        switch (event.type) {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break; 
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                mWindow.close();
            default:
                break;
        }
    }
}

/* handlePlayerInput: handles player input from keyboard, taking in the code for a key, and a boolean indicating whether the key was pressed or released */
void GameState::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    switch (key) {
        case sf::Keyboard::W: 
            std::cout << "W" << std::endl;
            break;
        case sf::Keyboard::A:
            break;
        case sf::Keyboard::S:
            break;
        case sf::Keyboard::D:
            break;
        default:
            break;
    }
}

/* update: update the game state */
void GameState::update() {
    /* not implemented */
    ;
}

/* render: renders the current game state to the screen */
void GameState::render() {
    /* clear the screen of the old game state */
    mWindow.clear();
    /* draw the new state */
    mWindow.draw(mPlayer);
    /*  */
    mWindow.display();
}



