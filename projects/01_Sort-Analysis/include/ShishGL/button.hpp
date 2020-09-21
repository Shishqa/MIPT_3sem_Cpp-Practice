#ifndef BUTTON_HPP
#define BUTTON_HPP


#include <cstddef>
#include "window.hpp"
#include "draw.hpp"


namespace ShishGL {


    struct ButtonColorScheme {
        Color bg_default,
              bg_hover,
              bg_click,
              fg_default,
              fg_hover,
              fg_click;
    };


    constexpr ButtonColorScheme DEFAULT_BUTTON_COLORS = {
            {LEMON_CHIFFON, 255},
            {PAPAYA_WHIP,   255},
            {WHITE,         255},
            {BLACK,         255},   // not yet implemented
            {BLACK,         255},   //
            {BLACK,         255}    //
    };


    class Button : public Window {
    public:

        Button() = delete;

        Button(const char* button_label, const Event& click_event,
               const Vector2<int> position, const Vector2<size_t>& size,
               const ButtonColorScheme& colors = DEFAULT_BUTTON_COLORS);

        ~Button() override = default;

    protected:

        const Event& on_click;

        const char* label;
        size_t label_len;

        Color color_current,
              color_default,
              color_hover,
              color_click;

        void onRender() override;

        void onEntry(int state) override;

        void onMouseClick(int button, int state, int x, int y) override;

    };

}


#endif //BUTTON_HPP
