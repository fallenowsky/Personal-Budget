#include "UserOperations.h"


void UserOperations::userRegister() {

    system("cls");
    cout << endl;
    cout << ">>>REGISTRATION MENU<<< \n\n";

    User user;

    user = getUserData();

    if ( userFile.addUserToXmlFile(user) ) {
        cout << "You have successfully added a new user to file \n\n";
        system("pause");
    } else
        cout << "There was a problem with adding a new user to file";


}
int UserOperations::logInUser() {

    system("cls");
    cout << endl;
    cout << ">>>Log-In MENU<<< \n\n";

    string input;
    int usersCount = users.size();
    const int triesCount = 4;

loginLabel:
    cout << "\nEnter login: ";
    input = AuxiliaryMethods::readLine();

    for(int i = 0; i < usersCount; ++i) {

        if ( users[i].getUserLogin() == input ) {

            for (int j = 1; j < triesCount; j++) {

                cout << "\nIt's your " << j << " chance\n";
                cout << "Enter password: ";

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

        } else {

            cout << "There is no login like this! Try one more time! \n\n";
            system("pause");
            goto loginLabel;
        }

    }
}
User UserOperations::getUserData() {

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
    } else {

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
    } else {
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
    } else {
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

bool UserOperations::changeUserPassword(const int LOGGED_USER_ID) {

    string newPassword = "";
    string oldPassword = "";

    int userId = 0;
    int usersCout = users.size();

    bool controlBit = false;


    for (int j = 0; j < usersCout; ++j) {

        if ( users[j].getUserId() == LOGGED_USER_ID ) {

            cout << "Type old password: ";
            oldPassword = AuxiliaryMethods::readLine();


            if ( oldPassword == users[j].getUserPassword() && LOGGED_USER_ID == users[j].getUserId() ) {

                cout << endl;
                cout << "Type new password: ";
                newPassword = AuxiliaryMethods::readLine();
                controlBit = 1;
                users[j].setUserPassword(newPassword);
                userFile.replacePasswordInXmlFile(LOGGED_USER_ID, oldPassword,newPassword);

                cout << "Password changed! \n";
                system("pause");
            }

        }
    }

if ( !controlBit ) {

    cout << "User not found! \n";
    system("pause");

}

}

