/****************************************************
Name: Rowan Rollman
Date: 6 April 2021
Problem Number: 5
Hours spent solving the problem: 60
Instructor: Komogortsev, TSU
*****************************************************/

//driver file
#include <iostream>
#include <cstdlib>
#include "tsupod.h"
using namespace std;

int main ()
{
    //initiate
    TsuPod tPod(15, 60);
    int songCnt = 0;
    int memUsed = 0;

    tPod.initTsuPod();

    tPod.addSong("American Idiot", "Green Day", 1, memUsed, songCnt);

    //Testing successful song addition
    tPod.addSong("Fat Lip", "Sum 41", 1, memUsed, songCnt);

    tPod.addSong("Last Hope", "Paramore", 2, memUsed, songCnt);

    tPod.addSong("Dogtown", "Fratellis", 1, memUsed, songCnt);

    tPod.addSong("Harmony Hall", "Vampire Weekend", 4, memUsed, songCnt);

    tPod.addSong("Education", "Modest Mouse", 1, memUsed, songCnt);

    tPod.addSong("I Want a Dog", "Hobo Johnson", 3, memUsed, songCnt);

    tPod.addSong("Go Away", "Weezer", 6, memUsed, songCnt);

    tPod.addSong("Cheaper", "Bob Schneider", 3, memUsed, songCnt);

    tPod.addSong("Just Like You", "Three Days Grace", 1, memUsed, songCnt);

    tPod.addSong("Basement Noise", "All Time Low", 2, memUsed, songCnt);

    tPod.addSong("Africa", "Weezer", 2, memUsed, songCnt);

    tPod.addSong("Africa", "Toto", 2, memUsed, songCnt);

    //Testing unsuccessful song addition (not enough memory)
    tPod.addSong("Mama Knows Best", "We The Kings", 90, memUsed, songCnt);
    tPod.showSongList(songCnt);

    //Testing unsuccessful song addition (invalid size)
    tPod.addSong("Never There", "Cake", -1, memUsed, songCnt);

    //Unsuccessful song removal
    tPod.removeSong("Runaway", "Bon Jovie", 3, memUsed, songCnt);
    tPod.showSongList(songCnt);

    cout << "Total Memory: " << tPod.getTotalMemory();
    cout << " MB\n";
    cout << "Memory left: " << tPod.getRemainingMemory(memUsed);
    cout << " MB\n";

    //Successful song removal
    tPod.removeSong("Go Away", "Weezer", 6, memUsed, songCnt);
    tPod.showSongList(songCnt);
    //successful shuffle
    tPod.shuffle(songCnt);
    tPod.showSongList(songCnt);
    //successful sorting
    tPod.sortSongList(songCnt);
    tPod.showSongList(songCnt);
    //successful clearing
    tPod.clearMemory(memUsed, songCnt);
    tPod.showSongList(songCnt);

    return 0;
}



