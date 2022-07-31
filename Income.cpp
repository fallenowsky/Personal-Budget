#include "Income.h"


int Income::getIncomeId() {

    return this -> incomeId;
}

int Income::getIncomeUserId() {

    return this -> incomeUserId;
}

string Income::getIncomeDate() {

    return this -> incomeDate;
}

string Income::getIncomeItem() {

    return this -> incomeItem;
}

double Income::getIncomeAmount() {

    return this -> incomeAmount;
}

void Income::setIncomeId(int incomeId) {

    this -> incomeId = incomeId;
}

void Income::setIncomeUserId(int incomeUserId) {

    this -> incomeUserId = incomeUserId;
}

void Income::setIncomeDate(string incomeDate) {

    this -> incomeDate = incomeDate;
}

void Income::setIncomeItem(string incomeItem) {

    this -> incomeItem = incomeItem;
}

void Income::setIncomeAmount(double incomeAmount) {

    this -> incomeAmount = incomeAmount;
}
