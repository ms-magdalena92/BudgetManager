#ifndef BUDGET_H
#define BUDGET_H

#include "UserManager.h"
#include "FinanceManager.h"

using namespace std;

class Budget
{
    UserManager userManager;
    FinanceManager *financeManager;
    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;

public:
    Budget(string usersFilename, string incomesFilename, string expensesFilename)
    :userManager(usersFilename), INCOMES_FILENAME(incomesFilename), EXPENSES_FILENAME(expensesFilename)
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
    void addExpense();
    void viewAllIncomes();
    void viewAllExpenses();
    void viewCurrentMonthBalance();
    void viewLastMonthBalance();
    void viewBalanceOfSelectedPeriod();
};

#endif // BUDGET_H
