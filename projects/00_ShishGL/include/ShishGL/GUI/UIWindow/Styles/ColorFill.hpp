/*============================================================================*/
#ifndef SHISHGL_COLOR_FILL_HPP
#define SHISHGL_COLOR_FILL_HPP
/*============================================================================*/
#include "GUI/UIWindow/Styles/Style.hpp"
#include "Color.hpp"
#include "RenderSystem.hpp"
/*============================================================================*/
namespace ShishGL {

    class ColorFill : public Style {
    public:

        explicit ColorFill(const Color& color)
            : fill_color(color)
            { }

        void apply(Viewport&, const Shape2D&) override {
            RENDERER().setColor(fill_color);
        }

        ~ColorFill() override = default;

    private:

        Color fill_color;

    };

}
/*============================================================================*/
#endif //SHISHGL_COLOR_FILL_HPP
/*============================================================================*/
