#pragma once
#include <raylib.h>

#include "../include/button.h"

class MENU
{
    public:
        bool game_running = 1;
    private:
        Texture2D background;
        Button start_button{"../graphics/start_button.png", {540, 250}, 0.65f};
        Button exit_button{"../graphics/exit_button.png", {540, 450}, 0.65f};
    public:
        MENU();
        ~MENU();
        void draw();
        void update(bool& menu_open, Vector2 mouse_position, bool mouse_pressed);
};
