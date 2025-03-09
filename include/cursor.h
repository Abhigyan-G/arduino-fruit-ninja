#pragma once

#include <raylib.h>





class Cursor
{
    public:
        int x, y;
        int accelerationx;
        int accelerationy;

    private:
        Color cursor_color;
        int velocityx;
        int velocityy;
        int decceleration;
        int max_acceleration;
        int max_velocity;

    public:
        Cursor();
        ~Cursor();
        void draw();
        void update();
};
