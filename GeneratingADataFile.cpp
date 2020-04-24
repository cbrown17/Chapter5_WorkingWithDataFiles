//
//  main.cpp
//  Chapter5_5
//
//  Created by Cassandra  Brown on 4/23/20.
//  Copyright © 2020 Cassandra  Brown. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;


int main(int argc, const char * argv[]) {
   
    //Declare and initialize objects
    double initial, increment, final, time, height, velocity, max_time=0, max_height=0;
    
    int loops, itime;
    string filename;
    ofstream balloon;
    
    //prompt user for name of output file
    cout << "enter the name of the out ";
    cin >> filename;
    
    //get user input
    cout << "Enter initial value for table (in hours) \n";
    cin >> initial;
    cout <<"Enter increment between lines (in hours) \n";
    cin >> increment;
    cout << "Enter final value for table (in hours) \n";
    cin >> final;
    
    //set  flags for standard output
    cout.setf(ios::fixed);
    cout.precision(2);
    
    //Print report heading
    cout << "\n\nWeather Balloon Information \n";
    cout << "Time  Height   Velocity \n";
    cout << "(hrs) (meters) (meters/s) \n";
    
    //Determine number of iteratioins required
    //Use integer index to avoid rounding error
    loops = (int)((final - initial)/increment);
    for(itime=0; itime<=loops; itime++)
    {
        time = initial + itime*increment;
        
        height = -0.12*pow(time, 4) + 12*pow(time, 3)
        - 380 * time*time + 4100*time + 220;
        
        velocity = -0.48*pow(time, 3) + 36*time*time - 760*time + 4100;
    
    
    
    //print report information to screem
    cout << setw(6) << time << setw(10) << height << setw(10)
    << velocity/3600 << endl;
    
    //write report information to a file
    
    balloon << setw(6) << time << setw(10) << height << setw(10)
    << velocity/3600 << endl;
    
    if(height > max_height)
    {
        max_height = height;
        max_time = itime;
    }
    }
    //report maximum height and corresponding time
    cout << "\nMaximum balloon height was" << setw(8) << max_height << "meters\n and it occuured at" << setw(6) << max_time << endl;
    
    //close file and exit program
    balloon.close();
    return 0;
}
