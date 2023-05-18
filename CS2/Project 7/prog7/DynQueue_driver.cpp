/***********************************
Date: 3 May 2021
Problem Number: 7
Hours spent working on project: 45
Instructor: Komogortsev, TSU
************************************/

#include "DynQueue.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    charQueue cQueue;
    int retcode;
    //askes user name of input file
    string fileName;
    cout << "Name of Input File: ";
    cin >> fileName;
    ifstream inFile;
    inFile.open(fileName.c_str());

    ofstream oFile;
    oFile.open("exp_output.dat");

    //error checking
    if (!inFile)
    {
         cout << "File not opened properly" << endl;
        return 0;
    }
    
    //looks at file until file ends
    while (!inFile.eof())
    {
        //store line
        string equation;
        inFile >> equation;
        if (equation == "\0") {
            return -1;
        }
    int n = equation.length();
        char cArr[n+1];
        strcpy(cArr, equation.c_str());

        //creates the dynamic array
        charQueue * queue = new charQueue();

        //only adds parans and brackets to queue
        for (int i=0; i<n; i++) {
            if (cArr[i] == '(' || cArr[i] == '[') {
                cQueue.enqueue(cArr[i]);
            }
            if (cArr[i] == ')' || cArr[i] == ']') {
                cQueue.enqueue(cArr[i]);
            }
        }
        //error codes
        retcode = checkBalance(cQueue);
        
        //write to file
        oFile << equation << " === ";
        if (retcode == 0) {
            oFile << " valid equation\n";
        }
        else if (retcode == 1) {
                oFile << " missing ')'\n";
            }
            else if (retcode == 2) {
                oFile << " missing ']'\n";
            }
        delete queue;
            cQueue.clear();
        }
        inFile.close();
        oFile.close();
    }
