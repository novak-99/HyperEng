#ifndef VECTOR_HPP
#define VECTOR_HPP


namespace HyperEngine{
    class Vector3{
        public:
            Vector3(int i, int j, int k);
            int getIComponent();
            int getJComponent();
            int getKComponent();

            void invert();
            float magnitude() const;
            float squareMagnitude() const;

            void normalize();
            Vector3 hadamardProduct(const Vector3& v) const;
            Vector3 crossProduct(const Vector3& v) const; 

            Vector3 operator+(const Vector3& v1, const Vector3& v2);
            Vector3 operator-(const Vector3& v1, const Vector3& v2);

            void operator+=(Vector3& v);
            void operator-=(Vector3& v);

            float operator*(const Vector3& v1, const Vector3& v2);
            
            Vector3 operator*(const Vector3& v1, float s);
            Vector3 operator/(const Vector3& v1, float s);

            Vector3 operator*=(float s);
            Vector3 operator/=(float s);

            Vector3 operator%(const Vector3& v);
            Vector3 operator%=(const Vector3& v);

        private:
            int i, j, k; 

    };

}

#endif // VECTOR_HPP