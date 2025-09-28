#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
    public:
    double e[3];

    vec3() : e{0,0,0} {}
    vec3(double e1, double e2, double e3) : e{e1, e2, e3} {}

    double x() const {return e[0];}
    double y() const {return e[1];}
    double z() const {return e[2];}

    vec3 operator-() const {return vec3{-e[0], -e[1], -e[2]};}
    double operator[] (int i) const {return e[i];}
    double& operator[] (int i) {return e[i];}

    vec3& operator+=(const vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        
        return *this;
    }

    vec3& operator*=(double scalar){
        e[0] *= scalar;
        e[1] *= scalar;
        e[2] *= scalar;

        return *this;
    }

    vec3& operator/=(double t){
        return *this *= 1/t;
    }

    double lenthSquared() const {return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];}
    double length() const {return sqrt(lenthSquared());}

};

using point3 = vec3;

//Vector utility function
inline vec3 operator+(const vec3 &u, const vec3 &v){
    return vec3(u[0] + v[0], u[1] + v[1], u[2] + v[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v){
    return vec3(u[0] - v[0], u[1] - v[1], u[2] - v[2]);
}

inline vec3 operator*(const double &t, const vec3 &v){
    return vec3(t * v[0], t * v[1], t * v[2]);
}

inline vec3 operator*(const vec3 &v, const double &t){
    return t * v;
}

inline vec3 operator/(const vec3 &v, const double &t){
    return 1/t * v;
}

inline vec3 unit_vector(const vec3 &v){
    return v / v.length();
}


inline double dot(const vec3 &u, const vec3 &v){
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v){
    return vec3(u[1]*u[2] - u[2]*v[1],
                u[2]*v[0] - u[0]*v[2],
                u[0]*v[1] - u[1]*v[0]);
}

#endif