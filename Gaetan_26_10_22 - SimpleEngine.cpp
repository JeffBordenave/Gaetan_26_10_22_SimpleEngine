// Gaetan_26_10_22 - SimpleEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SDL.h>
#include "Log.h"
#include "Game.h"

int main(int argc, char** argv)
{
    auto& instance = Game::instance();
    bool isGameInit = instance.initialize();

    if (isGameInit) 
    {
        instance.load();
        instance.loop();
        instance.unload();
    }

    instance.close();
    return 0;
}