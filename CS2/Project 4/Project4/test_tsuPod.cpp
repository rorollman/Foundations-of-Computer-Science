/****************************************************
Name: Rowan Rollman
Date: 22 March 2021
Problem Number: 4
Hours spent solving the problem: 28
Instructor: Komogortsev, TSU
*****************************************************/


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "tsuPod.h"

using namespace std;

int main() 
{
    int memUsed;
    int songCnt;
    
    //initializing tsuPod
    initTsuPod(memUsed, songCnt);

    //Following code lists all songs located in tsuPod memeory 
    //The word “empty” indicates empty slot in the playlist
    //rather than name of the song
//    showSongList();
    cout << endl;
    


    //Following code tests tsuPod input functionality
    int retCode = addSong("Runaway1", "Bon Jovi1", 1, memUsed, songCnt);

    //Testing successful song addition
    retCode = addSong("Runaway2", "Bon Jovi2", 2, memUsed, songCnt);

//    showSongList(); // to show that I have added 2 songs
    
    retCode = addSong("Runaway3", "Bon Jovi3", 3, memUsed, songCnt);

    retCode = addSong("Runaway4", "Bon Jovi4", 1, memUsed, songCnt);

    retCode = addSong("Runaway5", "Bon Jovi5", 5, memUsed, songCnt);

    retCode = addSong("Runaway6", "Bon Jovi6", 6, memUsed, songCnt);

    retCode = addSong("Runaway7", "Bon Jovi7", 1, memUsed, songCnt);

    retCode = addSong("Runaway8", "Bon Jovi8", 1, memUsed, songCnt);
    
    //Testing unsuccessful song addition (no empty spots)
    retCode = addSong("Runaway9", "Bon Jovi9", 1, memUsed, songCnt);

    retCode = addSong("Runaway10", "Bon Jovi10", 1, memUsed, songCnt);

//    showSongList(); //showing that I have successfully added  6 songs
    
    //Testing unsuccessful song addition (not enough memory)
    retCode = addSong("Runaway11", "Bon Jovi11", 10, memUsed, songCnt);
    cout << retCode << endl;
//    showSongList();
    //Testing unsuccessful song addition (invalid size)
    retCode = addSong("Runaway12", "Bon Jovie12", -1, memUsed, songCnt);

    //Unsuccessful song removal
    retCode = removeSong("Runaway100", memUsed, songCnt);
//    showSongList();
    cout << endl;
    
    //Successful song removal
    retCode = removeSong("Runaway7", memUsed, songCnt);
//    showSongList();
    cout << endl;

    //Testing shuffle
    shuffle();
    cout << endl;
//    showSongList();
    cout << endl;
    
    //Clearing song list
    clearMemory(memUsed, songCnt);
//    showSongList();
    
//    system("PAUSE");
    
}
