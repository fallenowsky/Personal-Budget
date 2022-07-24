#ifndef _USERMENEDZER_H
#define _USERMENEDZER_H


#include "UserOperations.h"
#include "AuxiliaryMethods.h"
#include "AccountOperations.h"


class UserMenedzer {

    UserOperations userOperations;
    AccountOperations *accountOperations;
    vector <User> users;
    int loggedUserId;
    char choice;

    void callCorrespondingFunction();
    void addIncome();
    void displayActualMonthBalance();
    void displaySelectedPeriodBalance();

public:

    UserMenedzer(string userFileName)

        : userOperations(userFileName) {
        users = userOperations.readUsersFromXmlFile();
        loggedUserId = 0;

    }
    void userRegister();
    void displayRegisteredUsers();
    bool ifUsersEmpty();
    void logInUser();


};










#endif // _USERMENEDZER_H
