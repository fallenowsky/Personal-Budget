#ifndef _PERSONALBUDGET_H
#define _PERSONALBUDGET_H

#include "UserMenedzer.h"


class PersonalBudget {

    UserMenedzer userMenedzer;


public:

    PersonalBudget(string USER_FILE_NAME, string INCOME_FILE_NAME, string EXPENSE_FILE_NAME) :
        userMenedzer(USER_FILE_NAME, INCOME_FILE_NAME, EXPENSE_FILE_NAME) {

    }



};








#endif // _PERSONALBUDGET
