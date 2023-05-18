/****************************************************
Name: Rowan Rollman
Date: 22 March 2021
Problem Number: 4
Hours spent solving the problem: 28
Instructor: Komogortsev, TSU
*****************************************************


This header file provides the prototypes of the function definitions
for the tsuPod project. This file has to be included in the program 
that tests the functionality of tsuPod.

You have to create file tsuPod.cpp with function definitions 
for the test program to work.

*********************************/
#ifndef tsuPod_h
#define tsuPod_h

#include <iostream>
#include <string>

using namespace std;

const int NUM_SONGS = 8;
const int MEMORY_SIZE = 25;

struct TsuPod
{
    string title;
    string artist;
    int size;
};


////////////////////////////////
/* FUNCTION - void initTsuPod

 Initialize all the slots to blank and 0 size memory
 
input parms - <memUsed and songCnt>
 
 output parms - <none>
*/

void initTsuPod (int &mem, int &cnt);


///////////////////////////////
/* FUNCTION - int addSong
 * attempts to add a new song to the tsuPod
          o returns a 0 if successful
          o returns -1 if not enough memory to add the song
          o returns -2 for any other error
 
 input parms - <title, artist, and size>
 
 output parms - <int returnVal>
*/

int addSong (string newTitle, string newArtist, int size, int &mem, int &cnt);


////////////////////////////
/* FUNCTION - int removeSong
    * attempts to remove a song from the tsuPod
          o returns 0 if successful
          o returns -1 if nothing is removed
    
          
input parms - <title, memUsed, songCnt>
 
output parms - <int returnVal>
*/   

int removeSong (string title, int &mem, int &cnt);


////////////////////////////
/* FUNCTION - void clearMemory
* clears all the songs from memory

input parms - <memUsed and songCnt>
 
output parms - <none>
*/
void clearMemory(int &mem, int &cnt);


/////////////////////////////
/* FUNCTION - void showSongList   
    * prints the current list of songs in order from first to last to standard output
    * format - slot #, Title, Artist, size in MB (one song per line)
    * print "Empty" for any slots that do not contain a song

input parms - <none>
 
output parms - <none>
*/
    
void showSongList ();


////////////////////////////
/* FUNCTION - void shuffle
    *  shuffles the songs into random order
          o will do nothing if there are less than two songs in the current list

input parms - <none>
 
output parms - <none>
*/

void shuffle ();

#endif
