#include "UserMenedzer.h"



void UserMenedzer::userRegister() {

    userOperations.userRegister();

}

void UserMenedzer::logInUser() {

    loggedUserId = userOperations.logInUser();

    if ( loggedUserId > 0 ){
        accountOperations = new AccountOperations();
        choice = AuxiliaryMethods::displayUserMenu();
        callCorrespondingFunction();
    }


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



