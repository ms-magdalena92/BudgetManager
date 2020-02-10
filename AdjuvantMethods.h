#ifndef ADJUVANTMETHODS_H
#define ADJUVANTMETHODS_H

#include <iostream>
#include <sstream>
#include <windows.h>
#include <ctime>

using namespace std;

class AdjuvantMethods
{
public:
    static char getChar();
    static string getLine();
    static string intToStringConversion (int number);
    static int stringToIntConversion(string snumber);
    static bool isLetter(char choice);
};

#endif // ADJUVANTMETHODS_H
