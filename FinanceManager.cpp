#include "FinanceManager.h"

void FinanceManager::addIncome()
{
    Income income;
    income = provideNewIncomeData();
    bool isIncomeAdded = false;

    incomes.push_back(income);
    isIncomeAdded = incomesFile.addIncomeToXmlFile(income,date);

    if(isIncomeAdded)
        cout << endl << "The income has been successfully added." << endl;

    system ("pause");
}
Income FinanceManager::provideNewIncomeData()
{
    string item = "";
    float amount = 0;
    char choice;

    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    date.getDateFromUser();
    cout << "Enter item: ";
    cin.sync();
    item = AdjuvantMethods::getLine();
    cout << "Enter amount: ";
    amount = AdjuvantMethods::getFloatNumber();

    income.setIncomeId(incomesFile.getLastIncomeId() + 1);
    income.setUserId(CURRENT_USER_ID);
    income.setDate(date.getDateInteger());
    income.setItem(item);
    income.setAmount(amount);

    return income;
}
void FinanceManager::addExpense()
{
    Expense expense;
    expense = provideNewExpenseData();
    bool isExpenseAdded = false;

    expenses.push_back(expense);
    isExpenseAdded = expensesFile.addExpenseToXmlFile(expense,date);

    if(isExpenseAdded)
        cout << endl << "The expense has been successfully added." << endl;

    system ("pause");
}
Expense FinanceManager::provideNewExpenseData()
{
    string item = "";
    float amount = 0;
    char choice;

    Expense expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    date.getDateFromUser();
    cout << "Enter item: ";
    cin.sync();
    item = AdjuvantMethods::getLine();
    cout << "Enter amount: ";
    amount = AdjuvantMethods::getFloatNumber();

    expense.setExpenseId(expensesFile.getLastExpenseId() + 1);
    expense.setUserId(CURRENT_USER_ID);
    expense.setDate(date.getDateInteger());
    expense.setItem(item);
    expense.setAmount(amount);

    return expense;
}
/*void FinanceManager::viewAllIncomes()
{
    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        viewIncome(itr);
        cout << endl;
    }
    system("pause");
}*/
void FinanceManager::viewIncome(vector <Income>::iterator itr)
{
    cout << "Income ID:   " << itr -> getIncomeId() << endl;
    cout << "User ID:     " << itr -> getUserId() << endl;
    cout << "Date:        " << date.changeDateTostring(itr -> getDate()) << endl;
    cout << "Item:        " << itr -> getItem() << endl;
    cout << "Amount:      " << itr -> getAmount() << endl;
}
/*void FinanceManager::viewAllExpenses()
{
    for (vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        viewExpense(itr);
        cout << endl;
    }
    system("pause");
}*/
void FinanceManager::viewExpense(vector <Expense>::iterator itr)
{
    cout << "Expense ID:  " << itr -> getExpenseId() << endl;
    cout << "User ID:     " << itr -> getUserId() << endl;
    cout << "Date:        " << date.changeDateTostring(itr -> getDate()) << endl;
    cout << "Item:        " << itr -> getItem() << endl;
    cout << "Amount:      " << itr -> getAmount() << endl;
}
void FinanceManager::viewCurrentMonthBalance()
{
    int currentDate = date.changeDateToIntNumber(date.getCurrentDateFromSystem());
    int minDate = (currentDate/100)*100 + 1;
    int maxDate = (currentDate/100 + 1)*100;

    system("cls");

    sortIncomesByDate();
    cout << ">>> INCOMES OF CURRENT MONTH  <<<\n" << endl;
    viewSelectedIncomes(minDate, maxDate);


    sortExpensesByDate();
    cout << ">>> EXPENSES OF CURRENT MONTH <<<\n" << endl;
    viewSelectedExpenses(minDate, maxDate);

    cout << ">>>   CURRENT MONTH SUMMARY   <<<\n" << endl;
    cout << "\nTotal income:     " << totalIncome << endl;
    cout << "Total expense:    " << totalExpense << endl;
    cout << "Month Balance:    " << showpos << totalIncome - totalExpense << endl << endl;
    cout << noshowpos;

    totalIncome = 0;
    totalExpense = 0;

    system("pause");
}
void FinanceManager::sortIncomesByDate()
{
    sort(incomes.begin(), incomes.end(), Income());
}
void FinanceManager::sortExpensesByDate()
{
    sort(expenses.begin(), expenses.end(), Expense());
}
void FinanceManager::viewSelectedIncomes(int minDate, int maxDate)
{
    bool incomeExist = false;
    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        int date = itr -> getDate();
        if(date >= minDate && date <= maxDate)
        {
            incomeExist = true;
            calculateTotalIncome(itr);
            viewIncome(itr);
            cout << endl;
        }
    }
    if (!incomeExist)
        cout << "There were no incomes.\n" << endl;
}
void FinanceManager::viewSelectedExpenses(int minDate, int maxDate)
{
    bool expenseExist = false;
    for (vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        int date = itr -> getDate();
        if(date >= minDate && date <= maxDate)
        {
            expenseExist = true;
            calculateTotalExpense(itr);
            viewExpense(itr);
            cout << endl;
        }
    }
    if (!expenseExist)
        cout << "There were no expenses.\n" << endl;
}
void FinanceManager::calculateTotalIncome(vector <Income>::iterator itr)
{
    totalIncome += itr -> getAmount();
}
void FinanceManager::calculateTotalExpense(vector <Expense>::iterator itr)
{
    totalExpense += itr -> getAmount();
}
void FinanceManager::viewLastMonthBalance()
{
    int currentDate = date.changeDateToIntNumber(date.getCurrentDateFromSystem());
    int minDate = (currentDate/100 - 1)*100 + 1;
    int maxDate = (currentDate/100)*100;

    system("cls");

    sortIncomesByDate();
    cout << ">>> INCOMES OF LAST MONTH  <<<\n" << endl;
    viewSelectedIncomes(minDate, maxDate);


    sortExpensesByDate();
    cout << ">>> EXPENSES OF LAST MONTH <<<\n" << endl;
    viewSelectedExpenses(minDate, maxDate);

    cout << ">>>   LAST MONTH SUMMARY   <<<\n" << endl;
    cout << "\nTotal income:     " << totalIncome << endl;
    cout << "Total expense:    " << totalExpense << endl;
    cout << "Month Balance:    " << showpos << totalIncome - totalExpense << endl << endl;
    cout << noshowpos;

    totalIncome = 0;
    totalExpense = 0;

    system("pause");
}
void FinanceManager::viewBalanceOfSelectedPeriod()
{
    system("cls");

    int date1 = 0, date2 = 0, minDate = 0, maxDate = 0;
    cout << "Enter a start date and an end date of period that you want to review: " << endl;
    cout << "\nEnter a start date: " << endl;
    date.getDateFromUser();
    date1 = date.getDateInteger();
    cout << "\nEnter an end date: " << endl;
    date.getDateFromUser();
    date2 = date.getDateInteger();

    if (date1 < date2)
    {
        minDate = date1;
        maxDate = date2;
    }
    else
    {
        minDate = date2;
        maxDate = date1;
    }

    system("cls");

    sortIncomesByDate();
    cout << ">>> INCOMES OF SELECTED PERIOD  <<<\n" << endl;
    viewSelectedIncomes(minDate, maxDate);


    sortExpensesByDate();
    cout << ">>> EXPENSES OF SELECTED PERIOD <<<\n" << endl;
    viewSelectedExpenses(minDate, maxDate);

    cout << ">>>   SELECTED PERIOD SUMMARY   <<<\n" << endl;
    cout << "\nTotal income:     " << totalIncome << endl;
    cout << "Total expense:    " << totalExpense << endl;
    cout << "Month Balance:    " << showpos << totalIncome - totalExpense << endl << endl;
    cout << noshowpos;

    totalIncome = 0;
    totalExpense = 0;

    system("pause");
}
