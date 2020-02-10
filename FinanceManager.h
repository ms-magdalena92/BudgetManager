#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "Income.h"
#include "Expense.h"
#include "AdjuvantMethods.h"
#include "IncomesFile.h"
#include "Date.h"

using namespace std;

class FinanceManager
{
    const int CURRENT_USER_ID;
    vector<Income> incomes;
    vector<Expense> expenses;
    IncomesFile incomesFile;
    Date date;

    Income provideNewIncomeData();
    int getNewIncomeId();

public:
    FinanceManager(int currentUserId, string incomesFilename)
    : CURRENT_USER_ID(currentUserId), incomesFile(incomesFilename)
    {
        incomes = incomesFile.loadIncomesOfCurrentUserFromXmlFile(CURRENT_USER_ID);
    };
    void addIncome();
    void viewAllIncomes();
};

#endif // FINANSEMANAGER_H
