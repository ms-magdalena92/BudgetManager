#ifndef BUDGET_H
#define BUDGET_H

#include "UserManager.h"
#include "FinanceManager.h"

using namespace std;

class Budget
{
    UserManager userManager;
    FinanceManager *financeManager;

public:
    Budget(string usersFilename):userManager(usersFilename)
    {
        financeManager = NULL;
    };
    ~Budget()
    {
        delete financeManager;
        financeManager = NULL;
    }
    void userSignUp();
    void userSignIn();
    void userSignOut();
    void viewAllUsers();
    bool isUserLoggedIn();
    char selectFromMainMenu();
    char selectFromUserMenu();
    void addIncome();
    void viewAllIncomes();
};

#endif // BUDGET_H
