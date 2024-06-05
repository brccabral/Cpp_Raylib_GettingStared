#include <raylib.h>

int main()
{
    Texture2D sprite; // need to load after InitWindow because InitWindow loads the graphics libraries

    InitWindow(800, 450, "raylib - basic window");
    SetTargetFPS(144);

    sprite = LoadTexture("resources/sprite.png");

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(sprite, 10, 10, WHITE);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
