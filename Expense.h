#ifndef _EXPENSE_H
#define _EXPENSE_H

#include <iostream>

using namespace std;


class Expense {


    int expenseId;
    int expenseUserId;
    string expenseDate;
    string expenseItem;
    double expenseAmount;

public:

    Expense(int expenseId = 0, int expenseUserId = 0, string expenseDate = "200011", string expenseItem = "Default name", double expenseAmount = 0.0) {}
    int getExpenseId();
    int getExpenseUserId();
    string getExpenseDate();
    string getExpenseItem();
    double getExpenseAmount();

    void setExpenseId(int expenseId);
    void setExpenseUserId(int expenseUserID);
    void setExpenseDate(string expenseDate);
    void setExpenseItem(string expenseItem);
    void setExpenseAmount(double expenseAmmount);
};


#endif // _expense_H
