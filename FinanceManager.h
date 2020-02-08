#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "Income.h"
#include "Expense.h"
#include "AdjuvantMethods.h"

using namespace std;

class FinanceManager
{
    const int CURRENT_USER_ID;
    vector<Income> incomes;
    vector<Expense> expenses;

    Income provideNewIncomeData();
    int getNewIncomeId();

public:
    FinanceManager(int currentUserId)
    : CURRENT_USER_ID(currentUserId)
    {};
    void addIncome();
    void viewAllIncomes();
};

#endif // FINANSEMANAGER_H
