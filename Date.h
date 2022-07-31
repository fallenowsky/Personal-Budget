#ifndef _DATE_H
#define _DATE_H

#include<iostream>

using namespace std;

class Date {

    string year;
    string month;
    string day;

public:

    Date ( string year  = "2022", string month = "01", string day = "01" ) { }
    string getYear();
    string getMonth();
    string getDay();

    void setYear(string year);
    void setMonth(string month);
    void setDay(string day);



};


#endif // _DATE_H
