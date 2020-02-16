#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include "XmlFile.h"
#include "Income.h"

using namespace std;

class IncomesFile : public XmlFile
{
    int lastIncomeId;

    int getLastIncomeIdFromFile();
public:
    IncomesFile(string incomesFilename):XmlFile(incomesFilename)
    {
        lastIncomeId = getLastIncomeIdFromFile();
    };
    vector<Income> loadIncomesOfCurrentUserFromXmlFile(int CURRENT_USER_ID);
    bool addIncomeToXmlFile(Income income, Date date);
    int getLastIncomeId();
};

#endif // INCOMESFILE_H
