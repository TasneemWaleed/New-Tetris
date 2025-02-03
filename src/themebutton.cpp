#include "themebutton.hpp"

ThemeButton::ThemeButton(const char *imagePath, Vector2 imagePosition, float scale)
{
    Image image = LoadImage(imagePath);
    int originalWidth = image.width;
    int originalHeight = image.height;

    int newWidth = static_cast<int>(originalWidth * scale);
    int newHeigth = static_cast<int>(originalHeight * scale);

    ImageResize(&image, newWidth, newHeigth);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    position = imagePosition;
}

ThemeButton::~ThemeButton()
{
    UnloadTexture(texture);
}

void ThemeButton::Draw()
{
    DrawTextureV(texture, position, WHITE);
}

bool ThemeButton::isPressed(Vector2 mousePos, bool mousePressed)
{
    Rectangle rect = {position.x, position.y, static_cast<float>(texture.width), static_cast<float>(texture.height)};

    if(CheckCollisionPointRec(mousePos,rect) && mousePressed)
    {
        return true;
    }
    return false;
}
