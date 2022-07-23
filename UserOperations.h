#ifndef _USEROPERATIONS_H
#define _USEROPERATIONS_H



#include "UserFile.h"
#include "AuxiliaryMethods.h"

using namespace std;


class UserOperations{

    //XmlFile xmlfile;
    User getUserData();
    UserFile userFile;

public:
    UserOperations(string userFileName) : userFile(userFileName) { };
    void userRegister();
    vector <User> readUsersFromXmlFile();



};







#endif // _USEROPERATIONS_H
