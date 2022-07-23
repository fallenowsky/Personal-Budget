#include "UserOperations.h"


void UserOperations::userRegister() {

    User user;

    user = getUserData();

    if ( userFile.addUserToXmlFile(user) )
        cout << "You have successfully added a new user to file ";
    else
        cout << "There was a problem with adding a new user to file";


}
int UserOperations::logInUser() {

    string input;
    int usersCount = users.size();
    const int triesCount = 4;

    cout << "Enter login: ";
    input = AuxiliaryMethods::readLine();

    for(int i = 0; i < usersCount; ++i) {

        if ( users[i].getUserLogin() == input ) {

            cout << endl;
            cout << "I have found a user with this login in base! Enter a password now: \n\n";

            for (int j = 1; j < triesCount; j++) {

                cout << "It's your " << j << " chance\n";

                input = AuxiliaryMethods::readLine();

                if ( input == users[i].getUserPassword() ) {
                    cout << "You are logged!\n\n";
                    system("pause");
                    return users[i].getUserId();
                }

                else
                    continue;
            }

            cout << endl;
            cout << "You don't have more chances!\n\n";
            system("pause");
            return 0;

        }

    }
}
User UserOperations::getUserData() {

    system("cls");
    cout << endl;
    cout << ">>>REGISTRATION MENU<<< \n\n";

    User user;

    string input = "";

    user.setUserId( userFile.getLastUserId() + 1 );

loginLabel:
    cout << "Enter user login: ";
    input = AuxiliaryMethods::readLine();

    if ( AuxiliaryMethods::checkInputDataValidity(input) ) {

        if ( userFile.ifLoginFree(input) )
            user.setUserLogin(input);
        else {

            cout << "This login is occupied by another user. Try one more time!\n";
            goto loginLabel;
        }
    } else{

        cout << "Enter a login which has at least 4 signs!\n";
        system("pause");
        goto loginLabel;
    }



    cout << "Enter user password: ";
    input = AuxiliaryMethods::readLine();
    user.setUserPassword(input);

nameLabel:
    cout << "Enter user name: ";
    input = AuxiliaryMethods::readLine();

    if ( AuxiliaryMethods::checkInputDataValidity(input) ) {

        input = AuxiliaryMethods::transformFirstLetterToHighRestToLow(input);
        user.setUserName(input);
    } else{
        cout << "Enter a Name which has at least 4 signs!\n";
        system("pause");
        goto nameLabel;
    }

surnameLabel:

    cout << "Enter user surname: ";
    input = AuxiliaryMethods::readLine();

    if ( AuxiliaryMethods::checkInputDataValidity(input) ) {
        input = AuxiliaryMethods::transformFirstLetterToHighRestToLow(input);
        user.setUserSurname(input);
    } else{
        cout << "Enter a Surname which has at least 4 signs!\n";
        system("pause");
        goto surnameLabel;
    }
    return user;
}

vector <User> UserOperations::readUsersFromXmlFile() {

    users = userFile.readUsersFromXmlFile();

    return users;

}
