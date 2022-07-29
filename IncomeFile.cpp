#include "IncomeFile.h"



void IncomeFile::addLoggedUserIncomeToXmlFile(Income income) {


    bool ifIncomeFileExists = xmlIncomeFile.Load( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + INCOME_FILE_NAME );

    if ( !ifIncomeFileExists )
        xmlIncomeFile.AddElem("Incomes");

    xmlIncomeFile.FindElem();
    xmlIncomeFile.IntoElem();
    xmlIncomeFile.AddElem( "Income" );
    xmlIncomeFile.IntoElem();
    xmlIncomeFile.AddElem( "IncomeId", income.getIncomeId() );
    xmlIncomeFile.AddElem( "IncomeUserId", income.getIncomeUserId() );
    xmlIncomeFile.AddElem( "IncomeDate", income.getIncomeDate() );
    xmlIncomeFile.AddElem( "IncomeItem", income.getIncomeItem() );
    xmlIncomeFile.AddElem( "IncomeAmount",to_string( income.getIncomeAmount() ) );


    xmlIncomeFile.Save( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + INCOME_FILE_NAME );

}

vector <Income> IncomeFile::readLoggedUserIncomesFromXmlFile() {

    Income income;
    vector <Income> incomes;

    string userIdString;
    string xmlInput = "";
    int idUserXml = 0;

    bool ifIncomeFileExists = xmlIncomeFile.Load( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + INCOME_FILE_NAME );


    if ( ifIncomeFileExists ) {

        xmlIncomeFile.ResetPos();
        xmlIncomeFile.FindElem();
        xmlIncomeFile.IntoElem();

        while ( xmlIncomeFile.FindElem() == true ) {

            xmlIncomeFile.IntoElem();

            xmlIncomeFile.FindElem();
            xmlIncomeFile.FindElem();

            userIdString = xmlIncomeFile.GetData();

            idUserXml = AuxiliaryMethods::transformStringToInt(userIdString);


            if ( idUserXml == LOGGED_USER_ID) {

                xmlIncomeFile.ResetMainPos();

                xmlIncomeFile.FindElem();

                xmlInput = xmlIncomeFile.GetData();

                income.setIncomeId( AuxiliaryMethods::transformStringToInt(xmlInput) );

                xmlIncomeFile.FindElem();

                xmlInput = xmlIncomeFile.GetData();
                income.setIncomeUserId( AuxiliaryMethods::transformStringToInt(xmlInput) );

                xmlIncomeFile.FindElem();

                income.setIncomeDate( xmlIncomeFile.GetData() );

                xmlIncomeFile.FindElem();
                income.setIncomeItem( xmlIncomeFile.GetData() );

                xmlIncomeFile.FindElem();
                xmlInput = xmlIncomeFile.GetData();

                income.setIncomeAmount( AuxiliaryMethods::convertStringToDouble(xmlInput) );


                incomes.push_back(income);

            }

            xmlIncomeFile.OutOfElem();
        }

        xmlIncomeFile.Save( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + INCOME_FILE_NAME );

    }

    return incomes;

}

int IncomeFile::getLastIncomeId() {


    bool ifIncomeFileExists = xmlIncomeFile.Load( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\" + INCOME_FILE_NAME );

    string xmlIncomeId = "";
    int xmlIncomeIdInt = 0;

    if ( ifIncomeFileExists ) {

        xmlIncomeFile.ResetPos();
        xmlIncomeFile.FindElem();
        xmlIncomeFile.IntoElem();

        while ( xmlIncomeFile.FindElem() == true ) {

            xmlIncomeFile.IntoElem();

            xmlIncomeFile.FindElem();
            xmlIncomeId = xmlIncomeFile.GetData();
            xmlIncomeIdInt = AuxiliaryMethods::transformStringToInt(xmlIncomeId);
            xmlIncomeFile.OutOfElem();

        }

    }

    return xmlIncomeIdInt;
}



