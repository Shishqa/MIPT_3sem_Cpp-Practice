#include "ShishGL/ShishGL.hpp"
#include "SortAnalyser/sort_analyser_window.hpp"

using namespace SortAnalyser;


int main(int argc, char** argv) {

    ShishGL::init(&argc, argv);

    MainWindow* app = new SortAnalyserWindow();

    if (!app) {
        fprintf(stderr, "no app\n");
        return 1;
    }

    app->run();

    delete app;

    ShishGL::terminate();

    return 0;
}
