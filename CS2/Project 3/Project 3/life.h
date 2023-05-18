/****************************************************
Name: Rowan Rollman
Date: 7 March 2021
Problem Number: 3
Hours sent solving the problem: 48
Instructor: Komogortsev, TSU
*****************************************************/

//This header file provides the prototypes of the function definitions
//for the project.

#ifndef life_h
#define life_h

#include <iostream>
#include <fstream>

using namespace std;

void populateWorld(const char * file);
void showWorld();
void iterateGeneration();
int countNeighbors(int x, int y);

#endif
