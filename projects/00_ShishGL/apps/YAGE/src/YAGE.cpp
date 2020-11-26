/*============================================================================*/
#include "ColorFill.hpp"
#include "ColorCollection.hpp"
#include "TextureFill.hpp"
#include "Bordered.hpp"
#include "UIWindow.hpp"
#include "Draggable.hpp"
#include "YAGE.hpp"
#include "Canvas.hpp"
#include "RectangleShape.hpp"
#include "ToolSelector.hpp"
#include "ImageManager.hpp"

#include "Pen.hpp"
#include "Eraser.hpp"

/*============================================================================*/
using namespace YAGE;
using namespace ShishGL;
/*============================================================================*/

void YAGE::init() {

    constexpr double WIN_WIDTH  = 1600;
    constexpr double WIN_HEIGHT = 1000;

    auto holder = WindowManager::create<UIWindow>(
            Viewport{
                    {100, 20},
                    {WIN_WIDTH + 20, WIN_HEIGHT + 50}
            }
    );
    holder->applyShape<RectangleShape>();
    holder->applyStyle<UIWindow::NORMAL>(
            ColorFill{COLOR::PALE_VIOLET_RED}
    );

    holder->attach(createMainLayout({ {10, 40}, {WIN_WIDTH, WIN_HEIGHT} }));

    WindowManager::putRoot(holder);
}

/*----------------------------------------------------------------------------*/

UIWindow* YAGE::createMainLayout(const Viewport& frame) {

    auto main_win = WindowManager::create<UIWindow>(frame);
    main_win->applyShape<RectangleShape>();

    main_win->attach(createMenuLayout({ {0, 0}, {frame.size.x, 50} }));

    main_win->attach(createToolsLayout({ {0, 50}, {400, frame.size.y - 50} }));

    main_win->attach(createCanvasLayout({ {400, 50}, frame.size - Vector2<double>{400, 50} }));

    return main_win;
}

/*----------------------------------------------------------------------------*/

UIWindow* YAGE::createCanvasLayout(const Viewport &frame) {

    ImageManager::createImage({500, 500});

    auto canvas_frame = WindowManager::create<UIWindow>(frame);
    canvas_frame->applyShape<RectangleShape>();
    canvas_frame->applyStyle<UIWindow::NORMAL>(
            ColorFill{Color{10, 10, 10, 255}}
    );

    auto canvas = canvas_frame->attach<Canvas>(
            Viewport{
                    {50, 50},
                    {600, 600}
            }
    );
    canvas->applyShape<RectangleShape>();

    return canvas_frame;
}

/*----------------------------------------------------------------------------*/

static constexpr Vector2<double> BUTTON_SIZE{64, 64};
static constexpr double PADDING = 30;
static constexpr double SPACING = 10;
static constexpr double TOOL_BORDER = 5;

UIWindow* createToolButton(const Vector2<double>& pos, Tool* tool) {

    auto tool_bt = WindowManager::create<UIWindow>(
            Viewport{ pos, BUTTON_SIZE }
            );
    tool_bt->applyShape<RectangleShape>();
    tool_bt->addBehavior<ToolSelector>(tool);
    tool_bt->applyStyle<UIWindow::NORMAL>(
            Bordered{TOOL_BORDER, COLOR::BLACK},
            ColorFill{COLOR::WHITE},
            TextureFill{tool->getIcon()}
            );
    tool_bt->applyStyle<UIWindow::HOVER>(
            Bordered{TOOL_BORDER, COLOR::GREEN},
            ColorFill{COLOR::WHITE},
            TextureFill{tool->getIcon()}
            );
    tool_bt->applyStyle<UIWindow::CLICK>(
            Bordered{TOOL_BORDER, COLOR::BEIGE},
            ColorFill{COLOR::WHITE},
            TextureFill{tool->getIcon()}
            );

    return tool_bt;
}

/*----------------------------------------------------------------------------*/

UIWindow* YAGE::createToolsLayout(const Viewport& frame) {

    auto tools = WindowManager::create<UIWindow>(frame);
    tools->applyShape<RectangleShape>();
    tools->applyStyle<UIWindow::NORMAL>(
            ColorFill(COLOR::PAPAYA_WHIP)
    );

    tools->attach(createToolButton({PADDING, PADDING},
                                   ToolManager::getImpl<Pen>()));
    tools->attach(createToolButton({PADDING + BUTTON_SIZE.x + SPACING, PADDING},
                                   ToolManager::getImpl<Eraser>()));

    return tools;
}

/*----------------------------------------------------------------------------*/

UIWindow* createMenuButton(const Vector2<double>& pos, const Vector2<double>& size) {

    auto button = WindowManager::create<UIWindow>(
            Viewport{pos, size}
            );

    button->applyShape<RectangleShape>();
    button->addBehavior<Clickable>();
    button->applyStyle<UIWindow::NORMAL>(
            ColorFill{Color{36, 36, 36, 255}}
            );
    button->applyStyle<UIWindow::HOVER>(
            ColorFill{Color{50, 50, 50, 255}}
    );
    button->applyStyle<UIWindow::CLICK>(
            ColorFill{Color{200, 200, 200, 255}}
    );

    return button;
}

UIWindow* YAGE::createMenuLayout(const Viewport& frame) {

    auto menu = WindowManager::create<UIWindow>(frame);
    menu->applyShape<RectangleShape>();
    menu->applyStyle<UIWindow::NORMAL>(
            ColorFill(Color{32, 32, 32, 255})
    );

    menu->attach(createMenuButton({0, 0}, {100, frame.size.y}));

    return menu;
}

/*============================================================================*/