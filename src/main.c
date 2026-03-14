#include "raylib.h"

int main(void)
{
    // Init
    const int screenWidth = 600;
    const int screenHeight = 400;
    InitWindow(screenWidth, screenHeight, "EchoBreak Rasterization Tool");
    SetTargetFPS(60);

    // Main
    while (!WindowShouldClose())
    {
        // Update
        

        // Draw
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTriangleLines((Vector2){screenWidth / 4.0f * 3.0f, 160.0f},
                          (Vector2){screenWidth / 4.0f * 3.0f - 20.0f, 230.0f},
                          (Vector2){screenWidth / 4.0f * 3.0f + 20.0f, 230.0f}, PURPLE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}