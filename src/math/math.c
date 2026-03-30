#include "math.h"
#include "raylib.h"
#include <math.h>

#define world_up (Vector3){0, 1, 0}

static inline Vector3 normalize(Vector3 v)
{
    float w = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);

    Vector3 res = {
        v.x / w,
        v.y / w,
        v.z / w
    };

    return res;
}

static inline Vector3 cross(Vector3 a, Vector3 b) 
{
    return (Vector3){
        a.y * b.z - a.z * b.y,  
        a.z * b.x - a.x * b.z,  
        a.x * b.y - a.y * b.x   
    };
}

static inline float dot(Vector3 a, Vector3 b) 
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

Vector2 projectPoint(Vector3 p, Vector3 cam, float yaw, float pitch, int w, int h, float f)
{
    // world -> camera
    Vector3 pc = {
        p.x - cam.x,
        p.y - cam.y,
        p.z - cam.z};

    Vector3 forward = {
        cos(pitch) * sin(yaw),
        sin(pitch),
        cos(pitch) * cos(yaw)
    };

    Vector3 right = normalize(cross(forward, world_up));
    Vector3 up = cross(right, forward);

    pc.x = dot(pc, right);
    pc.y = dot(pc, up);
    pc.z = dot(pc, forward);
        
        // perspective
    Vector2 proj = {
        pc.x / pc.z,
        pc.y / pc.z};
            
            // screen
    Vector2 screen = {
            proj.x * f + w / 2.f,
            -proj.y * f + h / 2.f};
                
    return screen;
}