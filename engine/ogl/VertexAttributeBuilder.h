#pragma once
#include "oglHeader.h"

namespace Engine {
    class VertexAttributeBuilder {
    private:
        std::vector<int> attribs;

    public:

        template<typename... Args>
        explicit VertexAttributeBuilder(Args... attribs) {
            this->attribs = {(attribs)...};
        }

        void build() {
            unsigned int offset = 0;
            unsigned int stride = 0;
            for (unsigned int attrib : attribs) {
                stride += (int)attrib;
            }
            for (int i = 0; i < attribs.size(); i++) {
                glVertexAttribPointer(i, (int)attribs[i], GL_FLOAT, false, (int)stride * (int)sizeof(float), (const void*)(offset * sizeof(float)));
                glEnableVertexAttribArray(i);
                offset += attribs[i];
            }
        }

        void enable() {
            for (int i = 0; i < attribs.size(); i++) {
                glEnableVertexAttribArray(i);
            }
        }

        void disable() {
            for (int i = 0; i < attribs.size(); i++) {
                glDisableVertexAttribArray(i);
            }
        }

        unsigned int getSize() {
            unsigned int size = 0;
            for (unsigned int c : attribs) {
                size += c;
            }
            return size;
        }
    };
}