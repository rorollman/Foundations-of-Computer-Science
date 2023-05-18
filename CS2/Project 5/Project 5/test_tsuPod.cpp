/****************************************************
Name: Rowan Rollman
Date:
Problem Number: 5
Hours spent solving the problem:
Instructor: Komogortsev, TSU
*****************************************************/

#include <iostream>
#include <fstream>
#include "tsuPod.h"
using namespace std;

int main ()
{
    //initiate
    TsuPod tPod(25, 100);
    int songCnt = 0;
    int memUsed = 0;
    
    tPod.initTsuPod();
    
    int retCode = tPod.addSong("Runaway1", "Bon Jovi1", 1, memUsed, songCnt);

    //Testing successful song addition
    retCode = tPod.addSong("Runaway2", "Bon Jovi2", 2, memUsed, songCnt);

    tPod.showSongList(); // to show that I have added 2 songs
    
    retCode = tPod.addSong("Runaway3", "Bon Jovi3", 3, memUsed, songCnt);

    retCode = tPod.addSong("Runaway4", "Bon Jovi4", 1, memUsed, songCnt);

    retCode = tPod.addSong("Runaway5", "Bon Jovi5", 5, memUsed, songCnt);

    retCode = tPod.addSong("Runaway6", "Bon Jovi6", 6, memUsed, songCnt);

    retCode = tPod.addSong("Runaway7", "Bon Jovi7", 1, memUsed, songCnt);

    retCode = tPod.addSong("Runaway8", "Bon Jovi8", 1, memUsed, songCnt);
    
    //Testing unsuccessful song addition (no empty spots)
    retCode = tPod.addSong("Runaway9", "Bon Jovi9", 1, memUsed, songCnt);

    retCode = tPod.addSong("Runaway10", "Bon Jovi10", 1, memUsed, songCnt);

    tPod.showSongList(); //showing that I have successfully added  6 songs
    
    //Testing unsuccessful song addition (not enough memory)
    retCode = tPod.addSong("Runaway11", "Bon Jovi11", 10, memUsed, songCnt);
    cout << retCode << endl;
    tPod.showSongList();
    //Testing unsuccessful song addition (invalid size)
    retCode = tPod.addSong("Runaway12", "Bon Jovie12", -1, memUsed, songCnt);

    //Unsuccessful song removal
    retCode = tPod.removeSong("Runaway100", "Bon Jovie100", 3, memUsed, songCnt);
    tPod.showSongList();
    cout << endl;
    
    //Successful song removal
    retCode = tPod.removeSong("Runaway7", "Bon Jovi7", 1, memUsed, songCnt);
    
    tPod.closeFile();
    
    return 0;
}
