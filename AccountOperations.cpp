#include "AccountOperations.h"



void AccountOperations::addIncome(int loggedUserId) {

    Income income;

    income = getIncomeData(loggedUserId);



}

Income AccountOperations::getIncomeData(int loggedUserId) {

    Date date;
    Income income;
    string userInput = "";

    int dateInt = 0;
    char sign = {};


    income.setIncomeId(1);
    income.setIncomeUserId(loggedUserId);


    cout << "Enter date. Would you like to add income with today's date? y/n ";
    cin >> sign;
    cin.get();

    if ( sign == 'y' ) {

        dateInt = readActualDateAndConvertToInt();

        cout << "Enter name of item: ";
        userInput =  AuxiliaryMethods::readLine();
        income.setIncomeItem(userInput);


        cout << "Enter amount of item: ";
        userInput = AuxiliaryMethods::readLine();
        income.setIncomeAmount( AuxiliaryMethods::convertStringToDouble(userInput) );


    } else {

dateLabel:
        cout << "Enter a date with which would you like to add an income(YYYY-MM-DD): ";
        userInput = AuxiliaryMethods::readLine();

        if ( AuxiliaryMethods::checkDateIfCorrect(userInput) ) {

            dateInt = AuxiliaryMethods::fetchDigitsFromDate(userInput);

            cout << "Enter name of item: ";
            userInput =  AuxiliaryMethods::readLine();
            income.setIncomeItem(userInput);

            cout << "Enter amount of item: ";
            userInput = AuxiliaryMethods::readLine();
            income.setIncomeAmount( AuxiliaryMethods::convertStringToDouble(userInput) );


        } else {
            cout << "Entered date has incorrect format. Try one more time!\n";
            system("pause");
            goto dateLabel;
        }

    }

    return income;

}

int AccountOperations::readActualDateAndConvertToInt(){

    Date date;
    string yearS = "", monthS = "", dayS = "", dateCollect = "";
    int year = 0;
    int month = 0;
    int day = 0;
    int dateInt = 0;

        date = AuxiliaryMethods::getSystemTime();

        year = date.getYear();
        yearS = AuxiliaryMethods::convertIntToString(year);
        month = date.getMonth();
        monthS = AuxiliaryMethods::convertIntToString(month);
        day = date.getDay();
        dayS = AuxiliaryMethods::convertIntToString(day);
        dateCollect = yearS + monthS + dayS;

        dateInt =  AuxiliaryMethods::transformStringToInt(dateCollect);


    return dateInt;

}
