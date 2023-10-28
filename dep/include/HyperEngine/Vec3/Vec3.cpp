#include "Vec3.hpp"
#include "Constants/Constants.hpp"
#include <cmath>

#include <iostream>

namespace HyperEngine{
    Vec3::Vec3(){
        (*this) = zeroVector;
    }

    Vec3::Vec3(float i, float j, float k){
        this->i = i;
        this->j = j;
        this->k = k;
    }

    float Vec3::getIComponent() { return i; }

    void Vec3::setIComponent(float i){ this->i = i; }

    float Vec3::getJComponent(){ return j; }

    void Vec3::setJComponent(float j){ this->j = j; }

    float Vec3::getKComponent() { return k; }

    void Vec3::getKComponent(float k){ this->k = k; }

    // void Vec3::operator=(const Vec3& v){
    //     i = v.i; 
    //     j = v.j; 
    //     k = v.k;
    // }

    Vec3 Vec3::operator+(const Vec3& v){
        return Vec3(
            i + v.i,
            j + v.j, 
            k + v.k
        );
    }

    void Vec3::operator+=(const Vec3& v){
        i += v.i; 
        j += v.j; 
        k += v.k;
    }

    Vec3 Vec3::operator-(const Vec3& v){
        return Vec3(
            i - v.i,
            j - v.j, 
            k - v.k
        );
    }

    void Vec3::operator-=(const Vec3& v){
        i -= v.i; 
        j -= v.j; 
        k -= v.k;
    }

    float Vec3::operator*(const Vec3& v){
        return i * v.i + j * v.j + k * v.k;
    }

    Vec3 Vec3::operator*(float s){
        return Vec3(
            i * s,
            j * s, 
            k * s
        );
    }

    void Vec3::operator*=(float s){
        i *= s; 
        j *= s; 
        k *= s;
    }

    Vec3 Vec3::operator/(float s){
        return Vec3(
            i / s,
            j / s, 
            k / s
        );
    }

    void Vec3::operator/=(float s){
        i /= s; 
        j /= s; 
        k /= s;
    }

    float Vec3::magnitude(){
        return std::sqrt(i*i + j*j + k*k);
    }

    Vec3 Vec3::normalize(){
        // add divide
        return (*this) / magnitude();
    }

    void Vec3::hadamard(const Vec3& v){
        i *= v.i; 
        j *= v.j; 
        k *= v.k;
    }

    void Vec3::print(){
        std::cout << i << " " << j << " " << k << "\n";
    }
}