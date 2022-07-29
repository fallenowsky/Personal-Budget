#ifndef _INCOME_H
#define _INCOME_H

#include <iostream>

using namespace std;


class Income{


    int incomeId;
    int incomeUserId;
    string incomeDate;
    string incomeItem;
    double incomeAmount;

public:

    Income(int incomeID = 0, int incomeUserId = 0, string incomeDate = "20000101", string incomeItem = "Default name", double incomeAmount = 0.0) {};
    int getIncomeId();
    int getIncomeUserId();
    string getIncomeDate();
    string getIncomeItem();
    double getIncomeAmount();

    void setIncomeId(int incomeId);
    void setIncomeUserId(int incomeUserID);
    void setIncomeDate(string incomeDate);
    void setIncomeItem(string incomeItem);
    void setIncomeAmount(double incomeAmmount);
};


#endif // _INCOME_H
