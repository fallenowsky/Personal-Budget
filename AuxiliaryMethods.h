#ifndef _AUXILIARYMETHODS_H
#define _AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <time.h>

#include "Date.h"

using namespace std;




class AuxiliaryMethods {

     static void eraseZerosIfExists(string &date);
     static bool ifDateFormatCorrect(string date);
     static bool ifYearMonthDayCorrect(string date);
     static bool ifLeapYear();


public:
    static char displayMainMenu();
    static string readLine();
    static int transformStringToInt(string stringNumber);
    static bool checkInputDataValidity(string userData);
    static string transformFirstLetterToHighRestToLow(string userData);
    static char displayUserMenu();
    static Date getSystemTime();
    static double convertStringToDouble(string stringNumber);
    static bool checkDateIfCorrect(string &date);
    static int fetchDigitsFromDate(string date);
    static string convertIntToString(int number);
    static int howManyDaysInMonth(int monthNumber);



};


#endif // _AUXILIARYMETHODS_H
