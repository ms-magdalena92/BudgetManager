#ifndef BUDGET_H
#define BUDGET_H

#include "UserManager.h"

using namespace std;

class Budget
{
    UserManager userManager;

public:
    Budget(string usersFilename):userManager(usersFilename)
    {};
    ~Budget()
    {}
    void userSignUp();
    void userSignIn();
    void userSignOut();
    void viewAllUsers();
    bool isUserLoggedIn();
    char selectFromMainMenu();
    char selectFromUserMenu();
};

#endif // BUDGET_H
