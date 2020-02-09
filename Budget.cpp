#include "Budget.h"

void Budget::userSignUp()
{
    userManager.userSignUp();
}
void Budget::userSignIn()
{
    userManager.userSignIn();
    if (userManager.isUserLoggedIn())
    {
        financeManager = new FinanceManager(userManager.getCurrentUserId(), INCOMES_FILENAME);
    }
}
void Budget::userSignOut()
{
    userManager.userSignOut();
    delete financeManager;
    financeManager = NULL;

}
void Budget::viewAllUsers()
{
    userManager.viewAllUsers();
}
bool Budget::isUserLoggedIn()
{
    userManager.isUserLoggedIn();
}
char Budget::selectFromMainMenu()
{
    userManager.selectFromMainMenu();
}
char Budget::selectFromUserMenu()
{
    userManager.selectFromUserMenu();
}
void Budget::addIncome()
{
    financeManager -> addIncome();
}
void Budget::viewAllIncomes()
{
    financeManager -> viewAllIncomes();
}
