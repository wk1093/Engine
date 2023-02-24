#include "oglHeader.h"
#include <API/Window.h>

namespace Engine {
    std::string engineBackend() {
        return IMPLEMENTATION;
    }

    class IMPL(Window) {
    private:
        GLFWwindow* m_window;
        bool m_closed;
        Color m_clearColor;
        std::string m_title;
        Vector2i m_size;
        Vector2i m_position;
        bool m_resizable;
        bool m_fullscreen;
        bool m_vsync;
        bool m_cursor;

        void init() {
            if (!glfwInit()) {
                std::cout << "Failed to initialize GLFW" << std::endl;
                return;
            }
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // cant use glBegin/glEnd with this
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // cant use glBegin/glEnd with this
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // cant use glBegin/glEnd with this
            glfwWindowHint(GLFW_RESIZABLE, m_resizable);
            glfwWindowHint(GLFW_DECORATED, !m_fullscreen);
            glfwWindowHint(GLFW_VISIBLE, !m_fullscreen);
            glfwWindowHint(GLFW_FOCUSED, !m_fullscreen);
            glfwWindowHint(GLFW_MAXIMIZED, m_fullscreen);
            glfwWindowHint(GLFW_FLOATING, m_fullscreen);
            glfwWindowHint(GLFW_AUTO_ICONIFY, !m_fullscreen);
            glfwWindowHint(GLFW_CENTER_CURSOR, !m_fullscreen);
            glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, m_fullscreen);
            glfwWindowHint(GLFW_FOCUS_ON_SHOW, !m_fullscreen);
            glfwWindowHint(GLFW_SCALE_TO_MONITOR, m_fullscreen);
            glfwWindowHint(GLFW_RED_BITS, 8);
            glfwWindowHint(GLFW_GREEN_BITS, 8);
            glfwWindowHint(GLFW_BLUE_BITS, 8);
            glfwWindowHint(GLFW_ALPHA_BITS, 8);
            glfwWindowHint(GLFW_DEPTH_BITS, 24);
            glfwWindowHint(GLFW_STENCIL_BITS, 8);
            glfwWindowHint(GLFW_SAMPLES, 4);
            glfwWindowHint(GLFW_REFRESH_RATE, 60);
            glfwWindowHint(GLFW_SRGB_CAPABLE, true);
            glfwWindowHint(GLFW_DOUBLEBUFFER, true);
            m_window = glfwCreateWindow((int)m_size.x, (int)m_size.y, m_title.c_str(), nullptr, nullptr);
            if (!m_window) {
                std::cout << "Failed to create GLFW window" << std::endl;
                glfwTerminate();
                return;
            }

            glfwMakeContextCurrent(m_window);

            if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
                std::cout << "Failed to initialize GLAD" << std::endl;
                return;
            }

