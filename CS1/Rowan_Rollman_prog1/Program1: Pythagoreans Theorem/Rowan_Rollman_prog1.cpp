//
//  Rowan_Rollman_prog1.cpp
//  Program1: Pythagorean Theorem
//
//  Created by Rowan Rollman on 9/2/20.
//  Copyright © 2020 Rowan Rollman. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    //Library of variables
    float Side_a, Side_b, Side_c;
    
    //Input for first triangle
    cout << "Please enter length of Side_a: ";
    cin >> Side_a;
    cout << "Please enter length of Side_b: ";
    cin >> Side_b;
    
    //Hypotenuse Calculation
    Side_c = sqrt(pow(Side_a, 2) + pow(Side_b, 2));
    
    //Output length of the hypotenuse
    cout << "The length of the hypotenuse is: ";
    cout << Side_c << endl;
    
    //New library for new variables
    float Side_x, Side_y, Side_z;
    
    //Inputs for new triangle
    cout << "This next step will be looking for " << endl;
    cout << "unknown Side_y." << endl;
    cout << "Please enter length of the hypotenuse: ";
    cin >> Side_z;
    cout << "Please enter the length of Side_x: ";
    cin >> Side_x;
    
    //Side Calculation
    Side_y = sqrt(pow(Side_z, 2) - pow(Side_x, 2));
    
    //Output the length of unknown Side_y
    cout << "The length of the previously unknown Side_y is: ";
    cout << Side_y << endl;
    
    
    return 0;
    
}
