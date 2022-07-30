#ifndef _INCOMEFILE_H
#define _INCOMEFILE_H

#include <vector>

#include "Income.h"
#include "XmlFiles.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"



class IncomeFile : public XmlFiles{

   CMarkup xmlIncomeFile;

   const string INCOME_FILE_NAME;
   const int LOGGED_USER_ID;

public:

    IncomeFile(int _LOGGED_USER_ID_, string INCOME_FILE_NAME_) : INCOME_FILE_NAME(INCOME_FILE_NAME_), LOGGED_USER_ID(_LOGGED_USER_ID_) {}
    void addLoggedUserIncomeToXmlFile(Income income);

    vector <Income> readLoggedUserIncomesFromXmlFile();
    int getLastIncomeId();



};





#endif // _INCOMEFILE_H
