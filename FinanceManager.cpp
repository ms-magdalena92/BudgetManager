#include "FinanceManager.h"

void FinanceManager::addIncome()
{
    Income income;
    income = provideNewIncomeData();

    incomes.push_back(income);
    incomesFile.addIncomeToXmlFile(income,date);
    cout << endl << "The item was successfully added." << endl;
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
void FinanceManager::viewAllIncomes()
{
    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        cout << itr -> getIncomeId() << endl;
        cout << itr -> getUserId() << endl;
        cout << itr -> getDate() << endl;
        cout << itr -> getItem() << endl;
        cout << itr -> getAmount() << endl;
    }
    system("pause");
}
