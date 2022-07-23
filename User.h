#ifndef _USER_H
#define _USER_H


#include <iostream>

using namespace std;

class User{

    int userId;
    string userLogin;
    string userPassword;
    string userName;
    string userSurname;


public:

   User() {

        userId = 0;
        userLogin = "Default";
        userPassword = "Default";
        userName = "Default";
        userSurname = "Default";
    }

    int getUserId();
    string getUserLogin();
    string getUserPassword();
    string getUserName();
    string getUserSurname();

    void setUserId(int userId);
    void setUserLogin(string userLogin);
    void setUserPassword(string userPassword);
    void setUserName(string userName);
    void setUserSurname(string userSurname);


};






#endif // _USER_H
