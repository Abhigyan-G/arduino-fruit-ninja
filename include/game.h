#pragma once
#include "serialib.h"
#include <string>
#include <cstdio>
#include <raylib.h>
#include "../include/cursor.h"
#include "../include/menu.h"

class Game
{
    public:
        Vector2 mouse_pos;
        bool mouse_pressed;
        bool paused;
        bool game_running;
        int WINDOWWIDTH = 1280, WINDOWHEIGHT = 800;
    private:
        Cursor cursor;
        // MENU Menu; 
        
        // Image background_image = LoadImage("/graphics/background2.png");    
        // Texture2D background = LoadTextureFromImage(background_image); 

        Texture2D background = LoadTexture("graphics/background2.png"); 
        // Texture2D background = LoadTexture("../graphics/background.jpg");
        // Texture2D menu_background = LoadTexture("../graphics/background2.png");
        // Texture2D start_button = LoadTexture("../graphics/start_button.png");
        // Texture2D exit_button = LoadTexture("../graphics/exit_button.png");



        
        bool read_serial;
        int x, y, temp;
        serialib serial;
        char errorOpening;
        char buffer[32];
        std::string str_buffer = "0", str_x, str_y;

    public:
        Game();
        ~Game();
        void draw();
        void update();
    private:
};
