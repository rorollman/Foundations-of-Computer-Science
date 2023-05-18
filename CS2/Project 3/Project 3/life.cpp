/****************************************************
Name: Rowan Rollman
Date: 7 March 2021
Problem Number: 3
Hours sent solving the problem: 48
Instructor: Komogortsev, TSU
*****************************************************/

//This file provides the implementation of the life.h header file.


#include <iostream>
#include <fstream>

#include "life.h"

using namespace std;

//GLOBAL VARIABLES

int ROWS;         //stores the number of rows in the grid
int COLUMNS;      //stores the number of cols in the grid
char ** newGrid;

//This function reads input file for subsequent prosessing (use get() 3 times,
//first to get rows, second to get cols, and last to write to grid.)
void populateWorld (const char * file)
{
    ifstream inFile;
    char temp;
    int rowCount=0;
    int colCount=0;
    
    //first time opening to get rowcount
    inFile.open("glider_gun_fight.txt");
    if (!inFile) {
        cout << "File could not be opened.\n";
        return;
    }
    inFile.get(temp);
    rowCount++;
    while (!inFile.eof()) {
        inFile.get(temp);
        if (temp == '\n') {
            rowCount++;
        }
    }
    inFile.close();
    //second time opening to get colcount
    inFile.open("glider_gun_fight.txt");
    if (!inFile) {
        cout << "File could not be opened.\n";
        return;
    }
    inFile.get(temp);
    colCount++;
    while (temp != '\n') {
        inFile.get(temp);
        colCount++;
    }
    
    inFile.close();

    ROWS = rowCount;
    COLUMNS = colCount;
    
    
    //third time opening to write to array grid
    inFile.open("glider_gun_fight.txt");
    //creating 2d dynamic array with size of
    grid = new char * [ROWS];
    for (int i=0; i<ROWS; i++) {
        grid[i] = new char [COLUMNS];
    }
    //writing array to grid
    while (!inFile.eof()) {
        for (int i=0; i<ROWS; i++) {
            for (int j=0; j<COLUMNS; j++) {
                inFile.get(grid[i][j]);
                }
            }
        }
    //writing grid to tempFile to store it
    ofstream outFile;
    outFile.open("tempFile.txt");
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLUMNS; j++) {
            outFile << grid[i][j];
        }
    }
    
    outFile.close();
    inFile.close();

}

//This function outputs the grid for current generation (read grid from tempFile
//go through each row, and print out each col, then move down another row to
//continue printing out the grid
void showWorld ()
{
    ifstream inFile;
    inFile.open("tempFile.txt");

    //displaying grid
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLUMNS; j++) {
            inFile.get(grid[i][j]);
            cout << grid[i][j];
            }
        }
    inFile.close();

}

//This function creats new generation grid from the old generation grid
//(open tempFile, get new row and col count, check neighbors to see who
//changes, then write newGrid to tempFile)
void iterateGeneration ()
{
    //doing this again to get new grid dimensions
    ifstream inFile;
    char temp;
    int rowCount=0;
    int colCount=0;
    inFile.open("tempFile.txt");
    
    inFile.get(temp);
    rowCount++;
    while (!inFile.eof()) {
        inFile.get(temp);
        if (temp == '\n') {
            rowCount++;
        }
    }
    inFile.close();
    //second time opening to get colcount
    inFile.open("glider_gun_fight.txt");
    if (!inFile) {
        cout << "File could not be opened.\n";
        return;
    }
    inFile.get(temp);
    colCount++;
    while (temp != '\n') {
        inFile.get(temp);
        colCount++;
    }
    
    inFile.close();
    ROWS = rowCount;
    COLUMNS = colCount;
    
    //creating newGrid dynamic array
    newGrid = new char * [ROWS];
    for (int i=0; i<ROWS; i++) {
        newGrid[i] = new char [COLUMNS];
    }
    //determing
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLUMNS; j++) {
            int countLives = countNeighbors(i, j);
            
            if (newGrid[i][j] == 1 && countLives < 2) {
                newGrid[i][j] = 0;
            }
            else if (newGrid[i][j] == 1 && countLives == 2){
                newGrid[i][j] = 1;
            }
            else if (newGrid[i][j] == 1 && countLives == 3){
                newGrid[i][j] = 1;
            }
            else if (newGrid[i][j] == 0 && countLives == 3){
                newGrid[i][j] = 1;
            }
            else if (newGrid[i][j] == 1 && countLives > 3){
                newGrid[i][j] = 0;
            }
        }
    }
    ofstream outFile;
    outFile.open("tempFile.txt");
    
    //writing newGrid to tempFile
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLUMNS; j++) {
            outFile << newGrid[i][j];
        }
    }
    outFile.close();
    //deallocating newGrid
    for (int i=0; i<ROWS; i++) {
         delete [] newGrid[i];
     }
     delete [] newGrid;
}

int countNeighbors(int x, int y)
{
    int neighbors = 8; //max num of neighbors for any one cell
    //checking all the neighbors around cell (x,y)
    if ((x-1) >= 0 && (y-1) >= 0) {
        if (grid[x-1][y-1] == 0) {
            neighbors--;
        }
    }
    else {
        neighbors--;
    }
    if ((x-1) >= 0) {
        if (grid[x-1][y] == 0) {
            neighbors--;
        }
    }
    else {
        neighbors--;
    }
    if ((x-1) >= 0 && (y+1) < COLUMNS) {
        if (grid[x-1][y+1] == 0) {
            neighbors--;
        }
    }
    else {
        neighbors--;
    }
    if ((y-1) >= 0) {
        if (grid[x][y-1] == 0) {
            neighbors--;
        }
    }
    else {
        neighbors--;
    }
    if ((y+1) < COLUMNS) {
        if (grid[x][y+1] == 0) {
            neighbors--;
        }
    }
    else {
        neighbors--;
    }
    if ((x+1) < ROWS && (y-1) >= 0) {
        if (grid[x+1][y-1] == 0) {
            neighbors--;
        }
    }
    else {
        neighbors--;
    }
    if ((x+1) < ROWS) {
        if (grid[x+1][y] == 0) {
            neighbors--;
        }
    }
    else {
        neighbors--;
    }
    if ((x+1) < ROWS && (y+1) < COLUMNS) {
        if (grid[x+1][y+1] == 0) {
            neighbors--;
        }
    }
    else {
        neighbors--;
    }
    //num of neighbors determines who lives and who dies
    return neighbors;
}
