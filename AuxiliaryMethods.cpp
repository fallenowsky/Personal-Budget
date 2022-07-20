#include "AuxiliaryMethods.h"



char AuxiliaryMethods::displayMainMenu(){

    char choice = {};

     system("cls");

     cout << endl;
     cout << ">>>REGISTATION MENU<<< \n";
     cout << "1.User register\n";
     cout << "2.Log-in user\n";
     cout << "9. Exit program\n";
     cout << "Your choice: "; cin >> choice;

     return choice;
}


string AuxiliaryMethods::readLine(){

    string input = "";

    getline(cin, input);

    return input;
}
