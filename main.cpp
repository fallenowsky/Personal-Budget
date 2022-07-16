#include <iostream>
#include <time.h>
#include "Markup.h"


using namespace std;


struct User {


    string id, login, haslo, imie, nazwisko;

};



int main()
{
    CMarkup xml;
    User user;

   /*
    int id = 0;
    string login = "", haslo = "";
   cout << "Podaj login: "; cin >> login;
   cout << "Podaj haslo: "; cin >> haslo;




    bool fileExists = xml.Load( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\proba_XML.xml" ); // zwraca 1 jesli otworzy plik i go zaladuje. Laduje informacje z pliku

    if ( !fileExists )
        xml.AddElem("Users"); // dodanie pierwszej galezi

        xml.FindElem();                      // przechodzenie miedzy kolejnymi wezlami/elementami.Zaglebianie sie do kolejnych galezi pliku XML. Znajduje korzen
        xml.IntoElem();                     // wchodzi do korzenia
        xml.AddElem("User");               // dodaje nowy wezel
        xml.IntoElem();                         // wchodzi do tego wezla
        xml.AddElem("UserId",id);               // dodaje znacznik 1
        xml.AddElem("Login", login);           // dodaje znacznik 2
        xml.AddElem("Password", haslo);      // dodaje znacznik 3
        xml.AddElem("Name", "Marcin");

        xml.AddElem("Surname", "Miaso");


        xml.Save("proba_XML.xml"); // zapisanie pliku pod podanu nazwa w katalogu z projektem

    */


    bool fileExists = xml.Load( "C:\\Programming\\Repos\\projektFinanse\\personalBudget\\proba_XML.xml" );

    if ( fileExists ){

        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        xml.FindElem();
        xml.IntoElem();

         xml.FindElem();
         string id = xml.GetData();

         xml.OutOfElem();

         cout << id << endl;


         while ( xml.FindElem() ){

         xml.IntoElem();
         xml.FindElem();
         string id1 = xml.GetData();
         cout << id1 << endl;
         xml.OutOfElem();

         }






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

    return 0;
}
