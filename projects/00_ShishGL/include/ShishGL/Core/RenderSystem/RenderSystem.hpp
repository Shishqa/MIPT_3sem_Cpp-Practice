/*============================================================================*/
#ifndef SHISHGL_RENDER_SYSTEM_HPP
#define SHISHGL_RENDER_SYSTEM_HPP
/*============================================================================*/
#include "IPlatform.hpp"
#include "LayoutManager.hpp"
/*============================================================================*/
namespace ShishGL {

    class RenderSystem {
    public:

        static bool init(int* argc_ptr, char* argv[]);

        static bool update();

        static bool terminate();

        static bool isInitialized();

        static IPlatform& Renderer();

    private:

        static void render(Renderable::ID obj);

        static bool is_initialized;

        static IPlatform* active_platform;

    };

    IPlatform& RENDERER();

}
/*============================================================================*/
#endif //SHISHGL_RENDER_SYSTEM_HPP
/*============================================================================*/