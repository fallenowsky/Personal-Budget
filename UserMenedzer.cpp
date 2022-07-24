#include "UserMenedzer.h"



void UserMenedzer::userRegister() {

    userOperations.userRegister();

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

    accountOperations -> getActualMonthIncome();

}

void UserMenedzer::displayPreviousMonthBalance(){

    accountOperations -> displayPreviousMonthBalance();

}

void UserMenedzer::displaySelectedPeriodBalance(){

    accountOperations -> displayChoosenPeriodBalance();

}

bool UserMenedzer::ifUsersEmpty() {

    if ( users.empty() == 1)
        return true;
    else
        return false;

}

void UserMenedzer::addIncome(){

    accountOperations -> addIncome(loggedUserId);
}

void UserMenedzer::callCorrespondingFunction(){

        switch(choice){

    case '1':
            addIncome();
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

        }


}


void UserMenedzer::displayRegisteredUsers() {

    for (int i = 0; i < users.size(); ++i) {

        cout << users[i].getUserId() << endl;
        cout << users[i].getUserLogin() << endl;
        cout << users[i].getUserPassword() << endl;
        cout << users[i].getUserName() << endl;
        cout << users[i].getUserSurname() << endl;

    }

}



