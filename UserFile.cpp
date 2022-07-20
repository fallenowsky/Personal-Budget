#include "UserFile.h"


bool UserFile::addUserToXmlFile(User user){

    bool userCorrectlyAdded;

    bool ifUserFileExists = xmlUserFile.Load( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\usersXmlFile.xml" );

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

        userCorrectlyAdded = xmlUserFile.Save( "usersXmlFile.xml" );


        return userCorrectlyAdded;
}
