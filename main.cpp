#include <iostream>

#include "Budget.h"

using namespace std;

int main()
{
    Budget budget("users.xml");
    budget.userSignIn();
    return 0;
}
