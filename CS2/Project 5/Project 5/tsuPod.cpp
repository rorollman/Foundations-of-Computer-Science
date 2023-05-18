/****************************************************
Name: Rowan Rollman
Date:
Problem Number: 5
Hours spent solving the problem:
Instructor: Komogortsev, TSU
*****************************************************/

//implementation file for tsuPod class
#include <iostream>
#include <fstream>
#include "tsuPod.h"
using namespace std;

TsuPod::TsuPod()    //default constructor
{
    NUM_SONGS = 0;
    MEMORY_SIZE = 0;
}

TsuPod::TsuPod(int numSongs, int memSize)  //constructor with parameters
{
    NUM_SONGS = numSongs;
    MEMORY_SIZE = memSize;
}

void TsuPod::initTsuPod()
{
    //creates Song object
    Song s;
    //opens binary file
    binFile.open("tsupod_memory.dat", ios::in | ios::out | ios::binary);
    if (!binFile) {
        return;
    }
    
    for (int i=0; i<NUM_SONGS; i++) {
        binFile.seekp((i)*sizeof(s), ios::beg);
        binFile.write(reinterpret_cast<char *>(&s), sizeof(s));
    }
}

int TsuPod::addSong(char nTitle[], char nArtist[], int size, int &mem, int &cnt)
{
    //return 0 for successful addition
    //return -1 if not enough memory
    //return -2 for any other error
    
    //creates Song object
    Song s;
    
    if (size<0) {
        cout << "Invalid song size, song not added.\n";
        return -2;
    }
    
    if (strcmp(nTitle, "") ==0  || strcmp(nArtist, "") ==0) {
        cout << "Title or artist is blank, song not added.\n";
        return -2;
    }
    
    if (cnt+1 > NUM_SONGS) {
        cout << "Not enough slots to add: " << nTitle;
        cout << endl;
        return -2;
    }
    
    if (size+mem > MEMORY_SIZE) {
        cout << "Not enough memory to add: " << nTitle;
        cout << endl;
        return -1;
    }
    
    if (size+mem <= MEMORY_SIZE) {
        s.setTitle(nTitle);
        s.setArtist(nArtist);
        s.setSize(size);
        s.setPos(cnt);
        cnt++;
        mem += size;
        
        binFile.seekp((cnt-1)*sizeof(s), ios::beg);
        binFile.write(reinterpret_cast<char *>(&s), sizeof(s));
        binFile.seekp(0L, ios::beg);
        
        return 0;

    }
    return 0;
}

int TsuPod::removeSong(char nTitle[], char nArtist[], int size, int &mem, int &cnt)
{
    Song s;
    
    for (int num=0; num<NUM_SONGS; num++) {
        if (nTitle == s.getTitle()) {
            cout << "Removing " << nTitle << endl;
            cnt--;
            mem -=size;
            strcpy(nTitle, "");
            strcpy(nArtist, "");
            size = 0;
            binFile.seekg((num)*sizeof(s), ios::beg);
            binFile.read(reinterpret_cast<char *>(&s), sizeof(s));
            binFile.seekp(0L, ios::beg);
            return 0;
        }
    }
    cout << "Song not found, removal failed.\n";
    return -1;
}

void TsuPod::showSongList()
{
    Song s;
    
    cout << "Song List: \n\n";
    
    for (int i=0; i<NUM_SONGS; i++) {
        binFile.seekg((i)*sizeof(s), ios::beg);
        binFile.read(reinterpret_cast<char *>(&s), sizeof(s));
        cout << "Song " << i+1 << ": ";
        cout << s.getTitle() << ", ";
        cout << s.getArtist() << ", ";
        cout << s.getSize() << " MB\n";
    }
    cout << endl;
    binFile.clear();
    binFile.seekg(0L, ios::beg);
}

void TsuPod::clearMemory (int &mem, int &cnt)
{
    Song s;
    
    for (int i=0; i<NUM_SONGS; i++) {
        binFile.seekp((i)*sizeof(s), ios::beg);
        binFile.write(reinterpret_cast<char *>(&s), sizeof(s));
    }
}

void TsuPod::closeFile()
{
    binFile.close();
}
