#include "UserFile.h"


bool UserFile::addUserToXmlFile(User user) {

    bool userCorrectlyAdded;

    bool ifUserFileExists = xmlUserFile.Load( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + USER_FILE_NAME );

    if ( !ifUserFileExists )
        xmlUserFile.AddElem("Users");

    xmlUserFile.FindElem();
    xmlUserFile.IntoElem();
    xmlUserFile.AddElem( "User" );
    xmlUserFile.IntoElem();
    xmlUserFile.AddElem( "UserId", user.getUserId() );
    xmlUserFile.AddElem( "UserLogin", user.getUserLogin() );
    xmlUserFile.AddElem( "UserPassword", user.getUserPassword() );
    xmlUserFile.AddElem( "UserName", user.getUserName() );
    xmlUserFile.AddElem( "UserSurname", user.getUserSurname() );

    userCorrectlyAdded = xmlUserFile.Save( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + USER_FILE_NAME );


    return userCorrectlyAdded;
}

vector <User> UserFile::readUsersFromXmlFile() {

    User user;

    string userIdString;

    bool ifUserFileExists = xmlUserFile.Load( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + USER_FILE_NAME );


    if ( ifUserFileExists ) {

        xmlUserFile.ResetPos();
        xmlUserFile.FindElem();
        xmlUserFile.IntoElem();

        while ( xmlUserFile.FindElem() ) {

            xmlUserFile.IntoElem();

            xmlUserFile.FindElem();

            userIdString = xmlUserFile.GetData();

            user.setUserId( AuxiliaryMethods::transformStringToInt(userIdString) );

            xmlUserFile.FindElem();
            user.setUserLogin( xmlUserFile.GetData() );

            xmlUserFile.FindElem();
            user.setUserPassword( xmlUserFile.GetData() );

            xmlUserFile.FindElem();
            user.setUserName( xmlUserFile.GetData() );

            xmlUserFile.FindElem();
            user.setUserSurname( xmlUserFile.GetData() );

            xmlUserFile.OutOfElem();

            users.push_back(user);
        }

        xmlUserFile.Save( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + USER_FILE_NAME );

    }

    return users;
}

int UserFile::getLastUserId() {

    int lastUserId = 0;

    for (int i = 0; i < users.size(); ++i) {

        if ( i == users.size() - 1) {

            lastUserId = users[i].getUserId();
        }

    }

    return lastUserId;
}

bool UserFile::ifLoginFree(string userLogin) {

    if (users.empty() == true)
        return true;
    else {

        bool ifUserFileExists = xmlUserFile.Load( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + USER_FILE_NAME );

        if ( ifUserFileExists ) {

            xmlUserFile.ResetPos();
            xmlUserFile.FindElem();
            xmlUserFile.IntoElem();

            while ( xmlUserFile.FindElem() ) {

                xmlUserFile.IntoElem();

                xmlUserFile.FindElem();
                xmlUserFile.FindElem();

                if ( userLogin == xmlUserFile.GetData() )
                    return false;

                xmlUserFile.OutOfElem();

            }

        }
        xmlUserFile.Save( " C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + USER_FILE_NAME );
    }
    return true;
}

void UserFile::replacePasswordInXmlFile(int userId, string oldPassword, string newPassword) {

/*
    bool ifUserFileExists = xmlUserFile.Load( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + USER_FILE_NAME);

    if ( ifUserFileExists ) {

        xmlUserFile.ResetPos();
        xmlUserFile.FindElem();
        xmlUserFile.IntoElem();

        while ( xmlUserFile.FindElem("User") ) {

            xmlUserFile.IntoElem();
            xmlUserFile.FindElem("UserId");


            if ( userId == AuxiliaryMethods::transformStringToInt( xmlUserFile.GetData() ) ) {

                 xmlUserFile.FindElem("UserPassword");

                if ( oldPassword == xmlUserFile.GetData() ) {

                    xmlUserFile.SetData( newPassword );
                    xmlUserFile.Save( " C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + USER_FILE_NAME );
                    return;

                }


            }
            xmlUserFile.OutOfElem();
        }

    }
    xmlUserFile.Save( " C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + USER_FILE_NAME );

    */

    if (xmlUserFile.Load( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + USER_FILE_NAME ) ){
        xmlUserFile.FindElem();
        xmlUserFile.IntoElem();

        while ( xmlUserFile.FindElem("User") ){

            xmlUserFile.IntoElem();
            xmlUserFile.FindElem("UserId");

            if ( xmlUserFile.GetData() == AuxiliaryMethods::convertIntToString(userId) ){

                xmlUserFile.FindElem("UserPassword");
                xmlUserFile.SetData(newPassword);
                xmlUserFile.Save( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + USER_FILE_NAME );
                break;
            }
            xmlUserFile.OutOfElem();

        }


    }

}
