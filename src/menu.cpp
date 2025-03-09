#include "../include/menu.h"
#include <raylib.h>

MENU::MENU()
{
    background = LoadTexture("../graphics/background2.png");
}

MENU::~MENU()
{
    UnloadTexture(background);
}

void MENU::draw()
{
    DrawTexture(background, 0, 0, WHITE);
    start_button.draw();
    exit_button.draw();
}

void MENU::update(bool& menu_open, Vector2 mouse_position, bool mouse_pressed)
{
    if(menu_open)
    {
        if(exit_button.is_pressed(mouse_position, mouse_pressed))
        {
            game_running = false;
        }
        if(start_button.is_pressed(mouse_position, mouse_pressed))
        {
            menu_open = false; 
        }
    }
    
}
