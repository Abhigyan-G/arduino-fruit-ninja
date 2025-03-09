#include <iostream>
#include <raylib.h>
// #include <game.h>
#include "../include/game.h"
//#include "serialib.h"
//#include <unistd.h>
//#include <cstdio>
//#include <string>


#if defined (_WIN32) || defined(_WIN64)
    //for serial ports above "COM9", we must use this extended syntax of "\\.\COMx".
    //also works for COM0 to COM9.
    //https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilea?redirectedfrom=MSDN#communications-resources
    #define SERIAL_PORT "\\\\.\\COM1"
#endif
#if defined (__linux__) || defined(__APPLE__)
    #define SERIAL_PORT "/dev/ttyUSB0"
#endif


int main( /*int argc, char *argv[]*/)
{
    // bool read_serial = 1;

    Game game;

    // // Serial object
    // serialib serial;

    // int WINDOWWIDTH = 1280, WINDOWHEIGHT = 800;
    InitWindow(game.WINDOWWIDTH, game.WINDOWHEIGHT, "Game");

    //window Colour
    Color window_color = {115, 245, 115, 255};
    
    std::cout<<"program start\n";


    //Target FPS
    SetTargetFPS(60);

    // // Connection to serial port
    // char errorOpening = serial.openDevice(SERIAL_PORT, 115200);

    // // Buffer string
    // char buffer[32] = "hello\n";

    // std::string str_buffer = "0", str_x, str_y;
    // int x, y;

    // int temp;


    // // If connection fails, return the error code otherwise, display a success message
    // if (errorOpening!=1) return errorOpening;
    // printf ("Successful connection to %s\n",SERIAL_PORT);

    while (!WindowShouldClose() && game.game_running) 
    {
    

        // if (read_serial) 
        // {
        //     // Read the string
        //     serial.readString(buffer, '\n', 14, 2000);
        //     printf("String read: %s\n", buffer);       
        //     str_buffer = buffer;
        //     temp = str_buffer.find("A");
        //     x = std::stoi(str_buffer.substr(0, temp));
        //     y = std::stoi(str_buffer.substr(temp + 1, 10));
        //     std::cout<<x<<" "<<y<<"\n";
        // }

        //update game logic

        game.update();









        //begin drawing
        BeginDrawing();
        ClearBackground(GRAY);

        game.draw();





        EndDrawing();




    }

    //close serial port
    // serial.closeDevice();

    CloseWindow();
    return 0 ;
}

