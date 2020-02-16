#include "ExpensesFile.h"

vector<Expense> ExpensesFile::loadExpensesOfCurrentUserFromXmlFile(int CURRENT_USER_ID)
{
    CMarkup xml;
    vector <Expense> expenses;
    int expenseId = 0;

    if (fileExist(xml))
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Expense"))
        {
            Expense expense;
            xml.IntoElem();
            xml.FindElem("ExpenseId");
            expenseId = AdjuvantMethods::stringToIntConversion(xml.GetElemContent());
            xml.FindElem("UserId");
            if(AdjuvantMethods::stringToIntConversion(xml.GetElemContent()) == CURRENT_USER_ID)
            {
                expense.setUserId(CURRENT_USER_ID);
                expense.setExpenseId(expenseId);
                xml.FindElem("Date");
                expense.setDate(date.changeDateToIntNumber(xml.GetElemContent()));
                xml.FindElem("Item");
                expense.setItem(xml.GetElemContent());
                xml.FindElem("Amount");
                expense.setAmount(AdjuvantMethods::stringToFloatConversion(xml.GetElemContent()));
                expenses.push_back(expense);
            }
            xml.OutOfElem();
        }
    }
    return expenses;
}
bool ExpensesFile::addExpenseToXmlFile(Expense expense, Date date)
{
    CMarkup xml;

    if (!fileExist(xml))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", date.getDateString());
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", AdjuvantMethods::floatToStringConversion(expense.getAmount()));
    xml.OutOfElem();
    xml.Save(getFilename());
    lastExpenseId++;
    if (!fileExist(xml))
    {
        cout << "Cannot open the " << getFilename() << " file." << endl;
        return false;
    }
    return true;
}
int ExpensesFile::getLastExpenseIdFromFile()
{
    CMarkup xml;
    vector <Expense> expense;

    if (fileExist(xml))
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Expense"))
        {
            xml.FindChildElem("ExpenseId");
        }
        return lastExpenseId = AdjuvantMethods::stringToIntConversion(xml.GetChildData());;
    }
    else
        return 0;
}
int ExpensesFile::getLastExpenseId()
{
    return lastExpenseId;
}
