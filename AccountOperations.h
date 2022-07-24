#ifndef _ACCOUNTOPERATIONS_H
#define _ACCOUNTOPERATIONS_H


#include "Income.h"
#include "IncomeFile.h"
#include "Date.h"
#include "AuxiliaryMethods.h"



class AccountOperations {

    IncomeFile incomeFile;
    vector <Income> incomes;
    double userIncomes;

    Income getIncomeData(int loggedUserId);
    int readActualDateAndConvertToInt();
    double getChoosenPeriodIncome(int dateFrom, int dateTo);

public:

    AccountOperations(int LOGGED_USER_ID) : incomeFile(LOGGED_USER_ID)  { incomes = incomeFile.readLoggedUserIncomesFromXmlFile(); userIncomes = 0;}
    void addIncome(int loggedUserId);
    void getActualMonthIncome();
    void displayChoosenPeriodBalance();


};





#endif // _ACCOUNTOPERATIONS_H

