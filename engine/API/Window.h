#pragma once
#include <API/engineHeader.h>

#include "Vector2i.h"
#include "Color.h"

/*
 * Window Usage:
 * Window window("Title", 800, 600);
 * while (!window.closed()) {
 *    window.update();
 *    window.clear();
 *    // Draw stuff
 *    window.render();
 * }
 */

namespace Engine {
    std::string engineBackend();

    class Window {
    private:
        // pointer to an implementation of the window.
        // This is used to make the window cross-platform/cross-backend.
        // The implementation is defined in the backend.
        void* m_impl;


    public:
        Window(const std::string& title, int width, int height, bool resizable=true, bool fullscreen=false);

        Window(const std::string& title, const Vector2i& size, bool resizable=true, bool fullscreen=false);

        ~Window();

        void update();

        [[nodiscard]] bool closed();

        void close();

        void clear();

        void render();

        void setClearColor(const Color& color);

        void setTitle(const std::string& title);

        void setSize(const Vector2i& size);

        void setSize(int width, int height);

        [[nodiscard]] const Vector2i& getSize();

        [[nodiscard]] const std::string& getTitle();

        void* getImplWindow();
    };
}