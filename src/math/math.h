#ifndef MATH_H
#define MATH_H

#include "raylib.h"
#include <math.h>

#define DO_NOT_DRAW -9999.f

static inline Vector3 Vector3Add(Vector3 a, Vector3 b) {
    return (Vector3){a.x + b.x, a.y + b.y, a.z + b.z};
}

static inline Vector3 Vector3Subtract(Vector3 a, Vector3 b) {
    return (Vector3){a.x - b.x, a.y - b.y, a.z - b.z};
}

static inline Vector3 Vector3Scale(Vector3 v, float scale) {
    return (Vector3){v.x * scale, v.y * scale, v.z * scale};
}

static inline float Clamp(float val, float min, float max) {
    return (val < min) ? min : (val > max) ? max : val;
}

static inline Vector3 normalize(Vector3 v) {
    float w = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    if (w == 0) return (Vector3){0, 0, 0};
    return (Vector3){v.x / w, v.y / w, v.z / w};
}

static inline Vector3 cross(Vector3 a, Vector3 b) {
    return (Vector3){
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

static inline float dot(Vector3 a, Vector3 b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

Vector2 projectPoint(Vector3 p, Vector3 cam, float yaw, float pitch, int w, int h, float f);

#endif