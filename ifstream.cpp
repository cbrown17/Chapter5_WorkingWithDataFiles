//
//  main.cpp
//  Example
//
//  Created by Cassandra  Brown on 4/23/20.
//  Copyright © 2020 Cassandra  Brown. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
   
    //Define file stream input object
    ifstream fin;
    
    //Define variables for opening input file
    char ch;
    string filename;
    
    //Get name of the input file from the keyboard/user
    cout << "Input complete file name: " << endl;
    cin >> filename;
    
    
    //Attempt to open input file
    fin.open(filename);
    if(fin.fail())
    {
        do
        {
            cerr << "Error opening input file" << filename << endl;
            cerr << "Would you like to enter a new filename?" << "Enter y for yes" ;
            cin >> ch;
            
            if(toupper(ch) != 'Y')
            {
                exit(1);
            }
            else
            {
                cerr << "Input complete file name: " << endl;
                cin >> filename;
                fin.clear();//clear error state
                //Attempt to open input file
                fin.open(filename,ios::app);
            }// end else
                
        }while(fin.fail());
    }
    cout << filename << "has been opened successfully..." << endl;
    
    //fin >> x >> y ;
    return 0;
}
