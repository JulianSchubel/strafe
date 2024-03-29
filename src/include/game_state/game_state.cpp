#include "./game_state.h"
#include <SFML/System/Vector2.hpp>

GameState::GameState() : mWindow(sf::VideoMode(640, 480), "SFML Application"),
                        mPlayer()
{
    mPlayer.setRadius(PRELUDE::BASE_PLAYER_RADIUS);
    mPlayer.setPosition(PRELUDE::BASE_PLAYER_X, PRELUDE::BASE_PLAYER_Y);
    mPlayer.setFillColor(PRELUDE::BASE_PLAYER_COLOR);

    mIsMovingUp = false;
    mIsMovingDown = false;
    mIsMovingLeft = false;
    mIsMovingRight = false;
}

/* run: the main game loop */
void GameState::run() {
    /* utility class that measures elapsed time */
    sf::Clock clock;
    /* each iteration is a frame / tick. FPS = iterations per second */
    while(mWindow.isOpen()) {
        /* reset clock and time duration of frame */
        sf::Time deltaTime = clock.restart();
        /* process input events */
        processEvents();
        /* update game state */
        update(deltaTime);
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
            mIsMovingUp = isPressed;
            break;
        case sf::Keyboard::S:
            mIsMovingDown = isPressed;
            break;
        case sf::Keyboard::A:
            mIsMovingLeft = isPressed;
            break;
        case sf::Keyboard::D:
            mIsMovingRight = isPressed;
            break;
        default:
            break;
    }
}

/* update: update the game state */
void GameState::update() {
    /* typedef of sf::Vector2<float>. Represents a vector in R2 space (2 dimensional) */
    sf::Vector2f movement(0.f, 0.f);
    if(mIsMovingUp) {
        movement.y -= PRELUDE::BASE_PLAYER_SPEED;
    }
    if(mIsMovingDown) {
        movement.y += PRELUDE::BASE_PLAYER_SPEED;
    }
    if(mIsMovingLeft) {
        movement.x -= PRELUDE::BASE_PLAYER_SPEED;
    }
    if(mIsMovingRight) {
        movement.x += PRELUDE::BASE_PLAYER_SPEED;
    }

    mPlayer.move(movement);
}

/* update: overloaded, frame-independent movement; use distance = speed * time to have momvement directly proportional to frame time */
void GameState::update(sf::Time deltaTime) {
    sf::Vector2f movement(0.f, 0.f);
    if(mIsMovingUp) {
        movement.y -= PRELUDE::BASE_PLAYER_SPEED;
    }
    if(mIsMovingDown) {
        movement.y += PRELUDE::BASE_PLAYER_SPEED;
    }
    if(mIsMovingLeft) {
        movement.x -= PRELUDE::BASE_PLAYER_SPEED;
    }
    if(mIsMovingRight) {
        movement.x += PRELUDE::BASE_PLAYER_SPEED;
    }

    /* amount to move = kM where M is the set movement increment and k the time since the start of the frame */
    mPlayer.move(movement * deltaTime.asSeconds());
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
