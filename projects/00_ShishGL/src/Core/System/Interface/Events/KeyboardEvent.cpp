/*============================================================================*/
#include "KeyboardEvent.hpp"
#include "SystemObject.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

KeyboardEvent::KeyboardEvent(Keyboard::Key key,
                             Keyboard::KeyState state,
                             Keyboard::ModifierMask modifiers)
                             : k_key(key)
                             , k_state(state)
                             , k_modifiers(modifiers)
                             { }

/*----------------------------------------------------------------------------*/

bool KeyboardEvent::happen(Object::ID listener) {
    return GET<SystemObject>(listener).onKeyboard(*this);
}

/*----------------------------------------------------------------------------*/

Keyboard::Key KeyboardEvent::key() const {
    return k_key;
}

/*----------------------------------------------------------------------------*/

Keyboard::KeyState KeyboardEvent::state() const {
    return k_state;
}

/*----------------------------------------------------------------------------*/

Keyboard::ModifierMask KeyboardEvent::modifiers() const {
    return k_modifiers;
}

/*============================================================================*/
