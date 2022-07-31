#include "UserMenedzer.h"



void UserMenedzer::userRegister() {

    userOperations.userRegister();
    users = userOperations.readUsersFromXmlFile();
    logInUser();

}

void UserMenedzer::logInUser() {

    if ( !ifUsersEmpty() ) {
        loggedUserId = userOperations.logInUser();

        if ( loggedUserId > 0 ) {
            accountOperations = new AccountOperations(loggedUserId,INCOME_FILE_NAME, EXPENSE_FILE_NAME);
            choice = AuxiliaryMethods::displayUserMenu();
            callCorrespondingFunctionUserMenu();
        }

    } else {

        cout << "\nFile with users is empty. Register a new user first! \n\n";
        system("pause");
        userRegister();

    }

}

void UserMenedzer::displayActualMonthBalance() {

    accountOperations -> displayActualMonthBalance();
    choice = AuxiliaryMethods::displayUserMenu();
    callCorrespondingFunctionUserMenu();

}

void UserMenedzer::displayPreviousMonthBalance() {

    accountOperations -> displayPreviousMonthBalance();
    choice = AuxiliaryMethods::displayUserMenu();
    callCorrespondingFunctionUserMenu();

}

void UserMenedzer::displaySelectedPeriodBalance() {

    accountOperations -> displayChoosenPeriodBalance();
    choice = AuxiliaryMethods::displayUserMenu();
    callCorrespondingFunctionUserMenu();

}

bool UserMenedzer::ifUsersEmpty() {

    if ( users.empty() == 1)
        return true;
    else
        return false;

}

void UserMenedzer::addIncome() {

    accountOperations -> addIncome(loggedUserId);
    choice = AuxiliaryMethods::displayUserMenu();
    callCorrespondingFunctionUserMenu();
}

void UserMenedzer::addExpense() {

    accountOperations -> addExpense(loggedUserId);
    choice = AuxiliaryMethods::displayUserMenu();
    callCorrespondingFunctionUserMenu();
}

void UserMenedzer::changeUserPassword() {

    userOperations.changeUserPassword(loggedUserId);
    choice = AuxiliaryMethods::displayUserMenu();
    callCorrespondingFunctionUserMenu();
}

void UserMenedzer::logOutUser() {

    char choice = {0};
    loggedUserId = 0;

    delete accountOperations;
    accountOperations = NULL;
    choice = AuxiliaryMethods::displayMainMenu();
    callCorresspondingFunctionMainMenu();

}
void UserMenedzer::callCorrespondingFunctionUserMenu() {

    switch(choice) {

    case '1':
        addIncome();
        break;
    case '2':
        addExpense();
        break;
    case '3':
        displayActualMonthBalance();
        break;
    case '4':
        displayPreviousMonthBalance();
        break;
    case '5':
        displaySelectedPeriodBalance();
        break;
    case '6':
        changeUserPassword();
        break;
    case '7':
        logOutUser();
        break;

    }


}

void UserMenedzer::callCorresspondingFunctionMainMenu() {

    for(;;) {
        switch(choice) {

        case '1':
            userRegister();
            break;
        case '2':
            logInUser();
            break;
        case '9':
            exit(0);
        default:
            cout << endl;
            cout << "It's non of the digit from above ! Try one more time!\n\n";
            system("pause");
            choice = AuxiliaryMethods::displayMainMenu();
            continue;
        }
        break;
    }

}

