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
