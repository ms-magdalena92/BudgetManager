#include "IncomesFile.h"

vector<Income> IncomesFile::loadIncomesOfCurrentUserFromXmlFile(int CURRENT_USER_ID)
{
    CMarkup xml;
    vector <Income> incomes;

    if (fileExist(xml))
    {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("Income"))
        {
            Income income;
            xml.IntoElem();
            xml.FindElem("UserId");
            if (atoi((xml.GetElemContent()).c_str()) == CURRENT_USER_ID)
            {
                income.setUserId(atoi((xml.GetElemContent()).c_str()));
                xml.FindElem("IncomeId");
                income.setIncomeId(atoi((xml.GetElemContent()).c_str()));
                xml.FindElem("Date");
                income.setDate(AdjuvantMethods::changeDateToIntNumber(xml.GetElemContent()));
                xml.FindElem("Item");
                income.setItem(xml.GetElemContent());
                xml.FindElem("Amount");
                income.setAmount(atof((xml.GetElemContent()).c_str()));
                incomes.push_back(income);
            }
            xml.OutOfElem();
        }
    }
    return incomes;
}
void IncomesFile::addIncomeToXmlFile(Income income)
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
    xml.AddElem("Date", AdjuvantMethods::changeIntDateTOString(income.getDate()));
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", income.getAmount());
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
