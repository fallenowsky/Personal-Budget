#include "AuxiliaryMethods.h"



char AuxiliaryMethods::displayMainMenu() {

    char choice = {};

    system("cls");

    cout << endl;
    cout << ">>>Main MENU<<< \n";
    cout << "1.User register\n";
    cout << "2.Log-in user\n";
    cout << "3.Display all registered users\n";
    cout << "9.Exit program\n\n";
    cout << "Your choice: ";
    cin >> choice;
    cin.get();

    return choice;
}

char AuxiliaryMethods::displayUserMenu(){

    char choice = {};

    cout << endl;
    cout << "1. Add income\n";
    cout << "2. Add expense\n";
    cout << "3. Show current month balance\n";
    cout << "4. Show previous month balance\n";
    cout << "5. Show selected period balance\n";
    cout << "6. Change password\n";
    cout << "7. Log-out user\n\n";
    cout << "Your choice: ";
    cin >> choice;
    cin.get();

    return choice;

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

Date AuxiliaryMethods::getSystemTime(){

    Date date;

    time_t timeT;
    time( & timeT );
    struct tm * st_time;
    st_time = localtime( & timeT );

    date.setDay( st_time -> tm_wday );
    date.setMonth( st_time -> tm_mon );
    date.setYear( st_time -> tm_year );

   // std::cout << dzien << " :: " << miesiac << std::endl;

    return date;

}

double AuxiliaryMethods::convertStringToDouble(string stringNumber){

     size_t number;
     double ammount = 0;

    ammount = stod( stringNumber, &number );

    return ammount;
}

bool AuxiliaryMethods::checkDateIfCorrect(string date){

   bool dateFormat = ifDateFormatCorrect(date);
   bool yearDateMonth = ifYearMonthDayCorrect(date);

   if ( (dateFormat && yearDateMonth) )
    return true;
   else
    return false;



}

bool AuxiliaryMethods::ifDateFormatCorrect(string date){

    bool yearOk = true;
    bool monthOk = true;
    bool dayOk = true;
    bool dashOk = true;

    int yearSigns = 4;
    int monthCount = 7;
    int dayCounts = 10;
    int firstDashPosition = 4;
    int secondDashPosition = 7;


    for ( int i = 0; i < yearSigns; ++i ){

        if ( isdigit(date[i] ) == false)
            yearOk = false;
    }

    for ( int i = 5; i < monthCount; ++i ){

        if ( isdigit(date[i]) == false)
            yearOk = false;
    }

     for ( int i = 8; i < dayCounts; ++i ){

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

bool AuxiliaryMethods::ifYearMonthDayCorrect(string date){

    Date systemDate;
    string ammount = "";
    int year = 0;
    int month = 0;
    int day = 0;
    bool yearIsOk;
    bool monthIsOk;
    bool dayIsOk;


    ammount = date.substr(0,4);
    year = transformStringToInt(ammount);

    systemDate = getSystemTime();

    if ( (year >= 2000) && (year <=  systemDate.getYear() ) )
            yearIsOk = true;


    ammount = date.substr(5,2);
    month = transformStringToInt(ammount);

    if  ( ( month >= 1 && month <= systemDate.getMonth()) )
        monthIsOk = true;


    ammount = date.substr(8,2);
    day = transformStringToInt(ammount);

    if ( (day >= 1 && day <= systemDate.getDay()) )
        dayIsOk = true;

    if ( (yearIsOk && monthIsOk && dayIsOk ) )
        return true;
    else
        return false;

}

int AuxiliaryMethods::fetchDigitsFromDate(string date)
{

    string dateNumbers = "";
    int dateInt = 0;

    dateNumbers = date.substr(0,4);
    dateNumbers += date.substr(5,2);
    dateNumbers += date.substr(8,2);

    dateInt = transformStringToInt(dateNumbers);

    return dateInt;

}
