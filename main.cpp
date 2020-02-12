#include <iostream>

#include "Budget.h"

using namespace std;

int main()
{
    Budget budget("users.xml", "incomes.xml", "expenses.xml");
    char choice;

    while (true)
    {
        if (!budget.isUserLoggedIn())
        {
            cin.sync();
            choice = budget.selectFromMainMenu();

            switch (choice)
            {
            case '1':
                budget.userSignUp();
                break;
            case '2':
                budget.userSignIn();
                break;
            case '3':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in the menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            cin.sync();
            choice = budget.selectFromUserMenu();

            switch (choice)
            {
            case '1':
                budget.addIncome();
                break;
            case '2':
                budget.addExpense();
                break;
            case '3':
                //budget.viewCurrentMonthBalance();
                break;
            case '4':
                //budget.viewLastMonthBalance();
                break;
            case '5':
                //budget.viewBalanceOfSelectedPeriod();
                break;
            case '6':
                //budget.changeCurrentUserPassword();
                break;
            case '7':
                budget.userSignOut();
                break;
            case '8':
                budget.viewAllIncomes();
                break;
            case '9':
                budget.viewAllExpenses();
            }
        }
    }
    return 0;
}
