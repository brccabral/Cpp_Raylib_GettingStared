#include <raylib.h>

int main()
{
    Texture2D sprite; // need to load after InitWindow because InitWindow loads the graphics libraries

    InitWindow(800, 450, "raylib - basic window");
    SetTargetFPS(144);

    sprite = LoadTexture("resources/sprite.png");
    float posX = -sprite.width;

    while (!WindowShouldClose())
    {
        posX += GetFrameTime() * 300.0f;
        if (posX > 800)
        {
            posX = -sprite.width;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(sprite, posX, 10, WHITE);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
