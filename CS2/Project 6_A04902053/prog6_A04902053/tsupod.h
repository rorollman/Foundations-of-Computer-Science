/****************************************************
Name: Rowan Rollman
Date:  April 2021
Problem Number: 6
Hours spent solving the problem: 60
Instructor: Komogortsev, TSU
*****************************************************/

//specification file for tsuPod class
#ifndef tsuPod_h
#define tsuPod_h
#include "Song.h"
#include <string>

using namespace std;

class TsuPod
{
private:
    Song song;
    int MEMORY_SIZE;
    int NUM_SONGS;
    struct songList
    {
        Song song;
        songList *next;
    };
    songList *head;
public:
    //constructor
    TsuPod();
    TsuPod(int, int);
    //destructor
    ~TsuPod();

    //functions
    void initTsuPod ();
    int addSong (string nTitle, string nArtist, int size, int&, int&);
    int removeSong (string nTitle, string nArtist, int size, int&, int&);
    void shuffle (int&);
    void clearMemory (int&, int&);
    void showSongList (int&);
    void sortSongList (int&);
    int getTotalMemory () const;
    int getRemainingMemory (int&) const;
};

#endif //tsuPod_h

