/****************************************************
Name: Rowan Rollman
Date: 7 March 2021
Problem Number: 3
Hours sent solving the problem: 48
Instructor: Komogortsev, TSU
*****************************************************/

// This is driver's code


#ifdef linux
#define LINUX true
#define WINDOWS false
#endif

#ifdef __CYGWIN32__
#define LINUX false
#define WINDOWS true
#endif


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>

#include "life.h"

const char FILE_NAME[] = "glider_gun_fight.txt";

using namespace std;

const int NUM_GENERATIONS = 10; //set to a smaller number for debugging

int main()
{
    populateWorld(FILE_NAME);
        
    showWorld();

    for (int iteration = 0; iteration < NUM_GENERATIONS; iteration++)
    {

        if (WINDOWS)
            system("cmd.exe /c cls"); //Windows only
        else
           system("clear"); //Linux only
        iterateGeneration();
        showWorld();
    }
    if (WINDOWS)
        system("cmd.exe /c PAUSE");
    return 0;
}

