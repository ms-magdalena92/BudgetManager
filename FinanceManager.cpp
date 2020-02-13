#include "FinanceManager.h"

void FinanceManager::addIncome()
{
    Income income;
    income = provideNewIncomeData();

    incomes.push_back(income);
    incomesFile.addIncomeToXmlFile(income,date);
    cout << endl << "The income was successfully added." << endl;
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
    cout << "Do you want to add income with today's date? (Y/N)" << endl;
    date.getDate();
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

    expenses.push_back(expense);
    expensesFile.addExpenseToXmlFile(expense,date);
    cout << endl << "The expense was successfully added." << endl;
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
    cout << "Do you want to add expense with today's date? (Y/N)" << endl;
    date.getDate();
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
void FinanceManager::viewAllIncomes()
{
    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        viewIncome(itr);
        cout << endl;
    }
    system("pause");
}
void FinanceManager::viewIncome(vector <Income>::iterator itr)
{
    cout << "Income ID:   " << itr -> getIncomeId() << endl;
    cout << "User ID:     " << itr -> getUserId() << endl;
    cout << "Date:        " << date.changeDateTostring(itr -> getDate()) << endl;
    cout << "Item:        " << itr -> getItem() << endl;
    cout << "Amount:      " << itr -> getAmount() << endl;
}
void FinanceManager::viewAllExpenses()
{
    for (vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        viewExpense(itr);
        cout << endl;
    }
    system("pause");
}
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
    int minDate = (currentDate/100)*100;
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
    cout << "Month Balance:    " << totalIncome - totalExpense << endl << endl;

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
        if(date > minDate && date < maxDate)
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
        if(date > minDate && date < maxDate)
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
