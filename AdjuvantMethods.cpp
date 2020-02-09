#include "AdjuvantMethods.h"

char AdjuvantMethods::getChar()
{
    string choice = "";

    while (true)
    {
        getline(cin, choice);

        if (choice.length() == 1)
        {
            return choice[0];
        }
        cout << "This is not a single character. Enter the character again." << endl;
    }
}
string AdjuvantMethods::getLine()
{
    string input = "";
    getline(cin, input);
    return input;
}
bool AdjuvantMethods::isDateCorrect(string date)
{
    string dateElement;
    int year, month, day;
    stringstream ss(date);
    getline(ss, dateElement, '-');
    year = stringToIntConversion(dateElement);
    getline(ss, dateElement, '-');
    month = stringToIntConversion(dateElement);
    getline(ss, dateElement);
    day = stringToIntConversion(dateElement);

    int maxYear = 2020; // uzupelnic o funckje pobierajaca date z systemu
    int minYear = 2000;

    if (year > maxYear || year < minYear)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    if (month == 2)
    {
        if (isYearLeap(year))
            return day <= 29;
        else
            return day <= 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return day <= 30;

    return true;
}
bool AdjuvantMethods::isYearLeap (int year)
{
    if ((year%4==0 && year%100!=0) || year%400==0)
        return true;
    else
        return false;
}
string AdjuvantMethods::intToStringConversion(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
int AdjuvantMethods::stringToIntConversion(string snumber)
{
    int number;
    istringstream iss(snumber);
    iss >> number;
    return number;
}
int AdjuvantMethods::changeDateToIntNumber(string sdate)
{
    string dateElement="", date="";
    stringstream ss(sdate);
    getline(ss, dateElement, '-');
    date+=dateElement;
    getline(ss, dateElement, '-');
    date+=dateElement;
    getline(ss, dateElement);
    date+=dateElement;
    return stringToIntConversion(date);
}
string AdjuvantMethods::changeIntDateTOString(int date)
{
    return "date";
}

