#include "math.h"

Vector2 projectPoint(Vector3 p, Vector3 cam, int w, int h, float f)
{
    // world -> camera
    Vector3 pc = {
        p.x - cam.x,
        p.y - cam.y,
        p.z - cam.z};
        
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