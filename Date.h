#ifndef _DATE_H
#define _DATE_H




class Date{

    int year;
    int month;
    int day;

public:

Date ( int year  = 2022, int month = 1, int day = 1 ){ }
int getYear();
int getMonth();
int getDay();

void setYear(int year);
void setMonth(int month);
void setDay(int day);



};


#endif // _DATE_H
