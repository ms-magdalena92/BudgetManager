#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <sstream>
#include <windows.h>
#include <ctime>

#include "AdjuvantMethods.h"

using namespace std;

class Date
{
    int dateInteger;
    int year, month, day;

    string dateString;
    string syear, smonth, sday;

    string createDate();
    bool isYearLeap ();
    bool isDateInProperRange(int date);
    bool isDateCorrect();
public:
    Date()
    {
        dateInteger = 0;
        dateString = "";
        year = 0;
        month = 0;
        day = 0;
        syear = "";
        smonth = "";
        sday = "";
    }
    string getDateString();
    int getDateInteger();
    string getCurrentDateFromSystem();
    int changeDateToIntNumber(string sdate);
    void getDate();
};

#endif // DATE_H
