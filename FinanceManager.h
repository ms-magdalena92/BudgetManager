#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "Income.h"
#include "Expense.h"
#include "AdjuvantMethods.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"
#include "Date.h"

using namespace std;

class FinanceManager
{
    const int CURRENT_USER_ID;
    vector<Income> incomes;
    vector<Expense> expenses;
    IncomesFile incomesFile;
    ExpensesFile expensesFile;
    Date date;

    Income provideNewIncomeData();
    Expense provideNewExpenseData();
public:
    FinanceManager(int currentUserId, string incomesFilename, string expensesFilename)
    : CURRENT_USER_ID(currentUserId), incomesFile(incomesFilename), expensesFile(expensesFilename)
    {
        incomes = incomesFile.loadIncomesOfCurrentUserFromXmlFile(CURRENT_USER_ID);
        expenses = expensesFile.loadExpensesOfCurrentUserFromXmlFile(CURRENT_USER_ID);
    };
    void addIncome();
    void addExpense();
    void viewAllIncomes();
};

#endif // FINANSEMANAGER_H
