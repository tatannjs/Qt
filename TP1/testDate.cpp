#include <iostream>
#include <string>

using namespace std;

#include "Date.h"

int main(int argc, char *argv[]) {

   Date dateDuJour = Date();
   Date dateDeux = Date(1,9,2012);

   t_DateFormat formatNumerique = Numerique;
   t_DateFormat formatCourt = DateCourt;
   t_DateFormat formatLong = DateLong;

   string chaine = dateDuJour.format(formatNumerique);
   cout << "Format numerique : " << chaine.c_str() << endl;
   chaine = dateDuJour.format(formatCourt);
   cout << "Format court : " << chaine.c_str() << endl;
   chaine = dateDuJour.format(formatLong);
   cout << "Format long : " << chaine.c_str() << endl;

   string chaine2 = dateDeux.format(formatNumerique);
   cout << "Format numerique : " << chaine2.c_str() << endl;
   chaine2 = dateDeux.format(formatCourt);
   cout << "Format court : " << chaine2.c_str() << endl;
   chaine2 = dateDeux.format(formatLong);
   cout << "Format long : " << chaine2.c_str() << endl;

   int nbJour = dateDuJour.nbJours(dateDeux);
   cout << "Nombre de jour d'ecart : " << nbJour << endl;

   return 0;
}
