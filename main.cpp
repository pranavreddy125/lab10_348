/*
EECS 348 – Lab 10
Pranav Reddy
main.cpp
For reading file, looping over lines, and calling functions
*/
#include <iostream>
#include <fstream> //reading from file
#include <string>
#include "valid.h"
#include "add.h"
using namespace std;

int main() {
    string filename; //filename that the user types
    cin >> filename; //reading that file name

    ifstream fin(filename); //opening the file to read

    string a; //to hold the string
    string b; //to hold the string
    while (fin >> a >> b) { //keeps looping as long as still two nums in the file
        bool validA = isValid(a); //check to see if valid num, calling function
        bool validB = isValid(b); //check to see if valid num
        if (validA && validB) { //if both valid then add and print result
            string sum = addStr(a, b);
            cout << sum << endl;
        } else { //if atleast one is invalid then print that
            cout << "invalid number" << endl;
        }
    }

    return 0;
}