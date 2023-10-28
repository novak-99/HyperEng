#ifndef VEC3_HPP
#define VEC3_HPP

namespace HyperEngine{
    class Vec3{
        public:
            Vec3();
            Vec3(float i, float j, float k);

            float getIComponent();
            void setIComponent(float i);

            float getJComponent();
            void setJComponent(float j);

            float getKComponent();
            void getKComponent(float k);

            Vec3 operator+(const Vec3& v);
            void operator+=(const Vec3& v);

            Vec3 operator-(const Vec3& v);
            void operator-=(const Vec3& v);

            float operator*(const Vec3& v);

            Vec3 operator*(float s);
            void operator*=(float s);

            Vec3 operator/(float s);
            void operator/=(float s);

            float magnitude();

            Vec3 normalize();

            void hadamard(const Vec3& v);

            void print();


        private:
            float i; 
            float j; 
            float k; 


    };
}
#endif // VEC3_HPP