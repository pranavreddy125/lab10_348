/*
EECS 348 – Lab 10
Pranav Reddy
valid.cpp
check to see if str is valid double, rules specified in lab manual
*/
#include "valid.h" //now can use isValid
#include <cctype>   //isdigit() fn to check if char is a number
bool isValid(const string &s) { //isValid function used to check if number is valid double num
    int index = 0; //curr index set to 0
    int len = s.size(); //getting length and storing
    bool hasDigit = false; //to track if have already seen 1 number
    bool hasDot = false; //to track if seen 1 decimal point already
    if (s[index] == '+' || s[index] == '-') { //skip the + or - at the beginning
        index++; //increment index and keep going as needed
    }

    for (; index < len; index++) { //looping through each char
        char c = s[index]; //getting curr char
        if (isdigit(c)) {   //if its a num then hasDigit goes true
            hasDigit = true;
        } 
        else if (c == '.') {     //if already seen a dot then mark as invalid
            if (hasDot) return false; 
            hasDot = true; //marking that dot was spotted
        } 
        else {     //everything else is invalid false
            return false;
        }
    }
    if (!hasDigit) return false; //needs to have 1 digit, cant start or end with dot as per instructions
    if (s[0] == '.' || s[len - 1] == '.') return false;

    return true; //if passes everything then its valid
}
