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
    cout << itr -> getIncomeId() << endl;
    cout << itr -> getUserId() << endl;
    cout << date.changeDateTostring(itr -> getDate()) << endl;
    cout << itr -> getItem() << endl;
    cout << itr -> getAmount() << endl;
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
    cout << itr -> getExpenseId() << endl;
    cout << itr -> getUserId() << endl;
    cout << date.changeDateTostring(itr -> getDate()) << endl;
    cout << itr -> getItem() << endl;
    cout << itr -> getAmount() << endl;
}
