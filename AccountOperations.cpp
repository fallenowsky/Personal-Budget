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
        income.setIncomeDate( AuxiliaryMethods::convertIntToString(dateInt));

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
            income.setIncomeDate( AuxiliaryMethods::convertIntToString(dateInt) );

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

int AccountOperations::readActualDateAndConvertToInt() {

    Date date;
    string yearS = "", monthS = "", dayS = "", dateCollect = "";

    int dateInt = 0;

    date = AuxiliaryMethods::getSystemTime();

    yearS = date.getYear();

    monthS = date.getMonth();

    dayS = date.getDay();

    dateCollect = yearS + monthS + dayS;

    dateInt =  AuxiliaryMethods::transformStringToInt(dateCollect);


    return dateInt;

}

void AccountOperations::displayActualMonthBalance() {

    if ( !incomes.empty () || !expenses.empty() ) {

        double actualMonthIncome = 0, actualMonthExpense = 0;

        actualMonthIncome = getActualMonthIncome();

        actualMonthExpense = getActualMonthExpense();

        AuxiliaryMethods::sortIncomesAndExpenses(incomesData,expensesData);
        AuxiliaryMethods::displayBalance(actualMonthIncome, actualMonthExpense,1);


    } else {

        cout << "There is no incomes or expenses!\n";
        system("pause");

    }


}

double AccountOperations::getActualMonthIncome() {

    Date date;
    incomesData.clear();
    double userIncomes = 0;
    int actualDateInt = 0, monthNumber = 0, daysInActualMonth = 0, daysLeftInActualMonth = 0;

    actualDateInt = readActualDateAndConvertToInt();

    date = AuxiliaryMethods::getSystemTime();

    monthNumber = AuxiliaryMethods::transformStringToInt( date.getMonth() );

    daysInActualMonth = AuxiliaryMethods::howManyDaysInMonth(monthNumber);

    daysLeftInActualMonth = daysInActualMonth - AuxiliaryMethods::transformStringToInt( date.getDay() );

    for (int i = 0; i < incomes.size(); ++i) {

        string dateS = incomes[i].getIncomeDate();
        int dateXmlFile = AuxiliaryMethods::transformStringToInt(dateS);

        if ( ( dateXmlFile > actualDateInt - AuxiliaryMethods::transformStringToInt( date.getDay() ) )&& ( dateXmlFile <= actualDateInt + daysLeftInActualMonth ) ) {

            userIncomes += incomes[i].getIncomeAmount();
            incomesData.push_back(incomes[i]);

        }

    }

    return userIncomes;

}

double AccountOperations::getActualMonthExpense() {

    Date date;
    double userExpenses = 0;
    expensesData.clear();
    int actualDateInt = 0, monthNumber = 0, daysInActualMonth = 0, daysLeftInActualMonth = 0;

    actualDateInt = readActualDateAndConvertToInt();

    date = AuxiliaryMethods::getSystemTime();

    monthNumber = AuxiliaryMethods::transformStringToInt( date.getMonth() );

    daysInActualMonth = AuxiliaryMethods::howManyDaysInMonth(monthNumber);

    daysLeftInActualMonth = daysInActualMonth - AuxiliaryMethods::transformStringToInt( date.getDay() );

    for (int i = 0; i < expenses.size(); ++i) {

        string dateS = expenses[i].getExpenseDate();
        int dateXmlFile = AuxiliaryMethods::transformStringToInt(dateS);

        if ( ( dateXmlFile > actualDateInt - AuxiliaryMethods::transformStringToInt( date.getDay() ) ) && ( dateXmlFile <= actualDateInt + daysLeftInActualMonth ) ) {

            userExpenses += expenses[i].getExpenseAmount();
            expensesData.push_back(expenses[i]);

        }

    }

    return userExpenses;

}

void AccountOperations::displayPreviousMonthBalance() {

    if ( !incomes.empty() || !expenses.empty() ) {

        double previousMonthIncome = 0, previousMonthExpense = 0;

        previousMonthIncome = getPreviousMonthIncome();

        previousMonthExpense = getPreviousMonthExpense();

        AuxiliaryMethods::sortIncomesAndExpenses(incomesData,expensesData);
        AuxiliaryMethods::displayBalance(previousMonthIncome,previousMonthExpense,2);


    } else {
        cout << "There is no incomes or expenses\n";
        system("pause");
    }
}

