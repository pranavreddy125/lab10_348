/*
EECS 348 – Lab 10
Pranav Reddy
valid.cpp
check to see if str is valid double, rules specified in lab manual
*/
#include "valid.h" //now can use isValid
#include <cctype>   //isdigit() fn to check if char is a num, wasn't working the previous way
bool isValid(const string &s) {
    int i = 0; //for index ptr
    int n = s.size(); //store len

    if (n == 0) return false;  //empty string no good

    //skip sign if first char
    if (s[i] == '+' || s[i] == '-') i++;

    bool digitBefore = false; //tracking if digit before decimal
    bool digitAfter = false; //tracking if digit after decimal
    bool hasDot = false; //tracking if decimal seen

    for (; i < n; i++) { //loop through char
        char c = s[i]; //curr char

        if (isdigit(c)) { //if number
            if (!hasDot) digitBefore = true; //digit before decimal
            else digitAfter = true; //digit after decimal
        }
        else if (c == '.') { //if dot found
            if (hasDot) return false; //only one dot allowed
            hasDot = true; //mark as seen then
        }
        else {
            return false; //not digit or dot
        }
    }

    if (!digitBefore) return false;//must have digit before dot


    if (hasDot && !digitAfter) return false;    //if dot exists, must have digit after

    return true;
}