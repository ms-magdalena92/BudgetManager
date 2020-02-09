#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#include "XmlFile.h"
#include "Income.h"
#include "AdjuvantMethods.h"

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
    void addIncomeToXmlFile(Income income);
    int getLastIncomeId();
};

#endif // INCOMESFILE_H
