#include "Vector3.hpp"

namespace HyperEngine{

    Vector3::Vector3(int i, int j, int k){
        this.i = i; 
        this.j = j;
        this.k = k; 
    }

    int Vector3::getIComponent(){ return i; }

    int Vector3::getJComponent(){ return j; }

    int Vector3::getKComponent(){ return k; }

    void Vector3::invert(){
        i = -i; 
        j = -j; 
        k = -k; 
    }

    float Vector3::magnitude() const {
        return sqrtf(x*x + y*y + z*z);
    }

    float Vector3::squareMagnitude() const {
        return x*x + y*y + z*z;
    }

    void Vector3::normalize(){
        float d = magnitude();
        if(d > 0){
            (*this) *= (float)(1) / d; 
        }
    }


    Vector3 Vector3::hadamardProduct(Vector3& v) const{
        return Vector3(x * vector.x, y * vector.y, z * vector.z);
    }

    Vector3 Vector3::crossProduct(const Vector3& v) const{
        return Vector3(
            y*v.z - z*v.y, 
            z*v.x - x*v.z,
            x*v.y - y*v.x
        );
    }

    void Vector3::addScaledVector(const Vector3& v, float s){
        x += vector.x * s; 
        y += vector.y * s; 
        z += vector.z * s; 
    }

    Vector3 Vector3::operator+(const Vector3& v1, const Vector3& v2){
        Vector3 v3(
            v1->getIComponent() + v2->getIComponent(), 
            v1->getJComponent() + v2->getJComponent(),
            v1->getKComponent() + v2->getKComponent()
        ); 
        return v3; 
    }

    Vector3 Vector3::operator-(const Vector3& v1, const Vector3& v2){
        Vector3 v3(
            v1->getIComponent() - v2->getIComponent(), 
            v1->getJComponent() - v2->getJComponent(),
            v1->getKComponent() - v2->getKComponent()
        ); 
        return v3; 
    }

    void Vector3::operator*=(Vector3& v){
        x *= v->x; 
        y *= v->y;
        z *= v->z;
    }

    float Vector3::operator*(const Vector3& v1, const Vector3& v2){
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; 
    }

    Vector3 Vector3::operator*(const Vector3& v1, double s){
        Vector3 v2(
            v1->getIComponent() * s, 
            v1->getJComponent() * s,
            v1->getKComponent() * s
        ); 
        return v2;
    }

    Vector3 Vector3::operator/(const Vector3& v1, double s){
        Vector3 v2(
            v1->getIComponent() / s, 
            v1->getJComponent() / s,
            v1->getKComponent() / s,
        ); 
        return v2;
    }

    void Vector3::operator*=(float s){
        x *= s;
        y *= s; 
        z *= s;
    }

    void Vector3::operator/=(float s){
        x /= s;
        y /= s; 
        z /= s;
    }

    Vector3 Vector3::operator%(const Vector3& v){
        return crossProduct(v);
    }

    void Vector3::operator%=(const Vector3& v){
        (*this) = crossProduct(v);
    }

}