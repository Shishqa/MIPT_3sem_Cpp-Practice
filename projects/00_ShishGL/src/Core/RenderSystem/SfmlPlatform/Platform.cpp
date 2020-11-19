/*============================================================================*/
#include "Platform.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

SfmlPlatform::SfmlPlatform()
    : display_size({})
    , is_running(false)
    , canvas(nullptr)
    , active_color({})
    , active_font({})
    { }

/*----------------------------------------------------------------------------*/

bool SfmlPlatform::initDisplay(int*, char**) {

    sf::VideoMode screen = sf::VideoMode::getDesktopMode();

    canvas = new sf::RenderWindow(screen, "sfml", sf::Style::Fullscreen);

    display_size = Vector2<double>{
        static_cast<double>(screen.width),
        static_cast<double>(screen.height)
    };

    //canvas->setMouseCursorVisible(false);

    /* todo: fix hard-coded font */
    if (!active_font.loadFromFile("fonts/FiraCode-Regular.ttf")) {
        return false;
    }

    is_running = true;

    return true;
}

/*----------------------------------------------------------------------------*/

bool SfmlPlatform::isRunning() {
    return is_running;
}

/*----------------------------------------------------------------------------*/

bool SfmlPlatform::closeDisplay() {

    is_running = false;

    delete canvas;
    canvas = nullptr;

    return true;
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::clear(const Color& color) {
    canvas->clear(sf::Color{color.r, color.g, color.b, color.a});
}

/*----------------------------------------------------------------------------*/

void SfmlPlatform::display() {
    canvas->display();
}

/*============================================================================*/

const Vector2<double>& SfmlPlatform::getDisplaySize() {
    return display_size;
}

/*----------------------------------------------------------------------------*/

Vector2<double> SfmlPlatform::getMousePos() {
    return Vector2<double>{
        static_cast<double>(sf::Mouse::getPosition(*canvas).x),
        static_cast<double>(sf::Mouse::getPosition(*canvas).y)
    };
}

/*============================================================================*/
