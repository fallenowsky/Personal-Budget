#ifndef _ACCOUNTOPERATIONS_H
#define _ACCOUNTOPERATIONS_H


#include "Income.h"
#include "IncomeFile.h"
#include "Date.h"
#include "AuxiliaryMethods.h"



class AccountOperations {

    IncomeFile incomeFile;
    vector <Income> incomes;

    Income getIncomeData(int loggedUserId);
    int readActualDateAndConvertToInt();

public:

    AccountOperations(int LOGGED_USER_ID) : incomeFile(LOGGED_USER_ID)  { incomes = incomeFile.readLoggedUserIncomesFromXmlFile(); }
    void addIncome(int loggedUserId);



};





#endif // _ACCOUNTOPERATIONS_H

