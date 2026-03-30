#include "math/math.h" // raylib is also here
#include "raylib.h"
#include <stdio.h>

int main(void)
{
    // Init
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "EchoBreak Rasterization Tool");
    SetTargetFPS(60);

    float pitch, yaw;
    pitch = yaw = 0.f;
    Vector3 cam = {0.f, 0.f, 0.0f};
    float focalLength = 1200.f;

    float cam_speed = 10.f;

    float rotation_speed = 0.02f;
    
    // Main
    while (!WindowShouldClose())
    {
        // Update

        if (IsKeyDown(KEY_RIGHT)) yaw -= rotation_speed;
        if (IsKeyDown(KEY_LEFT)) yaw += rotation_speed;
        if (IsKeyDown(KEY_DOWN)) pitch -= rotation_speed;
        if (IsKeyDown(KEY_UP)) pitch += rotation_speed;
        if (IsKeyDown(KEY_W)) cam.z += cam_speed;
        if (IsKeyDown(KEY_A)) cam.x += cam_speed;
        if (IsKeyDown(KEY_S)) cam.z -= cam_speed;
        if (IsKeyDown(KEY_D)) cam.x -= cam_speed;

        if (IsKeyDown(KEY_X)) { focalLength -= 1.f;  printf("focal length: %f\n", focalLength);}
        if (IsKeyDown(KEY_Z)) { focalLength += 1.f;  printf("focal length: %f\n", focalLength);}

        Vector2 p1 = projectPoint((Vector3){0.f, 100.f, 300.f}, cam, yaw, pitch, screenWidth, screenHeight, focalLength);
        Vector2 p2 = projectPoint((Vector3){-100.f, 0.f, 300.f}, cam, yaw, pitch, screenWidth, screenHeight, focalLength);
        Vector2 p3 = projectPoint((Vector3){100.f, 0.f, 300.f}, cam, yaw, pitch, screenWidth, screenHeight, focalLength);
            

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTriangleLines(p3, p2, p1, PURPLE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}