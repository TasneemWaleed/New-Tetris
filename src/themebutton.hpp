#pragma once
#include <raylib.h>

class ThemeButton
{
    public:
        ThemeButton(const char* imagePath, Vector2 imagePosition, float scale);
        ~ThemeButton();
        void Draw();
        bool isPressed(Vector2 mousePos, bool mousePressed);
    private:  
        Texture2D texture;
        Vector2 position;
};