/****************************************************
Name: Rowan Rollman
Date: 1/20/21
Problem Number: 1
Hours spent solving the problem: 12
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

//functions
void dateChange(ofstream &newFile, char line[]);
float tempChange(ofstream &newFile, char line[]);

const int size = 20;

int main(){
    ifstream outFile;
    ofstream newFile;
    int numReadings=0;
    char line[size];
    float avgTemp=0;
    
    outFile.open("biodata.dat");

    newFile.open("filtered_biodata.dat");
    
    //formatting
    newFile << "BIODATA Formatted Output" << endl;
    newFile << endl;
    
    //getting number of readings that are included in file
    outFile >> numReadings;
    
    //opens to the first line
    outFile.getline(line, size);
    
    //starts at second line which should be first reading
    for (int i=0; i<numReadings; i++) {
        outFile.getline(line, size);
        avgTemp += tempChange(newFile, line);
        dateChange(newFile, line);
        }
    
    //formatting
    newFile << endl;
    newFile << "Average Temp --- ";
    newFile << setprecision(2) << fixed << avgTemp/numReadings << " C";
    
    outFile.close();
    newFile.close();
    return 0;
    
}

void dateChange(ofstream &newFile, char line[])
{
    //character arrays for date
    char year[4], month[2], day[2], time[4];
    
    newFile << "recorded on ";
    
    //getting months from char array
    for (int i=4; i<6; i++) {
        month[i-4] = line[i];
        newFile << month[i-4];
        }
    newFile << "/";
    
    //getting day
    for (int i=6; i<8; i++) {
        day[i-6] = line[i];
        newFile << day[i-6];
        }
    newFile << "/";
    
    //getting year
    for (int i=0; i<4; i++) {
        year[i] = line[i];
        newFile << year[i];
        }
    newFile << " at ";
    
    //time is in 24hr
    for (int i=8; i<12; i++) {
        time[i-8] = line[i];
        newFile << time[i-8];
        }
    //formatting for file
    newFile << endl;
}

float tempChange(ofstream &newFile, char line[])
{
    char tempArr[6];
    float temp;
    
    //setting up tempArr
    for (int i=14; i<19; i++) {
        tempArr[i-14] = line[i];
        }
    
    //changing char array to float
    temp = strtof(tempArr, NULL);
    
    //checking unit of temp
    switch (line[13]) {
        case 'F':
            //do math things
            temp = temp-32;
            temp = temp/1.8;
            if (temp<0) {
                cout << "Temperature is not valid (negative)." << endl;
                exit(EXIT_FAILURE); //exit program
                }
            //formatting
            newFile << setprecision(2) << fixed << temp << " C --- ";
            break;
        case 'C':
            //change nothing
            if (temp<0) {
                cout << "Temperature is not valid (negative)" << endl;
                exit(EXIT_FAILURE); //exit program
                }
            //formatting
            newFile << setprecision(2) << fixed << temp << " C --- ";
            break;
        default:
            //error message about temp unit
            cout << "Unit of temperature not valid." << endl;
            cout << "Only F and C are allowed." << endl;
            cout << "Please edit folder contents." << endl;
            exit(EXIT_FAILURE); //exit program
            break;
    }
  
    return temp;
}


