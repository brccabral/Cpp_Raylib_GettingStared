#include <raylib.h>

int main()
{
    float posX = 0;

    InitWindow(800, 450, "raylib - basic window");

    SetTargetFPS(144);

    while (!WindowShouldClose())
    {
        posX += GetFrameTime() * 100;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        DrawRectangle(posX, 100, 100, 100, BLUE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
