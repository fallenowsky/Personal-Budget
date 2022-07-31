#ifndef _USEROPERATIONS_H
#define _USEROPERATIONS_H



#include "UserFile.h"
#include "AuxiliaryMethods.h"

using namespace std;


class UserOperations {


    UserFile userFile;
    vector <User> users;

    User getUserData();

public:
    UserOperations(string userFileName) : userFile(userFileName) { };
    void userRegister();
    vector <User> readUsersFromXmlFile();
    int logInUser();
    bool changeUserPassword(const int LOGGED_USER_ID);



};







#endif // _USEROPERATIONS_H
