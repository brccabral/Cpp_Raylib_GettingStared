#include <raylib.h>

int main()
{
    Texture2D sprite; // need to load after InitWindow because InitWindow loads the graphics libraries
    Sound sound; // need to InitAudioDevice

    InitWindow(800, 450, "raylib - basic window");
    SetTargetFPS(144);
    InitAudioDevice();

    sprite = LoadTexture("resources/sprite.png");
    float posX = -sprite.width;

    sound = LoadSound("resources/sound.ogg");

    while (!WindowShouldClose())
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            PlaySound(sound);
        }

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
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
