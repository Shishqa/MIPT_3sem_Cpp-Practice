/*============================================================================*/
#include "Platform.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

SfmlPlatform::SfmlPlatform()
    : is_running(false)
    , canvas(nullptr)
    , active_color({})
    , active_font({})
    { }

/*----------------------------------------------------------------------------*/

bool SfmlPlatform::initDisplay(int*, char**) {

    canvas = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "sfml",
                                  sf::Style::Fullscreen);

    //canvas->setMouseCursorVisible(false);

    /* todo: fix hard-coded font */
    if (!active_font.loadFromFile("./FiraCode-Regular.ttf")) {
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

Vector2<size_t> SfmlPlatform::getDisplaySize() {

    sf::VideoMode screen = sf::VideoMode::getDesktopMode();

    return Vector2<size_t>{screen.width, screen.height};
}

/*----------------------------------------------------------------------------*/

Vector2<double> SfmlPlatform::getMousePos() {
    return Vector2<double>{
        static_cast<double>(sf::Mouse::getPosition(*canvas).x),
        static_cast<double>(sf::Mouse::getPosition(*canvas).y)
    };
}

/*============================================================================*/
