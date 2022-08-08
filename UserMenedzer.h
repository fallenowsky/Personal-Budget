#ifndef _USERMENEDZER_H
#define _USERMENEDZER_H


#include "UserOperations.h"
#include "AuxiliaryMethods.h"
#include "AccountOperations.h"


class UserMenedzer {

    UserOperations userOperations;
    AccountOperations *accountOperations;
    vector <User> users;
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;
    int loggedUserId;
    char choice;

    void callCorrespondingFunctionUserMenu();
    void callCorresspondingFunctionMainMenu();
    void addIncome();
    void addExpense();
    void displayActualMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedPeriodBalance();
    void changeUserPassword();

public:

    UserMenedzer(string user_file_name, string income_file_name, string expense_file_name)

        : userOperations(user_file_name), INCOME_FILE_NAME(income_file_name), EXPENSE_FILE_NAME(expense_file_name ) {
        users = userOperations.readUsersFromXmlFile();
        loggedUserId = 0;
        accountOperations = NULL;
        choice = AuxiliaryMethods::displayMainMenu();
        callCorresspondingFunctionMainMenu();

    }

    ~UserMenedzer() {

        delete accountOperations;
        accountOperations = NULL;
    }
    void userRegister();
    bool ifUsersEmpty();
    void logInUser();
    void logOutUser();



};










#endif // _USERMENEDZER_H
