#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include "XmlFile.h"
#include "Income.h"
#include "Expense.h"

using namespace std;

class ExpensesFile : public XmlFile
{
    int lastExpenseId;
    Date date;

    int getLastExpenseIdFromFile();
public:
    ExpensesFile(string expensesFilename):XmlFile(expensesFilename)
    {
        lastExpenseId = getLastExpenseIdFromFile();
    };
    vector<Expense> loadExpensesOfCurrentUserFromXmlFile(int CURRENT_USER_ID);
    void addExpenseToXmlFile(Expense expense, Date date);
    int getLastExpenseId();
};

#endif // EXPENSESFILE
