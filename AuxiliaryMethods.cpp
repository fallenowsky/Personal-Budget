#include "AuxiliaryMethods.h"



char AuxiliaryMethods::displayMainMenu() {

    char choice = {};

    system("cls");

    cout << endl;
    cout << ">>>Main MENU<<< \n";
    cout << "1.User register\n";
    cout << "2.Log-in user\n";
    cout << "3.Display all registered users\n";
    cout << "9. Exit program\n\n";
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

        if ( (userData[k] >= 97 && userData[k] <= 122) || (userData[k] >= 65 && userData[k] <= 90) )
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
