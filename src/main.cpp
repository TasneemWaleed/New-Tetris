#include <raylib.h>
#include "game.h"
#include "colors.h"
#include "themebutton.hpp"
#include <iostream>

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main() 
{
    InitWindow(500, 620, "raylib Tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf" , 64, 0, 0);

    ThemeButton themeButton{"Graphics/dblue1.png", {380, 570}, 0.10};

    Game game = Game();

    Color currentColor = darkPurple;

    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }

        Vector2 mousePosition = GetMousePosition();
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
        if(themeButton.isPressed(mousePosition, mousePressed))
        {
            std::cout << "Theme Button Works" << std::endl;
            currentColor = darkBlue;
        }
            
        BeginDrawing();
        ClearBackground(currentColor);
        DrawTextEx(font, "Score", {365, 15}, 38, 2 , WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2 , WHITE);
        DrawTextEx(font, "Themes", {350, 520}, 38, 2 , WHITE);
        if(game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2 , WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightPurple);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
    
        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 38, 2 , WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightPurple);
        DrawRectangleRounded({320, 560, 170, 280}, 0.3, 6, lightPurple);
        themeButton.Draw();
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}