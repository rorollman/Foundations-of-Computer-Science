/****************************************************
Name: Rowan Rollman
Date:
Problem Number: 5
Hours spent solving the problem:
Instructor: Komogortsev, TSU
*****************************************************/

//implementation file for Song class


#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "Song.h"

using namespace std;

//constructor
Song::Song()
{
    strcpy(title, "");
    strcpy(artist, "");
    size = 0;
    songNum = 0;
}

Song::Song (char *nTitle, char *nArtist, int s)
{
    strcpy(title, nTitle);
    strcpy(artist, nArtist);
    size = s;
}

//mutators
void Song::setTitle(char *t)
{
    strcpy(title, t);
}

void Song::setArtist(char *a)
{
    strcpy(artist, a);
}

void Song::setSize(int s)
{
    size = s;
}

void Song::setPos(int)
{
    
}
//accessors
const char *Song::getTitle() const
{
    return title;
}

const char *Song::getArtist() const
{
    return artist;
}

int Song::getSize() const
{
    return size;
}
