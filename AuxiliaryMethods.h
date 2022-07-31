#ifndef _AUXILIARYMETHODS_H
#define _AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <time.h>
#include <vector>
#include <algorithm>

#include "Date.h"
#include "Income.h"
#include "Expense.h"

using namespace std;




class AuxiliaryMethods {

    static void eraseZerosIfExists(string &date);
    static bool ifDateFormatCorrect(string date);
    static bool ifYearMonthDayCorrect(string date);
    static bool ifLeapYear();
    static bool ifSignCorrect(string choice);
    static void displaySortedIncomesAndExpenses(vector <Income> &incomesSorted, vector <Expense> &expensesSorted);
    static void separateDateOktets(vector <Income> &incomesSorted, vector <Expense> &expensesSorted);
    static bool sortIncomesByDate( Income &income1,  Income &income2 );
    static bool sortExpensesByDate( Expense &income1, Expense &income2 );
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
    static void sortIncomesAndExpenses(vector <Income> incomes, vector <Expense> expenses);
    static void displayBalance(double incomes, double expenses, int whichBalance);



};


#endif // _AUXILIARYMETHODS_H
