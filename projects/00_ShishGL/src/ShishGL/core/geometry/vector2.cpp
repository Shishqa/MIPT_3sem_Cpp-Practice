/*============================================================================*/
#include "ShishGL/core/geometry/vector2.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

template <>
Vector2<double> Vector2<double>::operator!() const {
    double len = this->length();

    if (-0.0001 < len && len < 0.0001) {
        return *this;
    }

    Vector2<double> copy{*this};
    return (1 / len) * copy;
}

/*============================================================================*/
