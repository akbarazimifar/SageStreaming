#include "window_painter_glfw.h"

sage::Size<int> WindowPainterGLFW::_winSize;

WindowPainterGLFW::WindowPainterGLFW() : WindowPainterBase() {
#ifdef USE_IMGUI
    _gui = new sage::GuiLayer();
#endif
}

WindowPainterGLFW::~WindowPainterGLFW() {
#ifdef USE_IMGUI
    _gui->detach();
    delete _gui;
#endif
}

WindowPainterGLFW& WindowPainterGLFW::inst() {
    static WindowPainterGLFW inst;
    return inst;
}

GLFWwindow* WindowPainterGLFW::getWindow() {
    return _window;
}

#ifdef USE_IMGUI
sage::GuiLayer* WindowPainterGLFW::getGuiLayer() {
    return _gui;
}
#endif

bool WindowPainterGLFW::createWindow(int argc, char** argv, sage::Size<int> size) {
    _winSize = size;
    _data.height = size.height();
    _data.width = size.width();
    if (!_isInited) {
        if (!glfwInit()) {
            Log::error("GLFW initialization error.");
        }
        _isInited = true;
    }
    _window = glfwCreateWindow(size.width(), size.height(), "SageStreaming", nullptr, nullptr);
    /** Fullscreen mode. **/
    // _window = glfwCreateWindow(size.width(), size.height(),"SageStreaming", glfwGetPrimaryMonitor(), nullptr);
    glfwMakeContextCurrent(_window);
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);  //> Make use of existing GLFW loader;
    Log::info("OpenGL renderer:", glGetString(GL_VENDOR), glGetString(GL_RENDERER), glGetString(GL_VERSION));
#ifdef USE_IMGUI
    Log::critical("Set window");
    _gui->setGuiWindow(_window);
#endif
    glfwSetWindowUserPointer(_window, &_data);
    glfwSetWindowSizeCallback(_window, reshapeEvent);
    setVSync(true);
}

void WindowPainterGLFW::reshapeEvent(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, _winSize.width(), _winSize.height(), 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void WindowPainterGLFW::run() {
    /** @todo Find a better way of intital window shaping. **/
#ifdef USE_IMGUI
    _gui->init();
#endif
    reshapeEvent(_window, _data.width, _data.height);
    while (!glfwWindowShouldClose(_window)) {
        if (_painter) {
            if (!_painter->_isInited) {
                _painter->initTextures();
                _painter->_isInited = true;
            }
#ifdef USE_IMGUI
            _gui->beginDraw();
            _gui->processDraw();
#endif
            _painter->show(_winSize);
#ifdef USE_IMGUI
            _gui->endDraw();
#endif
            glfwPollEvents();
            glfwSwapBuffers(_window);
        }
    }
}

void WindowPainterGLFW::close() {
    glfwDestroyWindow(_window);
}

void WindowPainterGLFW::setVSync(bool enable) {
    enable ? glfwSwapInterval(1) : glfwSwapInterval(0);
}
