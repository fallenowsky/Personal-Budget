#include "Date.h"



string Date::getYear(){

    return this -> year;
}

string Date::getMonth(){

    return this -> month;
}

string Date::getDay(){

    return this -> day;
}

void Date::setYear(string year){

    this -> year = year;
}

void Date::setMonth(string month){

    this -> month = month;
}

void Date::setDay(string day){

    this -> day = day;
}
