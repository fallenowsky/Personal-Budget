#ifndef _AUXILIARYMETHODS_H
#define _AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>

using namespace std;




class AuxiliaryMethods {

public:
    static char displayMainMenu();
    static string readLine();
    static int transformStringToInt(string stringNumber);
    static bool checkInputDataValidity(string userData);
    static string transformFirstLetterToHighRestToLow(string userData);


};




#endif // _AUXILIARYMETHODS_H
