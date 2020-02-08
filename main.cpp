#include <iostream>

#include "Budget.h"

using namespace std;

int main()
{
    Budget budget("users.xml");
    budget.viewAllUsers();
    budget.userSignUp();
    budget.userSignUp();
    budget.viewAllUsers();
    return 0;
}
