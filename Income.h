#ifndef _INCOME_H
#define _INCOME_H

#include <iostream>

using namespace std;


class Income{


    int incomeId;
    int incomeUserId;
    int incomeDate;
    string incomeItem;
    double incomeAmount;

public:

    int getIncomeId();
    int getIncomeUserId();
    int getIncomeDate();
    string getIncomeItem();
    double getIncomeAmount();

    void setIncomeId(int incomeId);
    void setIncomeUserId(int incomeUserID);
    void setIncomeDate(int incomeDate);
    void setIncomeItem(string incomeItem);
    void setIncomeAmount(double incomeAmmount);
};


#endif // _INCOME_H
