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

#include "tsuPod.h"

using namespace std;

TsuPod info[NUM_SONGS];

void initTsuPod(int &mem, int &cnt) {
    //move through array and assign as blank
    for (int num=0; num<NUM_SONGS; num++) {
        info[num].title = "";
        info[num].artist = "";
        info[num].size = 0;
    }
    //initialize memory and song count
    mem=0;
    cnt=0;
}

int addSong (string newTitle, string newArtist, int size, int &mem, int &cnt) {
    //return 0 for successful addition
    //return -1 if not enough memory
    //return -2 for any other error
    //cout << mem+size << endl;
    if (size <= 0) {
        cout << "Size of " << newTitle << " is invalid.\n";
        return -2;
    }
    //checks to make sure there is enough memory to add song
    if ((mem+size) > MEMORY_SIZE) {
        cout << "Not enough memory to add: " << newTitle << endl;
        return -1;
    }
    //checks to make sure there are still spaces to add song
    if (cnt >= NUM_SONGS) {
        cout << "Not enough slots to add: " << newTitle << endl;
        return -2;
    }
    
    //checks if title or artist spot is empty
    if (newTitle == "" || newArtist == "") {
        cout << "Title or Artist spot is blank, cannot add song.\n";
        return -2;
    }
    
    //now adding successfully
    if (mem+size <= MEMORY_SIZE) {
        info[cnt].title = newTitle;
        info[cnt].artist = newArtist;
        info[cnt].size = size;
        
        //updating memory
        mem += size;
        cnt++;
        return 0;
    }
    return 0;
}

int removeSong (string title, int &mem, int &cnt) {
    for (int num=0; num<NUM_SONGS; num++) {
        if (info[num].title == title) {
            cout << "Removing " << title << endl;
            mem -= info[num].size;
            
            info[num].title = "";
            info[num].artist = "";
            info[num].size = 0;
            
            cnt -= 1;
            return 0;
            //succesfully removed
        }
    }
    cout << "Song not found, removal failed.\n";
    return -1;
}

void clearMemory(int &mem, int &cnt) {
    //move through array and assign as blank
    for (int num=0; num<NUM_SONGS; num++) {
        info[num].title = "";
        info[num].artist = "";
        info[num].size = 0;
    }
    //initialize memory and song count
    mem=0;
    cnt=0;
}

void showSongList() {
    //working through array of songs
    for (int i=0; i<NUM_SONGS; i++) {
        //if slot is blank, show empty
        if (info[i].title == "") {
            cout << "Empty\n";
        }
        //if it is not blank, show the info
        else {
            cout << info[i].title << ", ";
            cout << info[i].artist << ", ";
            cout << info[i].size << endl;
        }
    }
}

void shuffle() {
    TsuPod temp;
    int first, second;
    
    for (int i=0; i<NUM_SONGS; i++) {
        //creating indexes of random numbers
        first = (rand()%NUM_SONGS);
        second = (rand()%NUM_SONGS);
        
        //assigning and swapping
        temp = info[first];
        info[first] = info[second];
        info[second] = temp;
    }
}
