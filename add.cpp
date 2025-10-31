/*
EECS 348 – Lab 10
Pranav Reddy
valid.cpp
string addition done manually for both fractional and whole parts with carry as needed 
*/
#include "add.h"   //include the header so main can see this fn
string addStr(const string &a, const string &b) {
    //dec point position
    int dotA = a.find('.');  //look for decimal in first num
    int dotB = b.find('.');  //look for decimal in second num

    //splitting whole and fractional
    //whole part is before the decimal
    //if no decimal then whole part is full str
    string wholeA;
    if (dotA == -1) { 
        wholeA = a; 
    } else { 
        wholeA = a.substr(0, dotA); //take chars before decimal
    }

    string wholeB; //same for B
    if (dotB == -1) { 
        wholeB = b; 
    } else { 
        wholeB = b.substr(0, dotB);
    }

    //frac part after the decimal
    //if no decimal then frac is empty
    string fracA;
    if (dotA == -1) { 
        fracA = ""; 
    } else { 
        fracA = a.substr(dotA + 1); 
    }

    string fracB; //same for fracB
    if (dotB == -1) { 
        fracB = ""; 
    } else { 
        fracB = b.substr(dotB + 1); 
    }

    //padding with 0's so smaller becomes same length
    while (fracA.size() < fracB.size()) fracA += '0';
    while (fracB.size() < fracA.size()) fracB += '0';

    //adding frac digits
    string fracRes = "";   //frac answer
    int carry = 0;   //carry like normal math
    for (int i = fracA.size() - 1; i >= 0; i--) { //start at end, move left, adding each digit
        int sum = (fracA[i] - '0') + (fracB[i] - '0') + carry; //convert char to int and add
        carry = sum / 10;   //update carry
        char digit = (sum % 10) + '0';   //convert back to char
        fracRes = digit + fracRes;   //put digit in front
    }

    //padding for whole now
    while (wholeA.size() < wholeB.size()) wholeA = '0' + wholeA;
    while (wholeB.size() < wholeA.size()) wholeB = '0' + wholeB;

    //adding digits but for whole
    string wholeRes = "";  //final ans

    for (int i = wholeA.size() - 1; i >= 0; i--) { //same loop as prev but for whole part now
        int sum = (wholeA[i] - '0') + (wholeB[i] - '0') + carry;
        carry = sum / 10;
        char digit = (sum % 10) + '0';
        wholeRes = digit + wholeRes; //put digit in front
    }

    //final carry leftover, add in front
    if (carry) {
        wholeRes = '1' + wholeRes;
    }


    //if there is frac ans then add
    if (fracRes != "") {
        return wholeRes + "." + fracRes;  
    } 
    //else no decimal
    else {
        return wholeRes;  //just whole num ans
    }
}
