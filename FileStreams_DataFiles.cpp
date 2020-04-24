//
//  main.cpp
//  Chapter_5_DataFiles
//
//  Created by Cassandra  Brown on 4/21/20.
//  Copyright © 2020 Cassandra  Brown. All rights reserved.
//
/* This program reads data pairs from the file sensor.txt and writes valid data pairs to the
 file checkSensor.txt. Valid data pairs may not be negative. Invalid data is written to standard error(cerr)*/


#include <iostream>
#include <fstream> //required for ifstream ofstream stream class functions

using namespace std;

int main(int argc, const char * argv[]) {
    
    //Define file streams for input and output
    ifstream fin("/Volumes/SD/School/ENGR2230/Assignments/Chapter_5_DataFiles/sensor3.txt"); //input file
    ofstream fout("/Volumes/SD/School/ENGR2230/Assignments/Chapter_5_DataFiles/checkedSensor.txt");  //output file
    
    //check for possible errors
    if(fin.fail())
    {
        cerr << "could not open input file sensor.txt\n";
        exit(1);
    }
    if(fout.fail())
    {
        cerr << "could not open output file sensor.txt\n";
        exit(1);
    }
    
    //All files are open.
    double t, motion;
    int count=0;
    fin >> t >> motion;
    while (!fin.eof()) {
        ++count;
        
        //Write valid data to output file.
        if(t >= 0 && motion >=0)
        {
            fout << t << " " << motion << endl;
        }
        //Write invald data to standard error output.
        else
        {
            cerr << "bad data encountered on line" << count << endl << t  << " " << motion << endl;
        }
        //Input next data pair
        fin >> t >> motion;
    
    }//end wille
    return 0;
}
