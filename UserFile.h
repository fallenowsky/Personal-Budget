#ifndef _USERFILE_H
#define _USERFILE_H


#include "User.h"
#include "Markup.h"


using namespace std;

class UserFile{

     CMarkup xmlUserFile;
//int getLastUserID();


public:

    bool addUserToXmlFile(User user);




};



#endif // _USERFILE_H
