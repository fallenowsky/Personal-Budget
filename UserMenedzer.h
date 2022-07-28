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
    void addExpense();
    void displayActualMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedPeriodBalance();
    void changeUserPassword();

public:

    UserMenedzer(string userFileName)

        : userOperations(userFileName) {
        users = userOperations.readUsersFromXmlFile();
        loggedUserId = 0;
        accountOperations = NULL;

    }
    ~UserMenedzer(){

        delete accountOperations;
        accountOperations = NULL;
    }
    void userRegister();
    bool ifUsersEmpty();
    void logInUser();
    void logOutUser();



};










#endif // _USERMENEDZER_H
