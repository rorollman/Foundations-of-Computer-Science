//
//  main.cpp
//  Rowan_Rollman_prog3
//
//  Created by Rowan Rollman on 9/17/20.
//  Copyright © 2020 Rowan Rollman. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    //define variables
    int num, aux;
    
    //get user input
    cout << "Please enter the number of a highway (range 1-999): ";
    cin >> num;
    
    //error checking for invalid numbers
    if (num<1 || num>999) {
        cout << "Incorrect number. Please enter again: ";
        cin >> num;
        if (num<1 || num>999) {
            cout << "You are not paying attention. Please read the manual." << endl;
            cout << "Program exiting." << endl;
            return -1;
        }
    }
    
    //finding primary highways
    if (num<99 && num>1) {
        cout << "I-" << num << " is primary,";
        if (num%2 == 0) {
            cout << ", going east/west." << endl;
        } else {
            cout << ", going north/south." << endl;
        }
    }
    //finding auxiliary highways
    else {
        aux = num%100;
        cout << "I-" << num << " is auxiliary, serving I-" << aux;
        if (num%2 == 0) {
            cout << ", going east/west." << endl;
        } else {
            cout << ", going north/south." << endl;
        }
    }
    //exiting program
    return 0;
}
