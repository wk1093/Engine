#include "oglHeader.h"
#include <API/Time.h>

namespace Engine {
    double getEngineTime() {
        return glfwGetTime();
    }
}