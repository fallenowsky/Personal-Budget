#ifndef _ACCOUNTOPERATIONS_H
#define _ACCOUNTOPERATIONS_H


#include "Income.h"
#include "Expense.h"
#include "IncomeFile.h"
#include "ExpenseFile.h"
#include "Date.h"
#include "AuxiliaryMethods.h"



class AccountOperations {

    IncomeFile incomeFile;
    ExpenseFile expenseFile;
    vector <Income> incomes;
    vector <Expense> expenses;
    vector <Income> incomesData;
    vector <Expense> expensesData;

    Income getIncomeData(const int loggedUserId);
    Expense getExpenseData(const int loggedUserId);
    int readActualDateAndConvertToInt();
    double getActualMonthIncome();
    double getActualMonthExpense();
    double getChoosenPeriodIncome(int dateFrom, int dateTo);
    double getChoosenPeriodExpense(int dateFrom, int dateTo);
    double getPreviousMonthIncome();
    double getPreviousMonthExpense();

public:

    AccountOperations(int LOGGED_USER_ID) : incomeFile(LOGGED_USER_ID), expenseFile(LOGGED_USER_ID)  {

        incomes = incomeFile.readLoggedUserIncomesFromXmlFile();
        expenses = expenseFile.readLoggedUserExpensesFromXmlFile();
    }


    void addIncome(int loggedUserId);
    void addExpense(int loggedUserId);
    void displayActualMonthBalance();
    void displayPreviousMonthBalance();
    void displayChoosenPeriodBalance();



};





#endif // _ACCOUNTOPERATIONS_H

