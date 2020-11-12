/*============================================================================*/
#ifndef SHISHGL_CLICKABLE_WINDOW_HPP
#define SHISHGL_CLICKABLE_WINDOW_HPP
/*============================================================================*/
#include "Window.hpp"
/*============================================================================*/
namespace ShishGL {

    template <typename Shape>
    class ClickableWindow : public Window<Shape> {
    public:

        template <typename... Args>
        ClickableWindow(Object::ID id, Object::ID parent, Args&&... args);

        ~ClickableWindow() override = default;

        [[nodiscard]]
        bool filterEvent(const Event& event) const override;

    };

}
/*============================================================================*/
#include "ClickableWindow.ipp"
/*============================================================================*/
#endif //SHISHGL_CLICKABLE_WINDOW_HPP
/*============================================================================*/
