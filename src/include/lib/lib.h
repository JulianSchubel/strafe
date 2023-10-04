#ifndef PRELUDE
#define PRELUDE

#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <iostream>
#include <inttypes.h>

namespace PRELUDE {
    const float BASE_PLAYER_RADIUS = 40.f;
    const float BASE_PLAYER_X = 100.f;
    const float BASE_PLAYER_Y = 100.f;
    const auto BASE_PLAYER_COLOR = sf::Color::Cyan;
    const float BASE_PLAYER_SPEED = 100.f;
}

#endif //PRELUDE
