#include "../include/cursor.h"
#include <raylib.h>
// #include <iostream>


Cursor::Cursor()
{
    cursor_color = RED;
    x = 500;
    y = 500;
    accelerationx = 0;
    accelerationy = 0;
    decceleration = 1;
    velocityx = 0;
    velocityy = 0;
    max_acceleration = 500;
    max_velocity = 200;
}

Cursor::~Cursor()
{
    x = 0;
    y = 0;
}

void Cursor::draw()
{
    DrawCircle(x, y, 15, cursor_color);
}

/*
void Cursor::update()
{
    velocityx = velocityx + accelerationx;
    velocityy = velocityy + accelerationy;
    x = x + velocityx;
    y = y + velocityy;
    // if(velocityx != 0)
    //     velocityx = velocityx + (velocityx < 0 ? decceleration : -decceleration);
    // if(velocityy != 0)    
    //     velocityy = velocityy + (velocityy < 0 ? decceleration : -decceleration);
    

    std::cout<<x<<" "<<y<<" velocity"<<velocityx<<" "<<velocityy<<"\nacceleration";
    std::cout<<accelerationx<<" "<<accelerationy<<"\n";

    if(velocityx < 0 || velocityy > -max_velocity)
    {
        velocityx = velocityx + velocityx/10;
        velocityx++;
    }
    else if(velocityx > 0 || velocityx < max_velocity) 
    {
        velocityx = velocityx - velocityx/10;
        velocityx --;
    }
    if(velocityy < 0 || velocityy > -max_velocity)
    {
        velocityy = velocityy + velocityy/10;
        velocityy ++;
    }
    else if(velocityy > 0 || velocityx < max_velocity) 
    {
        velocityy = velocityy - velocityy/10;
        velocityy --;
    }



    // check if greater than max value
    if(accelerationx > max_acceleration)
    {
        accelerationx = max_acceleration;
    }
    if(accelerationy > max_acceleration)
    {
        accelerationy = max_acceleration;
    }



    if(velocityx > max_velocity)
    {
        velocityx = max_velocity;
    }
    if(velocityy > max_velocity)
    {
        velocityy = max_velocity;
    }
}*/


void Cursor::update()
{
    x += accelerationx;
    y += accelerationy;
}
