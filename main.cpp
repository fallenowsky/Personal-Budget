#include <iostream>
#include <time.h>
#include "Markup.h"
#include "PersonalBudget.h"


using namespace std;


int main() {


        PersonalBudget personalBudget("usersXmlFile.xml", "incomeFile.xml", "expenseFile.xml");

return 0;

}


















    /*

        time_t czas; cout << czas << endl;
        struct tm * ptr;
        time( & czas );
        ptr = localtime( & czas );
        char * data = asctime( ptr );
        cout << "Data: " << data <<endl;
        time_t sukundy = time(NULL);


    */



