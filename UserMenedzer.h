#ifndef _USERMENEDZER_H
#define _USERMENEDZER_H


#include "UserOperations.h"
#include "AuxiliaryMethods.h"


class UserMenedzer {

    UserOperations userOperations;
    //AccountOperations *accountOperations;
    vector <User> users;
    int loggedUserId;


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
