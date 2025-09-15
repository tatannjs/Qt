#include <iostream>
#include <string>

using namespace std;

#include "Operation.h"

int main(int argc, char *argv[])
{
   Operation op1(1, 10, 2010, "Retrait distributeur", -1200);
   Operation op2(2, 10, 2010, "Remise de cheque", 458);
   Operation op3("Remise especes", 1000);

   cout << endl
        << "=== Details des operations ===" << endl
        << endl;

   op1.afficher();
   cout << endl;

   op2.afficher();
   cout << endl;

   op3.afficher();
   cout << endl;

   cout << "Nombre total d'operations creees : " << Operation::getCompteur() << endl;
   cout << "Nombre d'operations en cours : " << Operation::getNbOpEnCours() << endl;

   return 0;
}
