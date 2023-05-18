/****************************************************
Name: Rowan Rollman
Date:
Problem Number: 5
Hours spent solving the problem:
Instructor: Komogortsev, TSU
*****************************************************/

//specification file for Song class

#ifndef Song_h
#define Song_h
#include <fstream>
#include <string>

using namespace std;

class Song
{
private:
    char artist[256];
    char title[256];
    int size;
    int songNum;
public:
    Song();
    Song(char * nTitle, char * nArtist, int);
    const char * getTitle() const;  //return title
    const char * getArtist() const; //return artist
    int getSize() const;      //return size
    void setTitle(char*);
    void setArtist(char*);
    void setSize(int);
    void setPos(int);
    
    bool operator == (const Song &s);
    bool operator < (const Song &s);
    bool operator > (const Song &s);
};

#endif // Song_h 
