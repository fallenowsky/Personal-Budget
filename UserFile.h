#ifndef _USERFILE_H
#define _USERFILE_H

#include <vector>

#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "XmlFiles.h"


using namespace std;

class UserFile : public XmlFiles {

     CMarkup xmlUserFile;
//int getLastUserID();
    vector <User> users;
    const string USER_FILE_NAME;


public:

    UserFile( string userFileName) : USER_FILE_NAME(userFileName){}
    bool addUserToXmlFile(User user);
    vector <User> readUsersFromXmlFile();
    int getLastUserId();
    bool ifLoginFree(string userLogin);


};



#endif // _USERFILE_H
