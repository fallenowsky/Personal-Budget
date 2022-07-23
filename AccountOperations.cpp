#include "AccountOperations.h"



void AccountOperations::addIncome(int loggedUserId) {

    Income income;

    income = getIncomeData(loggedUserId);



}

Income AccountOperations::getIncomeData(int loggedUserId) {

    Date date;
    Income income;
    string userInput = "";
    string dateInString = "";
    int dateInt = 0;
    char sign = {};


    income.setIncomeId(1);
    income.setIncomeUserId(loggedUserId);


    cout << "Enter date. Would you like to add income with today's date? y/n ";
    cin >> sign;

    if ( sign == 'y' ) {

        date = AuxiliaryMethods::getSystemTime();
        dateInString = date.getYear();
        dateInString += date.getMonth();
        dateInString += date.getDay();
        dateInt = AuxiliaryMethods::transformStringToInt(dateInString);


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








}
