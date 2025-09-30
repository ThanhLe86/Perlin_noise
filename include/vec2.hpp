#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec2 {
    public:
    float e[2];

    vec2() : e{0,0} {}
    vec2(float e1, float e2) : e{e1, e2} {}

    float x() const {return e[0];}
    float y() const {return e[1];}

    vec2 operator-() const {return vec2{-e[0], -e[1]};}
    float operator[] (int i) const {return e[i];}
    float& operator[] (int i) {return e[i];}

    vec2& operator+=(const vec2& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        
        return *this;
    }

    vec2& operator*=(float scalar){
        e[0] *= scalar;
        e[1] *= scalar;

        return *this;
    }

    vec2& operator/=(float t){
        return *this *= 1/t;
    }

    float lenthSquared() const {return e[0]*e[0] + e[1]*e[1];}
    float length() const {return sqrt(lenthSquared());}

};

using point3 = vec2;

//Vector utility function
inline vec2 operator+(const vec2 &u, const vec2 &v){
    return vec2(u[0] + v[0], u[1] + v[1]);
}

inline vec2 operator-(const vec2 &u, const vec2 &v){
    return vec2(u[0] - v[0], u[1] - v[1]);
}

inline vec2 operator*(const float &t, const vec2 &v){
    return vec2(t * v[0], t * v[1]);
}

inline vec2 operator*(const vec2 &v, const float &t){
    return t * v;
}

inline vec2 operator/(const vec2 &v, const float &t){
    return 1/t * v;
}

inline vec2 unit_vector(const vec2 &v){
    return v / v.length();
}


inline float dot(const vec2 &u, const vec2 &v){
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1];
}

inline vec2 cross(const vec2 &u, const vec2 &v){
    return vec2(u[1]*u[2] - u[2]*v[1],
                u[2]*v[0] - u[0]*v[2]);
}

#endif