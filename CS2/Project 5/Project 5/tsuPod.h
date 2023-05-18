/****************************************************
Name: Rowan Rollman
Date:
Problem Number: 5
Hours spent solving the problem:
Instructor: Komogortsev, TSU
*****************************************************/

//specification file for tsuPod class
#ifndef tsuPod_h
#define tsuPod_h
#include "Song.h"
#include <fstream>
#include <string>

using namespace std;

class TsuPod
{
private:
    Song song;
    fstream binFile;
    int MEMORY_SIZE;
    int NUM_SONGS;
public:
    //constructor
    TsuPod();
    TsuPod(int, int);
    
    //functions
    void initTsuPod ();
    int addSong (char nTitle[], char nArtist[], int size, int&, int&);
    int removeSong (char nTitle[], char nArtist[], int size, int&, int&);
    void clearMemory(int &, int &);
    void showSongList ();
    void shuffle ();
    void closeFile();
};

#endif //tsuPod_h