            glfwSetWindowUserPointer(m_window, this);
            glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
                auto* self = reinterpret_cast<IMPL(Window)*>(glfwGetWindowUserPointer(window));
                self->m_size.x = float(width);
                self->m_size.y = float(height);
                // if we do self->m_size = Vector2i(width, height); it will cause a heap corruption because of the way the Vector is implemented
                glViewport(0, 0, width, height);
            });

            glfwSetWindowPosCallback(m_window, [](GLFWwindow* window, int xpos, int ypos) {
                auto* self = reinterpret_cast<IMPL(Window)*>(glfwGetWindowUserPointer(window));
                self->m_position.x = float(xpos);
                self->m_position.y = float(ypos);
            });

            glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window) {
                auto* self = reinterpret_cast<IMPL(Window)*>(glfwGetWindowUserPointer(window));
                self->m_closed = true;
            });

            glfwSetWindowFocusCallback(m_window, [](GLFWwindow* window, int focused) {
                auto* self = reinterpret_cast<IMPL(Window)*>(glfwGetWindowUserPointer(window));
                if (focused) {
                    glfwSetInputMode(window, GLFW_CURSOR, self->m_cursor ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED);
                }
            });

            glfwSetWindowIconifyCallback(m_window, [](GLFWwindow* window, int iconified) {
                if (iconified) {
                    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
                }
            });

            glfwSetWindowMaximizeCallback(m_window, [](GLFWwindow* window, int maximized) {
                auto* self = reinterpret_cast<IMPL(Window)*>(glfwGetWindowUserPointer(window));
                if (maximized) {
                    glfwSetInputMode(window, GLFW_CURSOR, self->m_cursor ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED);
                }
            });

            glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
                auto* self = reinterpret_cast<IMPL(Window)*>(glfwGetWindowUserPointer(window));
                self->m_size.x = float(width);
                self->m_size.y = float(height);
                glViewport(0, 0, width, height);
            });

            glfwSetWindowContentScaleCallback(m_window, [](GLFWwindow* window, float xscale, float yscale) {
                auto* self = reinterpret_cast<IMPL(Window)*>(glfwGetWindowUserPointer(window));
                self->m_size.x = float(int(float(self->m_size.x) * xscale));
                self->m_size.y = float(int(float(self->m_size.y) * yscale));
                glViewport(0, 0, self->m_size.x, self->m_size.y);
            });
        }

    public:
        IMPL(Window)(Vector2i  size, std::string  title, bool resizable, bool fullscreen) :
            m_size(std::move(size)),
            m_title(std::move(title)),
            m_resizable(resizable),
            m_fullscreen(fullscreen),
            m_cursor(true),
            m_closed(false),
            m_clearColor(0.0f, 0.0f, 0.0f, 1.0f),
            m_window(nullptr),
            m_position(0, 0),
            m_vsync(true) {
            init();
        }
        ~IMPL(Window)() {
            destroy();
        }

        void clear() {
            glClearColor(m_clearColor.r(), m_clearColor.g(), m_clearColor.b(), m_clearColor.a());
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        static void update() {
            glfwPollEvents();
        }
        void swapBuffers() {
            glfwSwapBuffers(m_window);
        }
        void close() {
            glfwSetWindowShouldClose(m_window, true);
        }
        void destroy() {
            glfwDestroyWindow(m_window);
            glfwTerminate();
        }
        bool shouldClose() {
            return glfwWindowShouldClose(m_window);
        }

        // setters
        void setClearColor(const Color& color) {
            m_clearColor = color;
        }
        void setTitle(const std::string& title) {
            m_title = title;
            glfwSetWindowTitle(m_window, m_title.c_str());
        }
        void setSize(const Vector2i& size) {
            m_size = size;
            glfwSetWindowSize(m_window, m_size.x, m_size.y);
        }
        void setPosition(const Vector2i& position) {
            m_position = position;
            glfwSetWindowPos(m_window, m_position.x, m_position.y);
        }
        void setCursor(bool cursor) {
            m_cursor = cursor;
            glfwSetInputMode(m_window, GLFW_CURSOR, m_cursor ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED);
        }
        void setFullscreen(bool fullscreen) {
            m_fullscreen = fullscreen;
            glfwSetWindowMonitor(m_window, m_fullscreen ? glfwGetPrimaryMonitor() : nullptr, 0, 0, (int)m_size.x, (int)m_size.y, 0);
        }
        void setVsync(bool vsync) {
            m_vsync = vsync;
            glfwSwapInterval(m_vsync ? 1 : 0);
        }

        // getters
        [[nodiscard]] const Color& getClearColor() const {
            return m_clearColor;
        }
        [[nodiscard]] const std::string& getTitle() const {
            return m_title;
        }
        [[nodiscard]] const Vector2i& getSize() const {
            return m_size;
        }
        [[nodiscard]] const Vector2i& getPosition() const {
            return m_position;
        }
        [[nodiscard]] bool getCursor() const {
            return m_cursor;
        }
        [[nodiscard]] bool getFullscreen() const {
            return m_fullscreen;
        }
        [[nodiscard]] bool getVsync() const {
            return m_vsync;
        }
        // TODO: setup an event system
    };

    Window::Window(const std::string& title, const Vector2i& size, bool resizable, bool fullscreen) {
        m_impl = new IMPL(Window)(size, title, resizable, fullscreen);
    }
    Window::Window(const std::string& title, int width, int height, bool resizable, bool fullscreen) {
        m_impl = new IMPL(Window)(Vector2i(width, height), title, resizable, fullscreen);
    }

    IMPL(Window)* impl(Window* window) {
        return reinterpret_cast<IMPL(Window)*>(window->getImplWindow());
    }

    Window::~Window() {
        impl(this)->destroy();
        delete impl(this);
    }
    void Window::update() {
        IMPL(Window)::update();
    }

    void Window::clear() {
        impl(this)->clear();
    }

    void Window::render() {
        impl(this)->swapBuffers();
    }

    void Window::close() {
        impl(this)->close();
    }

    bool Window::closed() {
        return impl(this)->shouldClose();
    }

    void Window::setClearColor(const Color& color) {
        impl(this)->setClearColor(color);
    }

    void Window::setTitle(const std::string& title) {
        impl(this)->setTitle(title);
    }

    void Window::setSize(const Vector2i& size) {
        impl(this)->setSize(size);
    }

    void Window::setSize(int width, int height) {
        impl(this)->setSize(Vector2i(width, height));
    }

    const Vector2i& Window::getSize() {
        return impl(this)->getSize();
    }

    const std::string& Window::getTitle() {
        return impl(this)->getTitle();
    }

    void* Window::getImplWindow() {
        return m_impl;
    }
}