double AccountOperations::getPreviousMonthIncome() {

    Date date;

    date = AuxiliaryMethods::getSystemTime();
    incomesData.clear();

    int actualDateInt = 0, daysCountInPreviousMonth = 0, numberOfActualDay = 0, endOfPreviousMonth = 0, beginOfPreviousMonth = 0 ;
    double previousMonthIncomes = 0;

    actualDateInt = readActualDateAndConvertToInt();

    daysCountInPreviousMonth = AuxiliaryMethods::howManyDaysInMonth( AuxiliaryMethods::transformStringToInt( date.getMonth() ) - 1 );

    numberOfActualDay = AuxiliaryMethods::transformStringToInt( date.getDay() );

    endOfPreviousMonth = actualDateInt - numberOfActualDay; // <

    beginOfPreviousMonth = endOfPreviousMonth  - 100; // >


    for ( int k = 0; k < incomes.size(); ++k) {

        string dateS = incomes[k].getIncomeDate();
        int dateXmlFile = AuxiliaryMethods::transformStringToInt(dateS);

        if ( dateXmlFile > beginOfPreviousMonth && dateXmlFile < endOfPreviousMonth ) {

            previousMonthIncomes += incomes[k].getIncomeAmount();
            incomesData.push_back(incomes[k]);

        }

    }

    return previousMonthIncomes;

}

double AccountOperations::getPreviousMonthExpense() {

    Date date;
    expensesData.clear();

    date = AuxiliaryMethods::getSystemTime();

    int actualDateInt = 0, daysCountInPreviousMonth = 0, numberOfActualDay = 0, endOfPreviousMonth = 0, beginOfPreviousMonth = 0 ;
    double previousMonthExpenses = 0;

    actualDateInt = readActualDateAndConvertToInt();

    daysCountInPreviousMonth = AuxiliaryMethods::howManyDaysInMonth(  AuxiliaryMethods::transformStringToInt( date.getMonth() ) - 1 );

    numberOfActualDay = AuxiliaryMethods::transformStringToInt( date.getDay() );

    endOfPreviousMonth = actualDateInt - numberOfActualDay; // <

    beginOfPreviousMonth = endOfPreviousMonth  - 100; // >


    for ( int k = 0; k < expenses.size(); ++k) {

        string dateS = expenses[k].getExpenseDate();
        int dateXmlFile = AuxiliaryMethods::transformStringToInt(dateS);


        if ( dateXmlFile > beginOfPreviousMonth && dateXmlFile < endOfPreviousMonth ) {

            previousMonthExpenses += expenses[k].getExpenseAmount();
            expensesData.push_back(expenses[k]);

        }

    }

    return previousMonthExpenses;

}

void AccountOperations::displayChoosenPeriodBalance() {

    if ( !incomes.empty() || !expenses.empty() ) {

        string dateString = "", dateToString = "";
        int dateFromInt = 0, dateToInt = 0;
        double incomesAmount = 0, expensesAmount = 0;


dateLabel:
        cout << "Enter date from which would you like to search(Format: YYYY-MM-DD): ";
        dateString = AuxiliaryMethods::readLine();

        if ( AuxiliaryMethods::checkDateIfCorrect(dateString) ) {

            dateFromInt = AuxiliaryMethods::fetchDigitsFromDate(dateString);

            cout << "Enter a date to which would you like to search(Format: YYYY-MM-DD): ";
            dateToString = AuxiliaryMethods::readLine();

            if ( AuxiliaryMethods::checkDateIfCorrect(dateToString)) {

                dateToInt = AuxiliaryMethods::fetchDigitsFromDate(dateToString);

            } else {

                cout << "Entered date is incorrect! Try one more time.\n";
                system("pause");
                system("cls");
                goto dateLabel;
            }

        } else {
            cout << "Entered date is incorrect! Try one more time.\n";
            system("pause");
            system("cls");
            goto dateLabel;

        }


        incomesAmount = getChoosenPeriodIncome(dateFromInt, dateToInt);
        expensesAmount = getChoosenPeriodExpense(dateFromInt, dateToInt);

        AuxiliaryMethods::sortIncomesAndExpenses(incomesData,expensesData);
        AuxiliaryMethods::displayBalance(incomesAmount, expensesAmount, 3);

    } else
        cout << "There is no incomes or expenses\n";
    system("pause");
}

double AccountOperations::getChoosenPeriodIncome(int dateFrom, int dateTo) {

    incomesData.clear();
    double periodIncome = 0;

    for ( int j = 0; j < incomes.size(); ++j) {

        string dateS = incomes[j].getIncomeDate();
        int dateXmlFile = AuxiliaryMethods::transformStringToInt(dateS);

        if ( dateXmlFile >= dateFrom && dateXmlFile <= dateTo ) {

            periodIncome += incomes[j].getIncomeAmount();
            incomesData.push_back(incomes[j]);

        }

    }

    return periodIncome;

}

double AccountOperations::getChoosenPeriodExpense(int dateFrom, int dateTo) {

    expensesData.clear();
    double periodExpense = 0;

    for ( int j = 0; j < expenses.size(); ++j) {

        string dateS = expenses[j].getExpenseDate();
        int dateXmlFile = AuxiliaryMethods::transformStringToInt(dateS);

        if ( dateXmlFile >= dateFrom && dateXmlFile <= dateTo ) {

            periodExpense += expenses[j].getExpenseAmount();
            expensesData.push_back(expenses[j]);
        }

    }

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
        expense.setExpenseDate( AuxiliaryMethods::convertIntToString(dateInt) );

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
            expense.setExpenseDate( AuxiliaryMethods::convertIntToString(dateInt) );

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

