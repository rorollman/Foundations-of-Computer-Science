/****************************************************
Name: Rowan Rollman
Date:  April 2021
Problem Number: 6
Hours spent solving the problem: 60
Instructor: Komogortsev, TSU
*****************************************************/

//implementation file for Song class
#include <iostream>
#include <string>
#include <cstdlib>

#include "Song.h"

using namespace std;

//constructor
Song::Song()
{
    title = "";
    artist = "";
    size = 0;
    songNum = 0;
}

Song::Song (string nTitle, string nArtist, int s)
{
    title = nTitle;
    artist = nArtist;
    size = s;
}

void Song::setTitle(string t)
{
    title = t;
}

void Song::setArtist(string a)
{
    artist = a;
}

void Song::setSize(int s)
{
    size = s;
}

void Song::setPos(int pos)
{
    songNum = pos;
}

string Song::getTitle() const
{
    return title;
}

string Song::getArtist() const
{
    return artist;
}

int Song::getSize() const
{
    return size;
}

bool Song::operator == (const Song &s)
{
    bool test=false;

    if (title == s.title) {
        test = true;
    }
    else {
    test = false;
    }
    return test;
}

bool Song::operator < (const Song &s)
{
    bool test=false;
    if (title < s.title) {
        test = true;
    }
    else if (title == s.title) {
        if (artist < s.artist) {
            test = true;
        }
    }
    else if (title == s.title) {
        if (artist == s.artist) {
            if (size < s.size) {
                test = true;
            }
    }
    }
    return test;
}

bool Song::operator > (const Song &s)
{
    bool test=false;

    if (title > s.title) {
        test = true;
    }
    else if (title == s.title) {
        if (artist > s.artist) {
            test = true;
        }
    }
    else if (title == s.title) {
        if (artist == s.artist) {
            if (size > s.size) {
                test = true;
            }
    }
    }
    return test;
}

bool Song::operator != (const Song &blank)
{
    bool test=false;

    if (title != blank.title) {
        test = true;
    }
    else {
        test = false;
    }
    return test;
}
