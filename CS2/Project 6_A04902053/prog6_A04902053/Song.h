/****************************************************
Name: Rowan Rollman
Date: 6April 2021
Problem Number: 
Hours spent solving the problem: 60
Instructor: Komogortsev, TSU
*****************************************************/

//specification file for Song class
#ifndef Song_h
#define Song_h
#include <string>

using namespace std;

class Song
{
private:
    string artist;
    string title;
    int size;
    int songNum;
public:
    Song();
    Song(string nTitle, string nArtist, int);
    string getTitle() const;  //return title
    string getArtist() const; //return artist
    int getSize() const;      //return size
    void setTitle(string);
    void setArtist(string);
    void setSize(int);
    void setPos(int);

    bool operator == (const Song &s);
    bool operator < (const Song &s);
    bool operator > (const Song &s);
    bool operator != (const Song &blank);
};

#endif // Song_h
