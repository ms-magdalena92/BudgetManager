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
bool AdjuvantMethods::isLetter(char choice)
{
    if(isdigit(choice))
        return false;
    return true;
}

