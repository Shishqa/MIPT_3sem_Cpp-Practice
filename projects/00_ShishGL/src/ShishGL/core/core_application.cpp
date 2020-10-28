/*============================================================================*/
#include "ShishGL/core/log.hpp"
#include "ShishGL/core/core_application.hpp"
#include "ShishGL/core/event_system.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

bool CoreApplication::initialized = false;

CoreApplication::ObjectSet& CoreApplication::ActiveObjects() {
    static ObjectSet ACTIVE_OBJECTS;
    return ACTIVE_OBJECTS;
}

/*----------------------------------------------------------------------------*/

bool CoreApplication::init(int *argc_ptr, char **argv) {

    if (initialized) {
        return false;
    }

    LogSystem::openLog();

    LogSystem::printLog("initializing engine...");
    Engine::initialize(argc_ptr, argv);
    LogSystem::printLog("engine initialized");

    initialized = true;

    return true;
}

/*----------------------------------------------------------------------------*/

uint8_t CoreApplication::run() {

    if (!initialized) {
        LogSystem::printError("Running CoreApplication before initialization");
        return 1; /* todo */
    }

    while (Engine::isRunning()) {

        Engine::clear();

        for (const auto& obj : ActiveObjects()) {
            EventSystem::sendEvent(obj, Event::RENDER);
        }

        Engine::display();

        EventSystem::dispatchEvents();
    }

    terminate();

    return 0;
}

/*----------------------------------------------------------------------------*/

bool CoreApplication::terminate() {

    EventSystem::flush();

    for (const auto& obj : ActiveObjects()) {
        delete obj;
    }

    LogSystem::printLog("terminating engine...");
    Engine::terminate();
    LogSystem::printLog("engine terminated");

    LogSystem::closeLog();

    initialized = false;

    return true;
}

/*============================================================================*/