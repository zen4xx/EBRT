#include "math/math.h" // raylib is also here
#include "raylib.h"

int main(void)
{
    // Init
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "EchoBreak Rasterization Tool");
    SetTargetFPS(60);

    // Main
    while (!WindowShouldClose())
    {
        // Update
        Vector3 cam = {0.f, 0.f, 0.0f};
        float pitch, yaw = 0.f;
        
        Vector2 p1 = projectPoint((Vector3){0.f, 100.f, 3.f}, cam, yaw, pitch, screenWidth, screenHeight, 1.42);
        Vector2 p2 = projectPoint((Vector3){-100.f, 0.f, 3.f}, cam, yaw, pitch, screenWidth, screenHeight, 1.42);
        Vector2 p3 = projectPoint((Vector3){100.f, 0.f, 3.f}, cam, yaw, pitch, screenWidth, screenHeight, 1.42);
            

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTriangleLines(p3, p2, p1, PURPLE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}