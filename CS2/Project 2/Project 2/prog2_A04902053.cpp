/****************************************************
Name: Rowan Rollman
Date: 14 February 2021
Problem Number: 2
Hours spent solving the problem: 26
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int SIZE = 256;

//can't use >> to read from file, but can use << to write to file
void organizeGrades(int gradeInt[]);
float calAvg(int gradeInt[]);
char letterGrade(float avgGrade);
//with 6 grades, drop lowest grade and calculate avg
//if there are only 5 grades, give error/warning and continue program
//"only 5 grades for student x, will not drop lowest grade"
//then calculate avg from just those 5

int main()
{
    ifstream inFile;
    ofstream outFile;
    int gradeInt[6], stuIDInt;
    char input[SIZE];
    char inputCPY[SIZE];
    char* tokens;
    
    char firstName[10], lastName[12], stuID[6], grades[6][4];
    
    
    inFile.open("student_input.dat");
    outFile.open("student_results.dat");
    //error handling
    if (!inFile) {
            cout << "File could not be opened.\n";
            return 0;
        }
    //output formatting table
    outFile << left << setw(11) << "Last name";
    outFile << left << setw(13) << "First name";
    outFile << left << setw(10) << "ID";
    outFile << left << setw(16) << "Average Score";
    outFile << left << setw(6) << "Grade\n";
    
    //get the first line
    inFile.getline(input, SIZE);
  
    //counting how many letGrades
    int Acount=0;
    int Bcount=0;
    int Ccount=0;
    int Dcount=0;
    int Fcount=0;
    
    //does all this while the file still has lines
    while (!inFile.eof()) {
        
        //make a copy of each line
        strcpy(inputCPY, input);
        //separate line into tokens separated by spaces
        tokens = strtok(inputCPY, " ");
        //assigning each token to the correct variable
        strcpy(firstName, tokens);
        tokens = strtok(NULL, " ");
        strcpy(lastName, tokens);
        tokens = strtok(NULL, " ");
        strcpy(stuID, tokens);
        stuIDInt = atoi(stuID);
        
        for (int i=0; i<6; i++) {
            tokens = strtok(NULL, " ");
            strcpy(grades[i], tokens);
        }

        //error handling
        for (int i=0; i<6; i++) {
            if (isspace(grades[i][0])) {
                cout << "There are only 5 grades present for " << firstName;
                cout << ". The lowest grade will not be dropped.\n";
            }
            //changes from cstring to int
            gradeInt[i] = atoi(grades[i]);
            if (gradeInt[i] < 0) {
                cout << "Negative grade present. Exiting program.\n";
                return 0;
            }
        }
        //passing the grades to each function
        organizeGrades(gradeInt);
        float avgGrade;
        avgGrade = calAvg(gradeInt);
        char letGrade;
        letGrade = letterGrade(avgGrade);
        
        //writing to file, formatting
        outFile << left << setw(11) << lastName;
        outFile << left << setw(13) << firstName;
        outFile << left << setw(10) << stuIDInt;
        outFile << left << setw(16) << avgGrade;
        outFile << left << setw(6) << letGrade;
        outFile << endl;
        
        //increasing letter count
        switch (letGrade) {
            case 'A':
                ++Acount;
                break;
            case 'B':
                ++Bcount;
                break;
            case 'C':
                ++Ccount;
                break;
            case 'D':
                ++Dcount;
                break;
            case 'F':
                ++Fcount;
                break;
        }
        
        //get next line
        inFile.getline(input, SIZE);
    }
    
    //formatting grade totals
    outFile << "Grade Totals:" << endl;
    if (Acount > 0) {
        outFile << "A - " << Acount;
        outFile << endl;
    }
    if (Bcount > 0) {
        outFile << "B - " << Bcount;
        outFile << endl;
    }
    if (Ccount > 0) {
        outFile << "C - " << Ccount;
        outFile << endl;
    }
    if (Dcount > 0) {
        outFile << "D - " << Dcount;
        outFile << endl;
    }
    if (Fcount > 0) {
        outFile << "F - " << Fcount;
        outFile << endl;
    }
    
    inFile.close();
    outFile.close();
    
    return 0;
}

//function to organize grades using selection sort
void organizeGrades(int gradeInt[])
{
    int begin, minPos, value;
    //sorting gradeInt array from lowest to highest
    for (begin=0; begin<5; begin++) {
        minPos = begin;
        value = gradeInt[begin];
        for (int index = begin+1; index<6; index++) {
            if (gradeInt[index]<value) {
                value = gradeInt[index];
                minPos = index;
            }
        }
        gradeInt[minPos] = gradeInt[begin];
        gradeInt[begin] = value;
    }
}

//calculates avg
float calAvg(int gradeInt[])
{
    //calculating avg with elements 1 through 5
    //if there are only 5 grades, element 0 is a grade of 0
    float sum=0;
    for (int i=1; i<6; i++) {
        sum += gradeInt[i];
    }
    float avg=sum/5;
    return avg;
}

//takes avg and changes it to a letter grade
char letterGrade(float avgGrade)
{
    char letGrade;
    //conditions are the cutoffs
    if (avgGrade < 59.5) {
        letGrade = 'F';
    }
    if (avgGrade < 69.5) {
        letGrade = 'D';
    }
    if (avgGrade < 79.5) {
        letGrade = 'C';
    }
    if (avgGrade < 89.5) {
        letGrade = 'B';
    }
    else {
        letGrade = 'A';
    }
    
    return letGrade;
}
