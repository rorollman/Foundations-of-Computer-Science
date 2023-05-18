/****************************************************
Name: Rowan Rollman
Date: 6 April 2021
Problem Number: 5
Hours spent solving the problem: 60
Instructor: Komogortsev, TSU
*****************************************************/

//implementation file for tsuPod class
#include <iostream>
#include <cstdlib>
#include "tsupod.h"
using namespace std;

TsuPod::TsuPod()    //default constructor
{
    NUM_SONGS = 0;
    MEMORY_SIZE = 256;
}

TsuPod::TsuPod(int numSongs, int memSize)  //constructor with parameters
{
    //max mem allowed 256
    if (memSize > 256) {
        cout << "Memory exceeds 100 MB. ";
        cout << "Setting maximum memory to 100 MB.\n";
    }

    //if song and mem variables are valid, they are set here
    else {
    NUM_SONGS = numSongs;
    MEMORY_SIZE = memSize;
    }
}

void TsuPod::initTsuPod()
{
    //creates Song object
    Song s;

}

int TsuPod::addSong(string nTitle, string nArtist, int size, int &mem, int &cnt)
{
    //creates Song object
    Song s;
    songList *newnode;
    songList *nodeptr;

    //invalid size
    if (size <= 0) {
        cout << "Size of " << nTitle << " is invalid.\n";
        return 0;
    }

    //blank title or artist
    if (nTitle == "" || nArtist == "") {
        cout << "Title or artist is blank, song not added.\n";
        return 0;
    }

    //not enough memory
    if (size+mem >= MEMORY_SIZE) {
        cout << "Not enough memory to add: " << nTitle;
        cout << endl;
        return 0;
    }

    //the goldilocks of conditions, it's just right
    if (size+mem <= MEMORY_SIZE) {
        s.setTitle(nTitle);
        s.setArtist(nArtist);
        s.setSize(size);

        newnode = new songList;
        newnode->song = s;
        newnode->next = NULL;
        //if the list is empty, make it the head
        if (!head) {
            head = newnode;
        }
    //list isn't empty, append
        else
    {
            nodeptr = head;
            while (nodeptr->next) {
                nodeptr = nodeptr->next;
            }
            nodeptr->next = newnode;
        }

    //increase song count and memory used
        cnt++;
    mem += size;
    }
    return 0;
}

int TsuPod::removeSong(string nTitle, string nArtist, int size, int &mem, int &cnt)
{
    Song s;

    s.setTitle(nTitle);
    s.setArtist(nArtist);
    s.setSize(size);
    songList *nodeptr;
    songList *prevnode;

    //if the list is empty, display error message
    if (!head) {
        cout << "Nothing to delete\n";
        return 0;
    }

    //if it's the first song, delete
    if (head->song == s) {
        cnt--;
    mem -= size;
        cout << "Removing " << nTitle << "...\n";
        nodeptr = head->next;
        delete head;
        head = nodeptr;
    }

    //traverse list to look for the song to remove
    else
    {
         nodeptr = head;
        while (nodeptr != NULL && nodeptr->song != s) {
            prevnode = nodeptr;
            nodeptr = nodeptr->next;
        }
    //if found, delete
        if (nodeptr) {
            cout << "Removing " << nTitle << "...\n";
            prevnode->next = nodeptr->next;
            delete nodeptr;
            cnt--;
            mem -= size;
            return 0;
        }
    }
    //if not found, display error message
    cout << "Could not find: " << nTitle << ", removal failed.\n";
    return 0;
}

void TsuPod::showSongList(int &cnt)
{
    Song s;
    int temp=0;

    if (head == NULL) {
        cout << "TsuPod is empty.\n";
    }
    else {
    cout << endl;
        cout << "Song List: \n\n";
        songList *nodeptr;
        nodeptr = head;
        while (nodeptr != NULL && temp<cnt) {
            cout << "Song " << temp+1 << ": ";
            cout << nodeptr->song.getTitle() << ", ";
            cout << nodeptr->song.getArtist() << ", ";
            cout << nodeptr->song.getSize() << " MB\n";
            nodeptr = nodeptr->next;
            temp++;
        }
    }
}

void TsuPod::shuffle(int &cnt)
{
    cout << "Shuffling...\n";
    songList *prevNode;
    songList *switchSong;
    songList *ptr1;
    songList *ptr2;
    Song temp;
    ptr1 = head;

    for (int i=0; i<cnt; i++) {
        ptr2 = head;
        prevNode = ptr1;
        int first = (rand()%cnt) + 1;
        for (int j=1; j<= first; j++) {
            if (j == first) {
                switchSong = ptr2;
            }
            ptr2 = ptr2->next;
        }
    temp = prevNode->song;
        prevNode->song = switchSong->song;
        switchSong->song = temp;
        ptr1 = ptr1->next;
    }
}

void TsuPod::clearMemory(int &mem, int &cnt)
{
    cout << "Clearing memory...\n";
    Song s;

    songList *temp;
    temp = head;

    while (temp != NULL) {
        head->next = temp->next;
        temp->next = NULL;
        delete temp;
        temp = head->next;
    }
    head = NULL;
    cnt = 0;
    mem = 0;

}

void TsuPod::sortSongList(int &cnt)
{
    cout << "Sorting...\n";
    songList *nodeptr = head, *sort;
    Song temp;
    while (nodeptr) {
        for (sort = nodeptr->next; sort; sort = sort->next) {
            if (nodeptr->song > sort->song) {
                temp = nodeptr->song;
                nodeptr->song = sort->song;
                sort->song = temp;
            }
    }
    nodeptr = nodeptr->next;
    }
    cout << "Sorted\n";
}

int TsuPod::getTotalMemory() const
{
    return MEMORY_SIZE;
}

int TsuPod::getRemainingMemory(int &mem) const
{
    return MEMORY_SIZE-mem;
}

TsuPod::~TsuPod()
{
    //destructor
    songList *nodeptr;
    songList *nextnode;

    nodeptr = head;
    while (nodeptr != NULL) {
        nextnode = nodeptr->next;
        delete nodeptr;
        nodeptr = nextnode;
    }
}

