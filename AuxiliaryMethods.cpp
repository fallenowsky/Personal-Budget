#include "AuxiliaryMethods.h"



char AuxiliaryMethods::displayMainMenu() {

    string choice = "";

    system("cls");

    cout << endl;
    cout << ">>>Main MENU<<< \n";
    cout << "1.User register\n";
    cout << "2.Log-in user\n";
    cout << "9.Exit program\n\n";
    cout << "Your choice: ";
    choice = readLine();
    //cin.get();

  if ( ifSignCorrect(choice) ){
            return choice[0];
  }


}

char AuxiliaryMethods::displayUserMenu() {

    char choice = {};

    system("cls");
    cout << endl;
    cout << "1. Add income\n";
    cout << "2. Add expense\n";
    cout << "3. Display actual month balance\n";
    cout << "4. Display previous month balance\n";
    cout << "5. Display selected period balance\n";
    cout << "6. Change user password\n";
    cout << "7. Log-out user\n\n";
    cout << "Your choice: ";
    cin >> choice;
    cin.get();


    return choice;

}

void AuxiliaryMethods::sortIncomesAndExpenses(vector <Income> incomes, vector <Expense> expenses){

    vector <double> datesOfIncomes;
    vector <double> datesOfExpenses;

    Income income;
    Expense expense;

    int incomesCount = incomes.size();
    int expensesCount = expenses.size();
    int loopRepeats = 0;

    if ( incomesCount >= expensesCount )
            loopRepeats = incomesCount;
            else
                loopRepeats = expensesCount;

    for ( int i = 0; i < loopRepeats; ++i){

           datesOfIncomes.push_back( incomes[i].getIncomeDate() ) ;


    }

    for( int j = 0; j < expensesCount; ++j){
        datesOfExpenses.push_back( expenses[j].getExpenseDate() );

    }

    sort( datesOfIncomes.begin(), datesOfIncomes.end() );
    sort( datesOfExpenses.begin(), datesOfExpenses.end() );

   // for (int i = 0; i < loopRepeats; ++i){

   //     cout << fixed << datesOfExpenses[i] <<endl;
    //    system("pause");
   // }

    for ( int j = 0; j < loopRepeats; ++j){

        for (int k = 0; k < incomesCount; ++k){

            if ( datesOfIncomes[j] == incomes[k].getIncomeDate() ){

                income.setIncomeId( incomes[k].getIncomeId() );
                income.setIncomeUserId( incomes[k].getIncomeUserId() );
                income.setIncomeDate( incomes[k].getIncomeDate() );
                income.setIncomeItem( incomes[k].getIncomeItem() );
                income.setIncomeAmount( incomes[k].getIncomeAmount() );
                break;

                }

            }

        for ( int l = 0; l < expensesCount; ++l){

                if ( datesOfExpenses[j] ==  expenses[l].getExpenseDate() ){

                    expense.setExpenseId( expenses[l].getExpenseId() );
                    expense.setExpenseUserId( expenses[l].getExpenseUserId() );
                    expense.setExpenseDate( expenses[l].getExpenseDate() );
                    expense.setExpenseItem( expenses[l].getExpenseItem() );
                    expense.setExpenseAmount( expenses[l].getExpenseAmount() );
                    break;
                }

        }

        displaySortedIncomesAndExpenses(income, expense);

    }
    //system("pause");

}

void AuxiliaryMethods::displaySortedIncomesAndExpenses(Income income,Expense expense){


 if ( income.getIncomeId() > 0 && expense.getExpenseUserId () ) cout << "\nIncome: "; if ( expense.getExpenseId() > 0 && expense.getExpenseUserId () ) cout << "\t\t\tExpense: \n\n";
 if ( income.getIncomeId() > 0 && expense.getExpenseUserId () ) cout << "Income ID: " << income.getIncomeId(); if ( expense.getExpenseId() > 0 && expense.getExpenseUserId () ) cout << "\t\t\tExpense id: " << expense.getExpenseId() <<endl;
 if ( income.getIncomeId() > 0 && expense.getExpenseUserId () ) cout << "Income User ID: " << income.getIncomeUserId(); if ( expense.getExpenseId() > 0 && expense.getExpenseUserId () )cout  <<  "\t\tExpense User ID: " << expense.getExpenseUserId() <<endl;
 if ( income.getIncomeId() > 0 && expense.getExpenseUserId () ) cout << "Income Date: " << income.getIncomeDate(); if ( expense.getExpenseId() > 0 && expense.getExpenseUserId () )  cout <<  "\t\tExpense Date: " << expense.getExpenseDate() <<endl;
 if ( income.getIncomeId() > 0 && expense.getExpenseUserId () ) cout << "Income Item: " << income.getIncomeItem(); if ( expense.getExpenseId() > 0 && expense.getExpenseUserId () )  cout <<  "\t\tExpense Item: " << expense.getExpenseItem() <<endl;
 if ( income.getIncomeId() > 0 && expense.getExpenseUserId () ) cout << "Income Amount: " << income.getIncomeAmount(); if ( expense.getExpenseId() > 0 && expense.getExpenseUserId () ) cout  <<  "\t\tExpense Amount: " << expense.getExpenseAmount() <<endl << endl;



}


