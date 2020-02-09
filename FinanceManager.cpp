#include "FinanceManager.h"

void FinanceManager::addIncome()
{
    Income income;
    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = provideNewIncomeData();

    incomes.push_back(income);
    incomesFile.addIncomeToXmlFile(income);
    cout << endl << "The item was successfully added." << endl;
}

Income FinanceManager::provideNewIncomeData()
{
    string sdate, item;
    double amount;
    int date;

    Income income;

    cout << "Enter date (yyyy-mm-dd): ";

    while (true)
    {
        sdate = AdjuvantMethods::getLine();

        if(AdjuvantMethods::isDateCorrect(sdate))
        {
            date = AdjuvantMethods::changeDateToIntNumber(sdate);
            break;
        }
        else
            cout << "Date is not valid. Enter the date again." << endl;
    }
    cout << "Enter item: ";
    cin.sync();
    item = AdjuvantMethods::getLine();
    cout << "Enter amount: ";
    cin >> amount;

    income.setIncomeId(incomesFile.getLastIncomeId() + 1);
    income.setUserId(CURRENT_USER_ID);
    income.setDate(date);
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
