/*============================================================================*/
#ifndef SHISHGL_CURSOR_LOCATOR_HPP
#define SHISHGL_CURSOR_LOCATOR_HPP
/*============================================================================*/
#include "Window.hpp"
/*============================================================================*/
namespace ShishGL {

    class CursorLocator : public Window {
    public:

        explicit CursorLocator(Shape2D* shape);

    protected:

        bool onMouseMove(MouseEvent& event) override;

    };

}
/*============================================================================*/
#endif //SHISHGL_CURSOR_LOCATOR_HPP
/*============================================================================*/