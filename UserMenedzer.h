#ifndef _USERMENEDZER_H
#define _USERMENEDZER_H


#include "UserOperations.h"
#include "AuxiliaryMethods.h"


class UserMenedzer {

    UserOperations userOperations;
    vector <User> users;


public:

    UserMenedzer(string userFileName) : userOperations(userFileName){ users = userOperations.readUsersFromXmlFile(); }
    void userRegister();
    void displayRegisteredUsers();
    bool ifUsersEmpty();

};










#endif // _USERMENEDZER_H
