#include "ExpenseFile.h"



void ExpenseFile::addLoggedUserExpenseToXmlFile(Expense expense) {

    bool ifIncomeFileExists = xmlExpenseFile.Load( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + EXPENSE_FILE_NAME );

    if ( !ifIncomeFileExists )
        xmlExpenseFile.AddElem("Expenses");

    xmlExpenseFile.FindElem();
    xmlExpenseFile.IntoElem();
    xmlExpenseFile.AddElem( "Expense" );
    xmlExpenseFile.IntoElem();
    xmlExpenseFile.AddElem( "ExpenseId", expense.getExpenseId() );
    xmlExpenseFile.AddElem( "ExpenseUserId", expense.getExpenseUserId() );
    xmlExpenseFile.AddElem( "ExpenseDate", expense.getExpenseDate() );
    xmlExpenseFile.AddElem( "ExpenseItem", expense.getExpenseItem() );
    xmlExpenseFile.AddElem( "ExpenseAmount", to_string( expense.getExpenseAmount() ) );

    xmlExpenseFile.Save( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + EXPENSE_FILE_NAME );

}

vector <Expense> ExpenseFile::readLoggedUserExpensesFromXmlFile() {

    Expense expense;
    vector <Expense> expenses;

    string userIdString;
    string xmlInput = "";
    int idUserXml = 0;

    bool ifExpenseFileExists = xmlExpenseFile.Load( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + EXPENSE_FILE_NAME );


    if ( ifExpenseFileExists ) {

        xmlExpenseFile.ResetPos();
        xmlExpenseFile.FindElem();
        xmlExpenseFile.IntoElem();

        while ( xmlExpenseFile.FindElem() == true ) {

            xmlExpenseFile.IntoElem();

            xmlExpenseFile.FindElem();
            xmlExpenseFile.FindElem();

            userIdString = xmlExpenseFile.GetData();

            idUserXml = AuxiliaryMethods::transformStringToInt(userIdString);


            if ( idUserXml == LOGGED_USER_ID) {

                xmlExpenseFile.ResetMainPos();

                xmlExpenseFile.FindElem();

                xmlInput = xmlExpenseFile.GetData();

                expense.setExpenseId( AuxiliaryMethods::transformStringToInt(xmlInput) );

                xmlExpenseFile.FindElem();

                xmlInput = xmlExpenseFile.GetData();
                expense.setExpenseUserId( AuxiliaryMethods::transformStringToInt(xmlInput) );

                xmlExpenseFile.FindElem();

                expense.setExpenseDate( xmlExpenseFile.GetData() );

                xmlExpenseFile.FindElem();
                expense.setExpenseItem( xmlExpenseFile.GetData() );

                xmlExpenseFile.FindElem();
                xmlInput = xmlExpenseFile.GetData();
                expense.setExpenseAmount( AuxiliaryMethods::convertStringToDouble(xmlInput) );


                expenses.push_back(expense);

            }

            xmlExpenseFile.OutOfElem();
        }

        xmlExpenseFile.Save( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + EXPENSE_FILE_NAME );

    }

    return expenses;

}

int ExpenseFile::getLastExpenseId() {


    bool ifEpenseFileExists = xmlExpenseFile.Load( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + EXPENSE_FILE_NAME );

    string xmlExpenseId = "";
    int xmlExpenseIdInt = 0;

    if ( ifEpenseFileExists ) {

        xmlExpenseFile.ResetPos();
        xmlExpenseFile.FindElem();
        xmlExpenseFile.IntoElem();

        while ( xmlExpenseFile.FindElem() == true ) {

            xmlExpenseFile.IntoElem();

            xmlExpenseFile.FindElem();
            xmlExpenseId = xmlExpenseFile.GetData();
            xmlExpenseIdInt = AuxiliaryMethods::transformStringToInt(xmlExpenseId);
            xmlExpenseFile.OutOfElem();

        }

    }

    return xmlExpenseIdInt;
}



