#include "math.h"
#include "raylib.h"
#include <math.h>

#define world_up (Vector3){0, 1, 0}

Vector2 projectPoint(Vector3 p, Vector3 cam, float yaw, float pitch, int w, int h, float f)
{
    Vector3 pc = { p.x - cam.x, p.y - cam.y, p.z - cam.z };

    Vector3 forward = {
        cosf(pitch) * sinf(yaw),
        sinf(pitch),
        cosf(pitch) * cosf(yaw)
    };

    Vector3 right = normalize(cross(world_up, forward));
    if (right.x == 0 && right.y == 0 && right.z == 0) {
        right = (Vector3){1, 0, 0}; 
    }
    
    Vector3 up = cross(forward, right);

    pc = (Vector3){ dot(pc, right), dot(pc, up), dot(pc, forward) };

    if (pc.z <= 0.1f) return (Vector2){DO_NOT_DRAW, DO_NOT_DRAW};

    float projX = pc.x / pc.z;
    float projY = pc.y / pc.z;

    return (Vector2){
        projX * f + w / 2.f,
        -projY * f + h / 2.f
    };
}