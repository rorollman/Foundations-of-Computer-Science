//
//  main.cpp
//  Program 2
//
//  Created by Rowan Rollman on 9/9/20.
//  Copyright © 2020 Rowan Rollman. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //Define the things you are going to be using
    ifstream fin;
    ofstream fout;
    int x, y;
    
    cout << "Opening the input file..." << endl;
    
    //Open the file
    fin.open("points.txt");
    
    //Error checking
    if (!fin) {
        cout << "Cannot open the input file!" << endl;
        return -1;
    }
    
    cout << "Opened the input file succesfully." << endl;
    
    //Read data from the file
    fin >> x >> y;
  
    cout << "Obtained the information from the input file successfully." << endl;
    
    //Close file
    fin.close();
    
    cout << "Opening the output file..." << endl;
    
    //Open output file
    fout.open("points.txt", ios::app);
    
    //Error checking
    if (!fout) {
        cout << "Cannot open the output file, please check that you have permission to write in the file." << endl;
        return -1;
    }
    cout << "The output file is ready." << endl;
    //Formatting
    fout << endl;
    
    //Determining the quadrant
   if (x>0 && y>0) {
        fout << "The point (" << x << "," << y << ") lies in Quadrant I." << endl;
        
    }
   else if (x<0 && y>0) {
       fout << "The point (" << x << "," << y << ") lies in Quadrant II." << endl;
       
   }
   else if (x<0 && y<0) {
       fout << "The point (" << x << "," << y << ") lies in Quadrant III." << endl;
       
   }
   else if (x>0 && y<0) {
       fout << "The point (" << x << "," << y << ") lies in Quadrant IV." << endl;
       
   }
   else if (x==0 && y==0){
       fout << "The point (" << x << "," << y << ") is at the origin." << endl;

   }
   else
       fout << "The point (" << x << "," << y << ") does not lay in any quadrant." << endl;
    
    cout << "The output file has been updated successfully." << endl;
    
    //Close output file
    fout.close();
    
    
    return 0;
   
}
