#include "Expense.h"


int Expense::getExpenseId(){

    return this -> expenseId;
}

int Expense::getExpenseUserId(){

    return this -> expenseUserId;
}

string Expense::getExpenseDate(){

    return this -> expenseDate;
}

string Expense::getExpenseItem(){

    return this -> expenseItem;
}

double Expense::getExpenseAmount(){

    return this -> expenseAmount;
}

void Expense::setExpenseId(int expenseId){

    this -> expenseId = expenseId;
}

void Expense::setExpenseUserId(int expenseUserId){

    this -> expenseUserId = expenseUserId;
}

void Expense::setExpenseDate(string expenseDate){

    this -> expenseDate = expenseDate;
}

void Expense::setExpenseItem(string expenseItem){

    this -> expenseItem = expenseItem;
}

void Expense::setExpenseAmount(double expenseAmount){

    this -> expenseAmount = expenseAmount;
}
