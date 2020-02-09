#ifndef INCOME_H
#define INCOME_H

#include <iostream>

#include "Finance.h"

using namespace std;

class Income : public Finance
{
    int incomeId;

public:
    void setIncomeId(int newIncomeId);
    int getIncomeId();
};

#endif // INCOME_H
