/*============================================================================*/
#ifndef SHISHGL_SFML_ENGINE_HPP
#define SHISHGL_SFML_ENGINE_HPP
/*============================================================================*/
#include <cstddef>
#include <string_view>

#include <SFML/Graphics.hpp>

#include "iSystem.hpp"
/*============================================================================*/
namespace ShishGL {

    class SfmlSystem : public ISystem {
    public:

        SfmlSystem();

        /* Input */
        /*--------------------------------------------------------------------*/
        Vector2<double> getMousePos() override;
        /*--------------------------------------------------------------------*/

        /* Draw */
        /*--------------------------------------------------------------------*/
        void setColor(const Color& color) override;

        void drawPoint(const Vector2<double>& pos) override;

        void drawLine(const Vector2<double>& start,
                      const Vector2<double>& end) override;

        void drawRectangle(const Vector2<double>& pos,
                           const Vector2<double>& size) override;

        void drawCircle(const Vector2<double>& pos,
                        const size_t& radius) override;
        /*--------------------------------------------------------------------*/

        /* TODO: Text */
        /*--------------------------------------------------------------------*/
        void displayText(const std::string_view& text, size_t font_size,
                         const Vector2<double>& pos) override;
        /*--------------------------------------------------------------------*/

        ~SfmlSystem() override = default;

    protected:

        /* Essential */
        /*--------------------------------------------------------------------*/
         bool initDisplay(int* argc_ptr, char* argv[]) override;

         bool isRunning() override;

         bool closeDisplay() override;

         Vector2<size_t> getDisplaySize() override;
        /*--------------------------------------------------------------------*/

        /* Rendering */
        /*--------------------------------------------------------------------*/
         void clear(const Color& color) override;

         void display() override;
        /*--------------------------------------------------------------------*/

        /* Events */
        /*--------------------------------------------------------------------*/
         bool pollEvent() override;
        /*--------------------------------------------------------------------*/

    private:


        /* IMPLEMENTATION SPECIAL */
    /*========================================================================*/

         bool is_running;

         sf::RenderWindow* canvas;

         Color active_color;

         sf::Font active_font;

    };

}
/*============================================================================*/
#endif //SHISHGL_SFML_ENGINE_HPP
/*============================================================================*/
