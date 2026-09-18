//
// Created by addik on 17/09/2026.
//

#ifndef MOTIONLABENGINE_VECTOR_H
#define MOTIONLABENGINE_VECTOR_H
#include <cstddef>

namespace MotionLab::Maths {
    template<typename T, int n>
    class Vector {
    public:
        T axes[n];

        Vector() {
            for (std::size_t i = 0; i < n; i++) {
                axes[i] = T{};
            }
        }

        template<typename... Args>
        Vector(Args... args) : axes {static_cast<T>(args)...} {
            static_assert(sizeof... (Args) == n, "MotionLab::Maths::Vector: Wrong number of arguments!");
        }

        Vector<T, n> operator +(const Vector<T, n>& operand) {
            Vector<T, n> result;
            for (int i = 0; i < n; i++) {
                result.axes[i] = this->axes[i] + operand->axes[i];
            }
            return result;
        }

        Vector<T, n> operator -(const Vector<T, n>& operand) {
            Vector<T, n> result;
            for (int i = 0; i < n; i++) {
                result.axes[i] = this->axes[i] - operand->axes[i];
            }
            return result;
        }
    };

    template<typename T>
    class Vector2 : public Vector<T, 2> {
    public:
        Vector2() : Vector<T, 2>() {}

        template<typename... Args>
        Vector2(Args... args) : Vector<T, 2>(args...) {}

        T x() {
            return this->axes[0];
        }

        void setX(T value) {
            this->axes[0] = value;
        }

        T y() {
            return this->axes[1];
        }

        void setY(T value) {
            this->axes[1] = value;
        }
    };

    template <typename T>
    class Vector3 : public Vector<T, 3> {
        Vector3() : Vector<T, 3>() {}

        template<typename... Args>
        Vector3(Args... args) : Vector<T, 3>(args...) {}

        T x() {
            return this->axes[0];
        }

        void setX(T value) {
            this->axes[0] = value;
        }

        T y() {
            return this->axes[1];
        }

        void setY(T value) {
            this->axes[1] = value;
        }

        T z() {
            return this->axes[2];
        }

        void setZ(T value) {
            this->axes[2] = value;
        }
    };
}


#endif //MOTIONLABENGINE_VECTOR_H
