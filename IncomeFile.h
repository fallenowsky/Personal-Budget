#ifndef _INCOMEFILE_H
#define _INCOMEFILE_H

#include <vector>

#include "Income.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"



class IncomeFile{

   CMarkup xmlIncomeFile;

   const string INCOME_FILE_NAME;
   const int LOGGED_USER_ID;

public:

    IncomeFile(int _LOGGED_USER_ID_) : INCOME_FILE_NAME("incomeFile.xml"), LOGGED_USER_ID(_LOGGED_USER_ID_) {}
    void addLoggedUserIncomeToXmlFile(Income income);

    vector <Income> readLoggedUserIncomesFromXmlFile();
    int getLastIncomeId(vector <Income> &incomes);




};





#endif // _INCOMEFILE_H
