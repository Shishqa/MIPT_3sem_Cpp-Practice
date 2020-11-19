/*============================================================================*/
#ifndef SHISHGL_IPLATFORM_HPP
#define SHISHGL_IPLATFORM_HPP
/*============================================================================*/
#include <string_view>

#include "Vector2.hpp"
#include "Color.hpp"
#include "ResourceManager.hpp"
/*============================================================================*/
namespace ShishGL {

    class IPlatform {
    public:

        virtual bool isRunning() = 0;

        /* Input */
        /*--------------------------------------------------------------------*/
        virtual Vector2<double> getMousePos() = 0;
        /*--------------------------------------------------------------------*/

        /* View */
        /*--------------------------------------------------------------------*/
        virtual void setViewport(const Vector2<double>& pos,
                                 const Vector2<double>& size,
                                 const Vector2<double>& dp_pos,
                                 const Vector2<double>& dp_size) = 0;

        virtual const Vector2<double>& getDisplaySize() = 0;
        /*--------------------------------------------------------------------*/

        /* Draw */
        /*--------------------------------------------------------------------*/
        virtual void setColor(const Color& color) = 0;

        virtual void setTexture(const ResourceManager::Resource& texture) = 0;

        virtual void drawPoint(const Vector2<double>& pos) = 0;

        virtual void drawLine(const Vector2<double>& start,
                             const Vector2<double>& end) = 0;

        virtual void drawRectangle(const Vector2<double>& pos,
                                  const Vector2<double>& size) = 0;

        virtual void drawCircle(const Vector2<double>& pos,
                                const double& radius) = 0;
        /*--------------------------------------------------------------------*/

        /* Image */
        /*--------------------------------------------------------------------*/
        virtual void displayImage(const ResourceManager::Resource& image,
                                  const Vector2<double>& position) = 0;
        /*--------------------------------------------------------------------*/

        /* Text */
        /*--------------------------------------------------------------------*/
        virtual void setFont(const ResourceManager::Resource& font) = 0;

        virtual void displayText(const ResourceManager::Resource& text,
                                 const size_t& font_size,
                                 const Vector2<double>& pos) = 0;
        /*--------------------------------------------------------------------*/

        virtual ~IPlatform() = default;

    protected:

        friend class RenderSystem;
        friend class WindowManager;
        friend class CoreApplication;

        IPlatform() = default;

        /* Essential */
        /*--------------------------------------------------------------------*/
        virtual bool initDisplay(int* argc_ptr, char* argv[]) = 0;

        virtual bool closeDisplay() = 0;
        /*--------------------------------------------------------------------*/

        /* Rendering */
        /*--------------------------------------------------------------------*/
        virtual void clear(const Color& color) = 0;

        virtual void display() = 0;
        /*--------------------------------------------------------------------*/

        /* Events */
        /*--------------------------------------------------------------------*/
        virtual bool pollEvent() = 0;
        /*--------------------------------------------------------------------*/

    };

}

/*============================================================================*/
#endif //SHISHGL_IPLATFORM_HPP
/*============================================================================*/