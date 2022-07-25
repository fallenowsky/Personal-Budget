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


    income.setIncomeId( incomeFile.getLastIncomeId() + 1 );
    cout << income.getIncomeId() << endl;
    system("pause");

    income.setIncomeUserId(loggedUserId);


    cout << "Enter date. Would you like to add income with today's date? y/n ";
    cin >> sign;
    cin.get();

    if ( sign == 'y' ) {

        dateInt = readActualDateAndConvertToInt();
        income.setIncomeDate(dateInt);

        cout << "Enter name of item: ";
        userInput =  AuxiliaryMethods::readLine();
        income.setIncomeItem(userInput);


        cout << "Enter amount of item: ";
        userInput = AuxiliaryMethods::readLine();

        income.setIncomeAmount( AuxiliaryMethods::convertStringToDouble(userInput) );

        incomeFile.addLoggedUserIncomeToXmlFile(income);


    } else {

dateLabel:
        cout << "Enter a date with which would you like to add an income(YYYY-MM-DD): ";
        userInput = AuxiliaryMethods::readLine();

        if ( AuxiliaryMethods::checkDateIfCorrect(userInput) ) {

            dateInt = AuxiliaryMethods::fetchDigitsFromDate(userInput);
            income.setIncomeDate(dateInt);

            cout << "Enter name of item: ";
            userInput =  AuxiliaryMethods::readLine();
            income.setIncomeItem(userInput);

            cout << "Enter amount of item: ";
            userInput = AuxiliaryMethods::readLine();
            income.setIncomeAmount( AuxiliaryMethods::convertStringToDouble(userInput) );

            incomeFile.addLoggedUserIncomeToXmlFile(income);


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

void AccountOperations::displayActualMonthBalance(){

    double actualMonthIncome = 0, actualMonthExpense = 0;

    actualMonthIncome = getActualMonthIncome();

    actualMonthExpense = getActualMonthExpense();

    cout << actualMonthIncome - actualMonthExpense << endl;
    system("pause");

}

double AccountOperations::getActualMonthIncome(){

    Date date;
    double userIncomes = 0;
    int actualDateInt = 0, monthNumber = 0, daysInActualMonth = 0, daysLeftInActualMonth = 0;

        actualDateInt = readActualDateAndConvertToInt();

        date = AuxiliaryMethods::getSystemTime();

        monthNumber = date.getMonth();

        daysInActualMonth = AuxiliaryMethods::howManyDaysInMonth(monthNumber);

        daysLeftInActualMonth = daysInActualMonth - date.getDay();

        for (int i = 0; i < incomes.size(); ++i){

            if ( ( incomes[i].getIncomeDate() > actualDateInt - date.getDay() ) && ( incomes[i].getIncomeDate() <= actualDateInt + daysLeftInActualMonth ) ){


                userIncomes += incomes[i].getIncomeAmount();

            }

        }
       return userIncomes;

}

double AccountOperations::getActualMonthExpense(){

    Date date;
    double userExpenses = 0;
    int actualDateInt = 0, monthNumber = 0, daysInActualMonth = 0, daysLeftInActualMonth = 0;

        actualDateInt = readActualDateAndConvertToInt();

        date = AuxiliaryMethods::getSystemTime();

        monthNumber = date.getMonth();

        daysInActualMonth = AuxiliaryMethods::howManyDaysInMonth(monthNumber);

        daysLeftInActualMonth = daysInActualMonth - date.getDay();

        for (int i = 0; i < expenses.size(); ++i){

            if ( ( expenses[i].getExpenseDate() > actualDateInt - date.getDay() ) && ( expenses[i].getExpenseDate() <= actualDateInt + daysLeftInActualMonth ) ){


                userExpenses += expenses[i].getExpenseAmount();

            }

        }

      return userExpenses;

}

void AccountOperations::displayPreviousMonthBalance(){

    double previousMonthIncome = 0, previousMonthExpense = 0;

    previousMonthIncome = getPreviousMonthIncome();

    previousMonthExpense = getPreviousMonthExpense();

    cout << previousMonthIncome - previousMonthExpense << endl;
    system("pause");



}

double AccountOperations::getPreviousMonthIncome(){

    Date date;

    date = AuxiliaryMethods::getSystemTime();

    int actualDateInt = 0, daysCountInPreviousMonth = 0, numberOfActualDay = 0, endOfPreviousMonth = 0, beginOfPreviousMonth = 0 ;
    double previousMonthIncomes = 0;

        actualDateInt = readActualDateAndConvertToInt();

        daysCountInPreviousMonth = AuxiliaryMethods::howManyDaysInMonth( date.getMonth() - 1 );

        numberOfActualDay = date.getDay();

        endOfPreviousMonth = actualDateInt - numberOfActualDay; // <

        beginOfPreviousMonth = endOfPreviousMonth  - 100; // >


        for ( int k = 0; k < incomes.size(); ++k){


            if ( incomes[k].getIncomeDate() > beginOfPreviousMonth && incomes[k].getIncomeDate() < endOfPreviousMonth ){

                previousMonthIncomes += incomes[k].getIncomeAmount();

            }

        }
        cout << previousMonthIncomes << endl;
        system("pause");

    return previousMonthIncomes;

}

double AccountOperations::getPreviousMonthExpense(){

    Date date;

    date = AuxiliaryMethods::getSystemTime();

    int actualDateInt = 0, daysCountInPreviousMonth = 0, numberOfActualDay = 0, endOfPreviousMonth = 0, beginOfPreviousMonth = 0 ;
    double previousMonthExpenses = 0;

        actualDateInt = readActualDateAndConvertToInt();

        daysCountInPreviousMonth = AuxiliaryMethods::howManyDaysInMonth( date.getMonth() - 1 );

        numberOfActualDay = date.getDay();

        endOfPreviousMonth = actualDateInt - numberOfActualDay; // <

        beginOfPreviousMonth = endOfPreviousMonth  - 100; // >


        for ( int k = 0; k < expenses.size(); ++k){


            if ( expenses[k].getExpenseDate() > beginOfPreviousMonth && expenses[k].getExpenseDate() < endOfPreviousMonth ){

                previousMonthExpenses += expenses[k].getExpenseAmount();

            }

        }

        cout << previousMonthExpenses << endl;
        system("pause");

    return previousMonthExpenses;

}

void AccountOperations::displayChoosenPeriodBalance(){

    string dateString = "", dateToString = "";
    int dateFromInt = 0, dateToInt = 0;
    double incomes = 0, expenses = 0;


   dateLabel:
    cout << "Enter date from which would you like to search(Format: YYYY-MM-DD): ";
    dateString = AuxiliaryMethods::readLine();

    if ( AuxiliaryMethods::checkDateIfCorrect(dateString) ){

        dateFromInt = AuxiliaryMethods::fetchDigitsFromDate(dateString);

        cout << "Enter a date to which would you like to search(Format: YYYY-MM-DD): ";
        dateToString = AuxiliaryMethods::readLine();

        if ( AuxiliaryMethods::checkDateIfCorrect(dateToString)){

            dateToInt = AuxiliaryMethods::fetchDigitsFromDate(dateToString);

        } else{

            cout << "Entered date is incorrect! Try one more time.\n";
            system("pause");
            system("cls");
            goto dateLabel;
        }

    } else{
            cout << "Entered date is incorrect! Try one more time.\n";
            system("pause");
            system("cls");
            goto dateLabel;

    }


        incomes = getChoosenPeriodIncome(dateFromInt, dateToInt);
        expenses = getChoosenPeriodExpense(dateFromInt, dateToInt);

        cout << incomes - expenses << endl;
        system("pause");

}

double AccountOperations::getChoosenPeriodIncome(int dateFrom, int dateTo){

    double periodIncome = 0;

    for ( int j = 0; j < incomes.size(); ++j){

        if ( incomes[j].getIncomeDate() >= dateFrom && incomes[j].getIncomeDate() <= dateTo ){

              periodIncome += incomes[j].getIncomeAmount();

        }

    }

    cout << periodIncome << endl;
    system("pause");
    return periodIncome;

}

double AccountOperations::getChoosenPeriodExpense(int dateFrom, int dateTo){

    double periodExpense = 0;

    for ( int j = 0; j < expenses.size(); ++j){

        if ( expenses[j].getExpenseDate() >= dateFrom && expenses[j].getExpenseDate() <= dateTo ){

              periodExpense += expenses[j].getExpenseAmount();

        }

    }

    cout << periodExpense << endl;
    system("pause");
    return periodExpense;

}


void AccountOperations::addExpense(int loggedUserId) {

    Expense expense;

    expense = getExpenseData(loggedUserId);



}

Expense AccountOperations::getExpenseData(int loggedUserId) {

    Date date;
    Expense expense;
    string userInput = "";

    int dateInt = 0;
    char sign = {};


    expense.setExpenseId( expenseFile.getLastExpenseId() + 1 );
    cout << expense.getExpenseId() << endl;
    system("pause");

    expense.setExpenseUserId(loggedUserId);


    cout << "Enter date. Would you like to add expense with today's date? y/n ";
    cin >> sign;
    cin.get();

    if ( sign == 'y' ) {

        dateInt = readActualDateAndConvertToInt();
        expense.setExpenseDate(dateInt);

        cout << "Enter name of item: ";
        userInput =  AuxiliaryMethods::readLine();
        expense.setExpenseItem(userInput);


        cout << "Enter amount of item: ";
        userInput = AuxiliaryMethods::readLine();
        expense.setExpenseAmount( AuxiliaryMethods::convertStringToDouble(userInput) );

        expenseFile.addLoggedUserExpenseToXmlFile(expense);


    } else {

dateLabel:
        cout << "Enter a date with which would you like to add an expense(YYYY-MM-DD): ";
        userInput = AuxiliaryMethods::readLine();

        if ( AuxiliaryMethods::checkDateIfCorrect(userInput) ) {

            dateInt = AuxiliaryMethods::fetchDigitsFromDate(userInput);
            expense.setExpenseDate(dateInt);

            cout << "Enter name of item: ";
            userInput =  AuxiliaryMethods::readLine();
            expense.setExpenseItem(userInput);

            cout << "Enter amount of item: ";
            userInput = AuxiliaryMethods::readLine();
            expense.setExpenseAmount( AuxiliaryMethods::convertStringToDouble(userInput) );

            expenseFile.addLoggedUserExpenseToXmlFile(expense);


        } else {
            cout << "Entered date has incorrect format. Try one more time!\n";
            system("pause");
            goto dateLabel;
        }

    }

    return expense;

}

