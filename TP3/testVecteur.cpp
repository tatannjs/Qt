#include <iostream>
#include <exception>
#include <iomanip>
#include <math.h>

using namespace std;

#include "Vecteur.h"

long double f1(long double);

long double f2(long double, long double);

int main() {
   long double t2[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
   long double t3[5] = {2.0, 3.0, 4.0, 5.0, 6.0};
   
   // Constructeurs
   // 1 - Vecteur de dimension quelconque.
//   Vecteur v0(4, 0.0);

   // 2 - Vecteur vide (dimension 0)
//   Vecteur v1;
 
   // 3 - Vecteur contruit à partir d'une dimension et d'un tableau
//   Vecteur v2(5, t2);
//   Vecteur v3(5, t3);

   // 4 - Constructeur de recopie
//   Vecteur v4(v2);

   // Précicion d'affichage des réels avec 2 chiffres après la virgule.
   cout.precision(2);

   // 7 - Opérateur de flux en sortie
   cout << "1 - Vecteur de dimension quelconque" << endl;
//   cout << "V0 = " << v0 << endl << endl;

   cout << "2 - Vecteur vide" << endl;
//   cout << "V1 = " << v1 << endl << endl;

   cout << "3 - Vecteur construit à partir d'une dimension et d'un tableau" << endl;
//   cout << "V2 = " << v2 << endl;
//   cout << "V3 = " << v3 << endl << endl;

   cout << "4 - Constructeur de recopie (v4 à partir de v2)" << endl;
//   cout << "V4 = " << v4 << endl << endl;

   cout << "6 - Taille d'un vecteur" << endl;
//   cout << "V3 : " << v3.size() << endl << endl;

   // 8 - Affectation
   cout << "8 - Affectation v0 = v2" << endl;
/*
   v0 = v2;
   cout << "V0 = " << v0 << endl << endl;
*/

   // 9 - Indexation
   cout << "9 - Indexation v0[0]" << endl;
//   cout << "V0[0] = " << v0[0] << endl;
   cout << "9 - Indexation V0[0] = V0[3]" << endl;
/*
   v0[0] = v0[3];
   cout << "v0[0] = " << v0[0] << endl << endl;
*/

   // 10 - Norme
   cout << "10 - Norme de V0" << endl;
/*
   cout << "V0 = " << v0 << endl;
   cout << "Norme de V0 = " << v0.norme() << endl << endl;
*/

   // 11 - Normalisation
   cout << "11 - Norme de V0 (après normalisation)" << endl;
/*
   v0.normalise();
   cout << "V0 = " << v0 << endl;
   cout << "Norme de V0 = " << v0.norme() << endl << endl;
*/

    // 12 - Multiplication d'un vecteur par un scalaire
   cout << "12 - Multiplication d'un vecteur par un scalaire" << endl;
/*
   cout << "V2 * 2 = " << v2 * 2 << endl;
   cout << "2 * V2 = " << 2 * v2 << endl << endl;
*/

   // 13 - Opérateur - unaire
   cout << "13 - Opérateur - unaire" << endl;
//   cout << "-V1 = " << -v2 << endl << endl;

   // 14 - Addition et soustraction de 2 vecteurs
   cout << "14 - Addition et soustraction de 2 vecteurs" << endl;
/*
   cout << "V2 = " << v2 << endl;
   cout << "V3 = " << v3 << endl;
   cout << "V2 + V3 = ";
   try {
       cout << (v2 + v3) << endl;
   }
   catch (Erreur & e) {
      cout << e.what() << endl;
   }
   cout << "V3 - V2 = ";
   try {
       cout << (v3 - v2) << endl << endl;
   }
   catch (Erreur & e) {
      cout << e.what() << endl;
   }
*/

   // 15 - Application d'une fonction à 1 argument
   cout << "15 - Application d'une fonction à 1 argument" << endl;
/*
   cout << "V4 = " << v4 << endl;
   cout << "V4.appliquer1(f1) = " << v4.appliquer1(f1) << endl << endl;
*/

   // 16 - Produit scalaire de 2 vecteurs
   cout << "16 - Produit scalaire de 2 vecteurs" << endl;
/*
   cout << "V2 * V3 = ";
   try {
       cout << (v2 * v3) << endl  << endl;
   }
   catch (Erreur & e) {
      cout << e.what() << endl;
   }
*/

   // 17 - Opérateur de flux en entrée
   cout << "17 - Opérateur de flux en entrée" << endl;
/*
   cout << "Entrez un vecteur : " << endl;
   cin >> v1;
   if (! cin) {
      cout << "ERREUR de lecture\n";
      exit (-1);
   }
   cout << "V1 = " << v1 << endl << endl;
*/

   // 18 - Produit vectoriel de 2 vecteurs
   cout << "18 - Produit vectoriel de 2 vecteurs" << endl;
/*
   cout << "Entrez un vecteur V1 : " << endl;
   cin >> v1;
   cout << "Entrez un vecteur V2 : " << endl;
   cin >> v2;
   cout << "V1 = " << v1 << endl;
   cout << "V2 = " << v2 << endl;
   cout << "V1 ^ V2 = " << v1 << " ^ " << v2 << " = " << (v1 ^ v2) << endl << endl;
*/

   // 19 - Application d'une fonction à 2 argument
   cout << "19 - Application d'une fonction à 2 arguments" << endl;
/*
   try {
      cout << "appliquer2(f2, V1, V2) = " << appliquer2(f2, v1, v2) << endl << endl;
   }
   catch(Erreur & e) {
      cout << e.what() << endl;
   }
*/

   return 0;
}

long double f1(long double x) {
   return x / 2;
}

long double f2(long double x, long double y) {
   return (x + y) / 2;
}
