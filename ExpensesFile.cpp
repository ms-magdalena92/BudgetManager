#include "ExpensesFile.h"

vector<Expense> ExpensesFile::loadExpensesOfCurrentUserFromXmlFile(int CURRENT_USER_ID)
{
    Date date;
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
            expenseId = atoi((xml.GetElemContent()).c_str());
            xml.FindElem("UserId");
            if (atoi((xml.GetElemContent()).c_str()) == CURRENT_USER_ID)
            {
                expense.setUserId(CURRENT_USER_ID);
                expense.setExpenseId(expenseId);
                xml.FindElem("Date");
                expense.setDate(date.changeDateToIntNumber(xml.GetElemContent()));
                xml.FindElem("Item");
                expense.setItem(xml.GetElemContent());
                xml.FindElem("Amount");
                expense.setAmount(atof((xml.GetElemContent()).c_str()));
                expenses.push_back(expense);
            }
            xml.OutOfElem();
        }
    }
    return expenses;
}
void ExpensesFile::addExpenseToXmlFile(Expense expense, Date date)
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
