#ifndef _ACCOUNTOPERATIONS_H
#define _ACCOUNTOPERATIONS_H


#include "Income.h"
#include "Date.h"
#include "AuxiliaryMethods.h"



class AccountOperations{

Income getIncomeData(int loggedUserId);

public:

    void addIncome(int loggedUserId);



};





#endif // _ACCOUNTOPERATIONS_H

