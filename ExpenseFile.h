#ifndef _EXPENSEFILE_H
#define _EXPENSEFILE_H

#include <vector>

#include "Expense.h"
#include "XmlFiles.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"



class ExpenseFile : public XmlFiles {

    CMarkup xmlExpenseFile;

    const string EXPENSE_FILE_NAME;
    const int LOGGED_USER_ID;

public:

    ExpenseFile(int _LOGGED_USER_ID_, string _EXPENSE_FILE_NAME_) : EXPENSE_FILE_NAME(_EXPENSE_FILE_NAME_), LOGGED_USER_ID(_LOGGED_USER_ID_) {}
    void addLoggedUserExpenseToXmlFile(Expense expense);

    vector <Expense> readLoggedUserExpensesFromXmlFile();
    int getLastExpenseId();



};





#endif // _INCOMEFILE_H
