#ifndef ADJUVANTMETHODS_H
#define ADJUVANTMETHODS_H

#include <iostream>
#include <sstream>
#include <windows.h>
#include <ctime>
#include <string>

using namespace std;

class AdjuvantMethods
{
    static bool isFloatNumber(string input);
public:
    static char getChar();
    static string getLine();
    static string intToStringConversion(int number);
    static int stringToIntConversion(string snumber);
    static string floatToStringConversion(float fnumber);
    static float stringToFloatConversion(string snumber);
    static bool isLetter(char choice);
    static float getFloatNumber();
};

#endif // ADJUVANTMETHODS_H
