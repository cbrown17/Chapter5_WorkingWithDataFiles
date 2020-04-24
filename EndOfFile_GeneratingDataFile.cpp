//
//  main.cpp
//  Chapter5_4
//
//  Created by Cassandra  Brown on 4/23/20.
//  Copyright © 2020 Cassandra  Brown. All rights reserved.
//
/* This program generates a summary report from a data file that has the number of data points in the first record*/

#include <iostream> //Required for cerr, cin, cout
#include <fstream> //Required for ifstream, ofstream
#include <string> //Required for string

using namespace std;

int main(int argc, const char * argv[]) {
    //Declare and initialize objects
    int num_data_pts = 0;
    double time, motion, sum=0, max=0, min=0;
    string filename;
    ifstream sensor3;
    ofstream report;
    
    //Prompt user for name of input file.
    cout << "Enter the name of the input file" << endl;
    cin >> filename;
    
    //Open file and read the number of data points
    sensor3.open(filename);
    if( sensor3.fail())
    {
        cerr << "Error opening input file\n" << filename << endl;
        exit(1);
    }
    
    //Open report file
    report.open("/Volumes/SD/School/ENGR2230/Assignments/Chapter_5_DataFiles/sensorReport3.txt");
    
    
    //While not at the end og the file, read and acummulate information
    sensor3 >> time >> motion; //initial input
    
    while(!sensor3.eof()) //hasn't reached -99 (the indicator)
    {
        num_data_pts++;
        if(num_data_pts == 1)
        {
            max = min = motion;
        }
        sum += motion;
        if( motion > max)
        {
            max = motion;
        }
        if( motion < min)
        {
            min = motion;
        }
        sensor3 >> time >> motion; //input next
    }
    
    //set format flags.
    report.setf(ios::fixed);
    report.setf(ios::showpoint);
    report.precision(2);
    
    //print summary information
    report << "Number of sensor readings:" << num_data_pts << endl;
    report << "Averaging reading:        " << sum/num_data_pts << endl;
    report << "Maximum reading:          " << max << endl;
    report << "Minimum reading:          " << min << endl;
    
    // Close files and exit program
    sensor3.close();
    report.close();
    
    return 0;
} //end main
