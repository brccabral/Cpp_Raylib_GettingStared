#include <raylib.h>

int main()
{
    Texture2D sprite; // need to load after InitWindow because InitWindow loads the graphics libraries
    Sound sound; // need to InitAudioDevice
    Music music;

    InitWindow(800, 450, "raylib - basic window");
    SetTargetFPS(144);
    InitAudioDevice();

    sprite = LoadTexture("resources/sprite.png");
    float posX = -sprite.width;

    sound = LoadSound("resources/sound.ogg");
    music = LoadMusicStream("resources/music.mp3");
    // PlayMusicStream(music);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Rectangle spriteRec = {posX, 10, static_cast<float>(sprite.width), static_cast<float>(sprite.height)};
            if (CheckCollisionPointRec(GetMousePosition(), spriteRec))
            {
                PlaySound(sound);
            }
        }

        posX += GetFrameTime() * 300.0f;
        if (posX > 800)
        {
            posX = -sprite.width;
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            StopMusicStream(music);
            PlayMusicStream(music);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawTexture(sprite, posX, 10, WHITE);

        EndDrawing();
    }
    StopMusicStream(music);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
