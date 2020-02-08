#ifndef ADJUVANTMETHODS_H
#define ADJUVANTMETHODS_H

#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

class AdjuvantMethods
{
    static bool isYearLeap (int year);

public:
    static char getChar();
    static string getLine();
    static bool isDateCorrect(string date);
    static string intToStringConversion (int number);
    static int stringToIntConversion(string snumber);
    static int changeDateToIntNumber(string sdate);
};

#endif // ADJUVANTMETHODS_H
