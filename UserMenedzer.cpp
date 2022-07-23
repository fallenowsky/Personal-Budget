#include "UserMenedzer.h"



void UserMenedzer::userRegister() {

    userOperations.userRegister();

}

void UserMenedzer::logInUser() {

    loggedUserId = userOperations.logInUser();

    //if ( loggedUserId > 0 )


}

bool UserMenedzer::ifUsersEmpty() {

    if ( users.empty() == 1)
        return true;
    else
        return false;

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



