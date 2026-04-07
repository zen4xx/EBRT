#include "math/math.h" // raylib is also here
#include "raylib.h"
#include <stdint.h>

static const Vector3 cubeVertices[8] = {
    {-1, -1, -1},  // 0: back-bottom-left
    { 1, -1, -1},  // 1: back-bottom-right
    { 1,  1, -1},  // 2: back-top-right
    {-1,  1, -1},  // 3: back-top-left
    {-1, -1,  1},  // 4: front-bottom-left
    { 1, -1,  1},  // 5: front-bottom-right
    { 1,  1,  1},  // 6: front-top-right
    {-1,  1,  1}   // 7: front-top-left
};

static const uint16_t cubeIndices[36] = {
    0,3,2, 0,2,1,  
    4,5,6, 4,6,7,  
    0,4,7, 0,7,3,  
    1,2,6, 1,6,5,  
    3,2,6, 3,6,7,  
    0,1,5, 0,5,4   
};


void drawCube(Vector3 position, Vector3 camera, float yaw, float pitch, int width, int height, float focalLength)
{
    Vector2 projected[8];
    
    for (int i = 0; i < 8; i++)
    {
        Vector3 worldVertex = {
            cubeVertices[i].x + position.x,
            cubeVertices[i].y + position.y,
            cubeVertices[i].z + position.z
        };
        
        projected[i] = projectPoint(worldVertex, camera, yaw, pitch, width, height, focalLength);
    }
    
    for (int i = 0; i < 12; i++)
    {
        int a = cubeIndices[i * 3 + 0];
        int b = cubeIndices[i * 3 + 1];
        int c = cubeIndices[i * 3 + 2];

        if (projected[a].x > -1000 && projected[a].x < width + 1000 &&
            projected[b].x > -1000 && projected[b].x < width + 1000)
        {
            DrawLine((int)projected[a].x, (int)projected[a].y, (int)projected[b].x, (int)projected[b].y, RED);
            DrawLine((int)projected[b].x, (int)projected[b].y, (int)projected[c].x, (int)projected[c].y, GREEN);
            DrawLine((int)projected[c].x, (int)projected[c].y, (int)projected[a].x, (int)projected[a].y, BLUE);
        }
    }
}

int main(void)
{
    // Init
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "EchoBreak Rasterization Tool");
    SetTargetFPS(60);

    float pitch, yaw;
    pitch = yaw = 0.f;
    Vector3 cam = {0.f, 1.6f, 0.0f};
    Vector3 cube_pos = {0, 0, 5};
    float focalLength = 500.f;

    float cam_speed = 0.5f;

    float rotation_speed = 0.05f;

    // Main
    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT)) yaw += rotation_speed;
        if (IsKeyDown(KEY_LEFT))  yaw -= rotation_speed;
        if (IsKeyDown(KEY_DOWN))  pitch -= rotation_speed;
        if (IsKeyDown(KEY_UP))    pitch += rotation_speed;

        pitch = Clamp(pitch, -PI/2 + 0.01f, PI/2 - 0.01f);
        
        if (yaw > PI * 2) yaw -= PI * 2;
        if (yaw < 0) yaw += PI * 2;

        Vector3 lookDirection = {
            cosf(pitch) * sinf(yaw),
            sinf(pitch),
            cosf(pitch) * cosf(yaw)
        };

        Vector3 moveForward = {
            sinf(yaw),  
            0.0f,
            cosf(yaw)
        };
        moveForward = normalize(moveForward);

        Vector3 moveRight = {
            sinf(yaw - PI/2), 
            0.0f,
            cosf(yaw - PI/2)
        };
        moveRight = normalize(moveRight);

        if (IsKeyDown(KEY_W)) cam = Vector3Add(cam, Vector3Scale(moveForward, cam_speed));
        if (IsKeyDown(KEY_S)) cam = Vector3Subtract(cam, Vector3Scale(moveForward, cam_speed));
        
        if (IsKeyDown(KEY_D)) cam = Vector3Subtract(cam, Vector3Scale(moveRight, cam_speed));
        if (IsKeyDown(KEY_A)) cam = Vector3Add(cam, Vector3Scale(moveRight, cam_speed));
        
        if (IsKeyDown(KEY_SPACE)) cam.y += cam_speed;
        if (IsKeyDown(KEY_LEFT_CONTROL)) cam.y -= cam_speed;

        BeginDrawing();
        ClearBackground(BLACK);

        drawCube(cube_pos, cam, yaw, pitch, screenWidth, screenHeight, focalLength);

        DrawText(TextFormat("Yaw: %.0f Pitch: %.0f", yaw * 180 / PI, pitch * 180 / PI), 10, 10, 20, GREEN);
        DrawText(TextFormat("Cam: (%.1f, %.1f, %.1f)", cam.x, cam.y, cam.z), 10, 30, 20, GREEN);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}