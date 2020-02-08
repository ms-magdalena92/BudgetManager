#include "Budget.h"

void Budget::userSignUp()
{
    userManager.userSignUp();
}
void Budget::userSignIn()
{
    userManager.userSignIn();
}
void Budget::userSignOut()
{
    userManager.userSignOut();
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
