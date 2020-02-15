#include "IncomesFile.h"

vector<Income> IncomesFile::loadIncomesOfCurrentUserFromXmlFile(int CURRENT_USER_ID)
{
    Date date;
    CMarkup xml;
    vector <Income> incomes;
    int incomeId = 0;

    if (fileExist(xml))
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Income"))
        {
            Income income;
            xml.IntoElem();
            xml.FindElem("IncomeId");
            incomeId = atoi((xml.GetElemContent()).c_str());
            xml.FindElem("UserId");
            if (atoi((xml.GetElemContent()).c_str()) == CURRENT_USER_ID)
            {
                income.setUserId(CURRENT_USER_ID);
                income.setIncomeId(incomeId);
                xml.FindElem("Date");
                income.setDate(date.changeDateToIntNumber(xml.GetElemContent()));
                xml.FindElem("Item");
                income.setItem(xml.GetElemContent());
                xml.FindElem("Amount");
                income.setAmount(AdjuvantMethods::stringToFloatConversion(xml.GetElemContent()));
                incomes.push_back(income);
            }
            xml.OutOfElem();
        }
    }
    return incomes;
}
void IncomesFile::addIncomeToXmlFile(Income income, Date date)
{
    CMarkup xml;

    if (!fileExist(xml))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", date.getDateString());
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", AdjuvantMethods::floatToStringConversion(income.getAmount()));
    xml.OutOfElem();
    xml.Save(getFilename());
    lastIncomeId++;
}
int IncomesFile::getLastIncomeIdFromFile()
{
    CMarkup xml;
    vector <Income> incomes;

    if (fileExist(xml))
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Income"))
        {
            xml.FindChildElem("IncomeId");
        }
        return lastIncomeId = AdjuvantMethods::stringToIntConversion(xml.GetChildData());;
    }
    else
        return 0;
}
int IncomesFile::getLastIncomeId()
{
    return lastIncomeId;
}