void AuxiliaryMethods::displayBalance(double incomes, double expenses, int whichBalance){

string balanceType = "";

    if ( whichBalance == 1 )
        balanceType = " actual month ";
    else if ( whichBalance == 2)
        balanceType = " previous month ";
    else
        balanceType = " choosen period of time ";

    cout <<"Your incomes from" << balanceType << "are equals to " << incomes;
    cout <<"\t Your expenses from" << balanceType << "are equals to " << expenses << endl;
    cout << "\nYour balance from" << balanceType <<": " << incomes - expenses << endl;

    system("pause");


}



bool AuxiliaryMethods::ifSignCorrect(string choice){

    int dataLength = choice.size();

    while ( true ){

        if ( dataLength > 1){
            cout << "It's not a single sign! Try one more time: ";
            choice = readLine();
            dataLength = choice.length();
            continue;
        }else
        return true;

    }

}

string AuxiliaryMethods::readLine() {

    string input = "";

    getline(cin, input);

    return input;
}

int AuxiliaryMethods::transformStringToInt(string stringNumber) {

    stringstream ss;
    int intNumber = 0;

    ss << stringNumber;
    ss >> intNumber;

    return intNumber;
}

string AuxiliaryMethods::convertIntToString(int number) {

    string numberS = "";

    numberS = to_string(number);

    return numberS;
}

bool AuxiliaryMethods::checkInputDataValidity(string userData) {

    if ( userData.length() > 3 )
        return true;
    else
        return false;

}

string AuxiliaryMethods::transformFirstLetterToHighRestToLow(string userData) {

label:

    int signsAmmount = userData.length();
    int counter = 0;

    for ( int k = 0; k < signsAmmount; ++k ) {

        if ( ( (userData[k] >= 97 && userData[k] <= 122) || (userData[k] >= 65 && userData[k] <= 90) ) && (signsAmmount > 3) )
            counter++;

    }

    if ( counter == signsAmmount ) {

        for ( int i = 0; i < signsAmmount; ++i) {

            if( i == 0) {

                if ( (userData[i] >= 97 && userData[i] <= 122) )
                    userData[i] -= 32;
                else
                    continue;

            } else {

                if ( (userData[i] >= 65 && userData[i] <= 90) )
                    userData[i] += 32;
                else
                    continue;
            }

        }
        return userData;


    } else {

        cout <<"\n You have entered incorrect user Name or Surname. Try one more time: \n";
        userData = readLine();
        goto label;
    }
}

Date AuxiliaryMethods::getSystemTime() {

    Date date;
    int day = 0, month = 0;
    string dayS = "0", monthS = "0";

    time_t timeT;
    time( & timeT );
    struct tm * st_time;
    st_time = localtime( & timeT );

    day = st_time -> tm_mday;
    month = st_time -> tm_mon + 1;

    if ( day < 10 ) {
      dayS += convertIntToString(day);
      day = transformStringToInt(dayS);
    }
    if ( month < 10){
        monthS += convertIntToString(month);
        month = transformStringToInt(monthS);
    }
    date.setDay( day );
    date.setMonth( month + 1);
    date.setYear( st_time -> tm_year + 1900 );

    return date;

}

double AuxiliaryMethods::convertStringToDouble(string stringNumber) {

    size_t number;
    double ammount = 0;

    ammount = stod( stringNumber, &number );

    return ammount;
}

bool AuxiliaryMethods::checkDateIfCorrect(string &date) {

    bool dateFormat = ifDateFormatCorrect(date);
    bool yearDateMonth = ifYearMonthDayCorrect(date);
    eraseZerosIfExists(date);

    if ( dateFormat && yearDateMonth )
        return true;
    else
        return false;



}

