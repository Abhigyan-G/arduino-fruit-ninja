//#include "game.h"
#include "../include/game.h"
#include <cstdio>
#include <raylib.h>

#if defined (_WIN32) || defined(_WIN64)
    //for serial ports above "COM9", we must use this extended syntax of "\\.\COMx".
    //also works for COM0 to COM9.
    //https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilea?redirectedfrom=MSDN#communications-resources
    #define SERIAL_PORT "\\\\.\\COM1"
#endif
#if defined (__linux__) || defined(__APPLE__)
    #define SERIAL_PORT "/dev/ttyUSB0"
#endif

Game::Game()
{
    //load textures
    // background = LoadTexture("/graphics/background.jpg");
    // menu_background = LoadTexture("../graphics/background2.png");
    // start_button = LoadTexture("../graphics/start_button.png");
    // exit_button = LoadTexture("../graphics/exit_button.png");
    printf("Program Start");


    game_running = true;
    paused = true;
    read_serial = 1;
    errorOpening = serial.openDevice(SERIAL_PORT, 115200);
    x = 0; y = 0;
    if (errorOpening!=1)
    {
        printf("Couldn't Connect to %s\n", SERIAL_PORT);
        read_serial = false;
    }
    printf ("Successful connection to %s\n", SERIAL_PORT);
}

Game::~Game()
{
    //unload textures

    // UnloadImage(background_image);
    UnloadTexture(background);
    // UnloadTexture(background);
    // UnloadTexture(menu_background);
    // UnloadTexture(start_button);
    // UnloadTexture(exit_button);




    //close serial port
    serial.closeDevice();
}

void Game::draw()
{
    // if(paused)
    // {
    //     Menu.draw();
    // }
    //
    if(paused)
    {
        //draw menu background
        DrawTexture(background, 0, 0, WHITE);
    }

    if(!paused)
    {
        //draw game background
        // DrawTexture(background, 0, 0, WHITE);


        //draw cursor
        if(cursor.x < 0)
            cursor.x = 0;
        else if (cursor.x > WINDOWWIDTH) 
        {
            cursor.x = WINDOWWIDTH;
        }
        if(cursor.y < 0)
            cursor.y = 0;
        else if (cursor.y > WINDOWHEIGHT) 
        {
            cursor.y = WINDOWHEIGHT;
        }
        cursor.draw();
    }


}

void Game::update()
{
    //get mouse positon and menu functions
    mouse_pos = GetMousePosition();
    mouse_pressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);


    //read serial data form arduino
    if (read_serial) 
    {
        // Read the string
        serial.readString(buffer, '\n', 32, 2000);
        printf("String read: %s\n", buffer);       
        str_buffer = buffer;
        temp = str_buffer.find("A");
        x = std::stoi(str_buffer.substr(0, temp));
        y = std::stoi(str_buffer.substr(temp + 1, 10));
        std::cout<<x<<" "<<y<<"\n";
    }



    // Menu.update(paused, mouse_pos, mouse_pressed); 



    if(IsKeyPressed(KEY_P))
    {
        if(paused)
        {
            cursor.x = 500;
            cursor.y = 400;
        }
        paused = paused ? 0 : 1;
        
    }









    if(!paused)
    {

        //update cursor acceleration value
        

        cursor.accelerationx = y;
        cursor.accelerationy = -x;



        cursor.update();


    }

}
