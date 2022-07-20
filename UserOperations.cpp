#include "UserOperations.h"


void UserOperations::userRegister(){

    User user;

    user = getUserData();

    if ( userfile.addUserToXmlFile(user) )
        cout << "You have successfully added a new user to file ";
    else
        cout << "There was a problem with adding a new user to file";


}

User UserOperations::getUserData(){

    User user;

    string input = "";

    //user.setUserId(userFile.getLastUserID() + 1);
    cin.get();
    cout << "Enter user login: "; input = AuxiliaryMethods::readLine();
    user.setUserLogin(input);

    cout << "Enter user password: "; input = AuxiliaryMethods::readLine();
    user.setUserPassword(input);

    cout << "Enter user name: "; input = AuxiliaryMethods::readLine();
    user.setUserName(input);

    cout << "Enter user surname: "; input = AuxiliaryMethods::readLine();
    user.setUserSurname(input);

    return user;
}
