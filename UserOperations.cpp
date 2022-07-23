#include "UserOperations.h"


void UserOperations::userRegister(){

    User user;

    user = getUserData();

    if ( userFile.addUserToXmlFile(user) )
        cout << "You have successfully added a new user to file ";
    else
        cout << "There was a problem with adding a new user to file";


}

User UserOperations::getUserData(){

    User user;

    string input = "";

    user.setUserId( userFile.getLastUserId() + 1 );

    label:
    cout << "Enter user login: "; input = AuxiliaryMethods::readLine();
    if ( userFile.ifLoginFree(input) )
    user.setUserLogin(input);
    else {

        cout << "This login is occupied by another user. Try one more time!\n";
        goto label;
    }

    cout << "Enter user password: "; input = AuxiliaryMethods::readLine();
    user.setUserPassword(input);

    cout << "Enter user name: "; input = AuxiliaryMethods::readLine();
    user.setUserName(input);

    cout << "Enter user surname: "; input = AuxiliaryMethods::readLine();
    user.setUserSurname(input);

    return user;
}

vector <User> UserOperations::readUsersFromXmlFile(){

    vector <User> users;

    users = userFile.readUsersFromXmlFile();

    return users;

}
