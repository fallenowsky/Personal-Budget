#include "UserMenedzer.h"



void UserMenedzer::userRegister() {

    userOperations.userRegister();
    users = userOperations.readUsersFromXmlFile();
    logInUser();

}

void UserMenedzer::logInUser() {

    loggedUserId = userOperations.logInUser();

    if ( loggedUserId > 0 ){
        accountOperations = new AccountOperations(loggedUserId);
        choice = AuxiliaryMethods::displayUserMenu();
        callCorrespondingFunction();
    }


}

void UserMenedzer::displayActualMonthBalance(){

    accountOperations -> displayActualMonthBalance();
    choice = AuxiliaryMethods::displayUserMenu();
    callCorrespondingFunction();

}

void UserMenedzer::displayPreviousMonthBalance(){

    accountOperations -> displayPreviousMonthBalance();
    choice = AuxiliaryMethods::displayUserMenu();
    callCorrespondingFunction();

}

void UserMenedzer::displaySelectedPeriodBalance(){

    accountOperations -> displayChoosenPeriodBalance();
    choice = AuxiliaryMethods::displayUserMenu();
    callCorrespondingFunction();

}

bool UserMenedzer::ifUsersEmpty() {

    if ( users.empty() == 1)
        return true;
    else
        return false;

}

void UserMenedzer::addIncome(){

    accountOperations -> addIncome(loggedUserId);
    choice = AuxiliaryMethods::displayUserMenu();
    callCorrespondingFunction();
}

void UserMenedzer::addExpense(){

    accountOperations -> addExpense(loggedUserId);
    choice = AuxiliaryMethods::displayUserMenu();
    callCorrespondingFunction();
}

void UserMenedzer::changeUserPassword(){

    userOperations.changeUserPassword(loggedUserId);
    choice = AuxiliaryMethods::displayUserMenu();
    callCorrespondingFunction();
}

void UserMenedzer::logOutUser(){

    char choice = {0};
    loggedUserId = 0;

    delete accountOperations;
    accountOperations = NULL;

}
void UserMenedzer::callCorrespondingFunction(){

        switch(choice){

    case '1':
            addIncome();
            break;
    case '2':
            addExpense();
            break;
    case '3':
            displayActualMonthBalance();
            break;
    case '4':
            displayPreviousMonthBalance();
            break;
    case '5':
            displaySelectedPeriodBalance();
            break;
    case '6':
            changeUserPassword();
            break;
    case '7':
            logOutUser();
            break;

        }


}