bool AuxiliaryMethods::ifDateFormatCorrect(string date) {

    bool yearOk = true;
    bool monthOk = true;
    bool dayOk = true;
    bool dashOk = true;

    int yearSigns = 4;
    int monthCount = 7;
    int dayCounts = 10;
    int firstDashPosition = 4;
    int secondDashPosition = 7;


    for ( int i = 0; i < yearSigns; ++i ) {

        if ( isdigit(date[i] ) == false)
            yearOk = false;
    }

    for ( int i = 5; i < monthCount; ++i ) {

        if ( isdigit(date[i]) == false)
            yearOk = false;
    }

    for ( int i = 8; i < dayCounts; ++i ) {

        if ( isdigit(date[i]) == false)
            yearOk = false;
    }

    if( (date[firstDashPosition] != '-') || (date[secondDashPosition] != '-') )
        dashOk = false;

    if ( (yearOk && monthOk && dayOk && dashOk) )
        return true;
    else
        return false;

}

bool AuxiliaryMethods::ifYearMonthDayCorrect(string date) {

    Date systemDate;
    string numbersFromDateString = "";
    int year = 0;
    int month = 0;
    int day = 0;
    int daysInMonth = 0;
    bool yearIsOk;
    bool monthIsOk;
    bool dayIsOk;


    numbersFromDateString = date.substr(0,4);
    year = transformStringToInt(numbersFromDateString);

    systemDate = getSystemTime();

    if ( (year >= 2000) && (year <=  systemDate.getYear() ) )
        yearIsOk = true;


    numbersFromDateString = date.substr(5,2);
    month = transformStringToInt(numbersFromDateString);

    if ( year < systemDate.getYear() ) {

        if  ( ( month >= 1 && month <= 12) )
            monthIsOk = true;

    }

    else if ( year == systemDate.getYear() ) {

        if (  month > 0 && month <= systemDate.getMonth())
            monthIsOk = true;
    } else
        monthIsOk = false;


    numbersFromDateString = date.substr(8,2);
    day = transformStringToInt(numbersFromDateString);
    daysInMonth = howManyDaysInMonth(month);



    if ( day > 0 && day <= daysInMonth ) {
        dayIsOk = true;
    } else
        dayIsOk = false;



    if ( (yearIsOk && monthIsOk && dayIsOk ) )
        return true;
    else
        return false;

}

void AuxiliaryMethods::eraseZerosIfExists(string &date) {

    int amountOfSigns = date.size();

    for ( int i = 0; i < amountOfSigns; ++i) { //2022-04-05 // 2022-4-5

        if ( i == 5 || i == 7) {

            if (date[i] == '0') {

                date.erase(i,1);
                amountOfSigns = date.size();
            }

        }

    }
    if ( amountOfSigns == 10 && date[8] == '0')
        date.erase(8,1);

}

int AuxiliaryMethods::fetchDigitsFromDate(string date) { //2022-07-17

    string dateNumbers = "";
    int dateInt = 0;

    int dateSigns = date.size();

    if ( dateSigns == 10) {

        dateNumbers = date.substr(0,4);
        dateNumbers += date.substr(5,2);
        dateNumbers += date.substr(8,2);

    }
    if ( dateSigns == 9 && ( isdigit(date[7]) && isdigit(date[8]) ) ) {

        dateNumbers = date.substr(0,4);
        dateNumbers += date.substr(5,1);
        dateNumbers += date.substr(7,2);

    } else {

        dateNumbers = date.substr(0,4);
        dateNumbers += date.substr(5,2);
        dateNumbers += date.substr(8,1);
    }

    if ( dateSigns == 8 ) {

        dateNumbers = date.substr(0,4);
        dateNumbers += date.substr(5,1);
        dateNumbers += date.substr(7,1);

    }

    dateInt = transformStringToInt(dateNumbers);

    return dateInt;

}

bool AuxiliaryMethods::ifLeapYear() {

    Date date;

    date = getSystemTime();

    int year = date.getYear();

    if ( (year % 4 == 0  &&  year % 100 != 0) || (year % 400 == 0) )
        return 1;
    else
        return 0;
}

int AuxiliaryMethods::howManyDaysInMonth(int monthNumber) {

    if ( monthNumber == 1 || monthNumber == 3 || monthNumber == 5 || monthNumber == 7 || monthNumber == 8 || monthNumber == 10 || monthNumber == 12)
        return 31;
    else if ( monthNumber == 4 || monthNumber == 6 || monthNumber == 9 || monthNumber == 11 )
        return 30;
    else if ( monthNumber == 2 ) {

        if ( ifLeapYear() )
            return 29;
        else
            return 28;
    }

}


