#include <iostream>
#include <string>

using namespace std;
#include "Ratio.h"

int main() {
   cout << "Vous devez comparer le programme source et son affichage pour vérifier que vous comprennez bien toutes les opérations." << endl << endl;

   // 1: Constructeur avec deux paramètres (numérateur et dénominateur) :
   cout << "1 : Construction de r1 avec deux paramètres entiers : le numérateur et le dénominateur" << endl;
 //  Ratio r1(1, 4);

 
   // 2: Constructeur avec un seul paramètre fabricant l'entier équivalent, ici 3/1 :
   cout << endl << endl
        << "2 : Construction de r2 avec un seul paramètre entier : le numérateur" << endl
        << "On veut obtenir le rationnel équivalent à cet entier naturel." << endl
        << "Le dénominateur du rationnel à construire est fixé à un." << endl;
 //  Ratio r2(3);

 
   // 3: Constructeur sans paramètre, équivalent à 0/1 :
   cout << endl << endl
        << "3 : Construction de r3 sans aucun paramètre, ce qu'on appelle le constructeur par défaut" << endl
        << "Le numérateur est fixé à zéro et le dénominateur à un." << endl;
//   Ratio r3;
   cout << "Sur le même principe, construction de r4 et r5." << endl;
//   Ratio r4(1, 4);
//   Ratio r5(5, 6);

 
   // 4: Fonction membre Ratio::ecrire()
   cout << endl << endl
        << "4: Affichage avec Ratio::ecrire() :" << endl;
 //  cout << "un quart : r1="; r1.ecrire(); cout << endl;
 //  cout << "trois    : r2="; r2.ecrire(); cout << endl;
 //  cout << "zero     : r3="; r3.ecrire(); cout << endl;

 
   // 5: Fonction Ratio::affecter(int numerateur,int denominateur)
   //    avec valeurs par défaut identiques à celles du constructeur :
   cout << endl << endl
        << "5: Fonction Ratio::affecter()" << endl;
//   r2.affecter(2, 3); cout << "deux tiers : r2="; r2.ecrire(); cout << endl;
//   r3.affecter(2);    cout << "deux       : r3="; r3.ecrire(); cout << endl;
//   r1.affecter();     cout << "zero       : r1="; r1.ecrire(); cout << endl;
//   cout << "Affectation de 1/4 a r1." << endl;
//   r1.affecter(1,4); // Juste pour remettre une valeur non-nulle...
//   cout << "un quart   : r1="; r1.ecrire(); cout << endl;

 
   // 6: Fonction Ratio::valeur_reelle() :
   cout << endl << endl
        << "6: Ratio::valeur_reelle()" << endl;
//   cout << "r2="; r2.ecrire(); cout << "=" << r2.valeur_reelle()
//        << " <- Remarquez que le calcul est seulement une valeur approchée arrondie : il faudrait une infinité de '6' après la virgule..." << endl;

 
   // 7: Fonction Ratio::inverser()
   cout << endl << endl
        << "7: Ratio::inverser()." << endl;
//   cout << "r3=";                 r3.ecrire();
//   r3.inverser();
//   cout << ", Inverser r3 : r3="; r3.ecrire(); cout << endl;

 
   // 8: Constructeur de copie :
   cout << endl << endl
        << "8: Construction de r comme copie de r1 :" << endl;
   {
//      Ratio r(r1);
//      cout << " r="; r.ecrire(); cout << endl;
      // Sur cette classe particulière, même si vous ne la faites pas,
      // le constructeur par défaut fonctionnera correctement :
      // il suffit en effet de copier les données membres d'un objet dans l'autre.
      // Respectez cependant la consigne et ECRIVEZ DE TOUTES FACONS le constructeur de copie.
   }

 
   // 9: Affichage dans les constructeurs et ajout du destructeur :
   //    Ajoutez le destructeur pour Ratio.
   //    Ajoutez des affichages sur cout dans les constructeurs et le destructeur pour indiquer
   //    quand ont lieu les constructions et les destructions. Cela ne se fait pas habituellement
   //    (les constructions et destructions sont silencieuses !),
   //    mais cela vous permettra de vérifier que vous avez compris.
   //    Comparez avec l'affichage obtenu avec le résultat fourni.
   cout << endl << endl
        << "9: Construction de 4/5 :" << endl;   
   {
//      Ratio r(4,5);
      cout << "Destruction de 4/5 :" << endl;
   }


   // 10: Accesseurs numerateur() et denominateur()
   //     qui renvoient la valeur de la donnée membre correspondante :
   cout << endl << endl
        << "10: Accesseurs :" << endl;
//   cout << "r2="; r2.ecrire(); cout << ", numérateur de r2 = " << r2.numerateur() << ", denominateur de r2 = " << r2.denominateur() << endl;

 
   // 11: S'assurer que toutes les fonctions qui ne modifient pas le Rationnel sont marquées en conséquence :
   cout << endl << endl
        << "11: operations constantes :" << endl;
   {
//      const Ratio & r = r2; // Astuce pour faire que le nouveau nom r corresponde dans ce bloc à une version constante de r2.
//      cout << "r="; r.ecrire(); cout << "=" << r.valeur_reelle() << endl;
//      cout << "accesseurs : r.numerateur()->"
//           << r.numerateur()
//           << ", r.denominateur()->"
//           << r.denominateur() << endl;
   }

 
   // 12: Operateur << pour les Ratio :
   // Une fois que vous savez faire celui-là, aucune raison sur vos prochaines classes de faire la fonction membre ecrire() !
   cout << endl << endl
        << "12: operateur d'envoi sur un flux :" << endl;
//   cout << "r1="<< r1 << endl;

 
   // 13: Opérateur d'affectation :
   cout << endl << endl
        << "13: operateur d'affectation :" << endl;
//   r2 = r1;         // affectation à partir d'une variable nommée.
//   cout << "La variable r1=" << r1 << " a bien ete affectée a r2=" << r2 << endl;

 
   // 14: Opérateurs arithmétiques :
   cout << endl << endl
        << "14: operateurs arithmétiques :" << endl
        << "(Il est normal d'avoir des constructions-destructions pour chaque résultat intermédiaire, et vous devez identifier quand elles se produisent !)" << endl;
//   cout << "r4=" << r4 << ", r5=" << r5 << endl;
   cout << endl;
//   cout << r4 << " + " << r5 << " = " << r4 + r5 << endl;
   cout << endl;
//   cout << r4 << " - " << r5 << " = " << r4 - r5 << endl;
   cout << endl;
//   cout << r4 << " * " << r5 << " = " << r4 * r5 << endl;
   cout << endl;
//   cout << r4 << " / " << r5 << " = " << r4 / r5 << endl;

 
   // 15: Autres opérateurs d'affectation :
   cout << endl << endl
        << "15: autres operateurs d'affectation :" << endl;
   {
//      r2 = r4; r1 = r5;
//      cout << "r1=" << r1 << ", r2=" << r2 << ", r3=" << r3 << endl;
//      r3 = r2 += r1; // r2 += r1 équivalent à r2 = r2 + r1;
      cout << "* * * Remarquez qu'il n'y a pas ici de contruction-destruction ! * * *" << endl;
//      cout << "r3 = r2 += r1;"<< endl << "r1=" << r1 << ", r2=" << r2 << ", r3=" << r3 << endl;

//      r2 = r4; r1 = r5;
//      cout << endl << "r1=" << r1 << ", r2=" << r2 << endl;
//      r3 = r2 -= r1; // Idem avec -=
//      cout << "r3 = r2 -= r1;"<< endl << "r1=" << r1 << ", r2=" << r2 << ", r3=" << r3 << endl;

//      r2 = r4; r1 = r5;
//      cout << endl << "r1=" << r1 << ", r2=" << r2 << endl;
//      r3 = r2 *= r1; // Idem avec *=
//      cout << "r3 = r2 *= r1;"<< endl << "r1=" << r1 << ", r2=" << r2 << ", r3=" << r3 << endl;

//      r2 = r4; r1 = r5;
//      cout << endl << "r1=" << r1 << ", r2=" << r2 << endl;
//      r3 = r2 /= r1; // Idem avec /=
//      cout << "r3 = r2 /= r1;"<< endl << "r1=" << r1 << ", r2=" << r2 << ", r3=" << r3 << endl;
   }

 
   // 16: Opérateurs de comparaison :
   cout << endl << endl
        << "16: operateurs de comparaison :" << endl;
   {
//      Ratio r(10, 12);
//      if (r1 == r)
//      cout << r1 << "==" << r << endl; // Souvenez vous que 5/6 est égal à 10/12 !
//      if (r2 != r)
//      cout << r2 << "!=" << r << endl;
   }

 
   // 17: Opérateurs de pré et post incrémentation et décrémentation :
   cout << endl << endl
        << "17: Opérateurs de pré et post incrémentation et décrémentation :" << endl;
   {
//      Ratio r;
//      cout << endl << "r=" << r << ", r5=" << r5 << endl;
//      r = r5++;
//      cout << "r = r5++; "<< endl << "r=" << r << ", r5=" << r5 << endl;

//      r.affecter();
//      cout << endl << "r=" << r << ", r5=" << r5 << endl;
//      r = r5--;
//      cout << "r = r5--; "<< endl << "r=" << r << ", r5=" << r5 << endl;

      cout << endl << "Les opérateurs suivants n'utilisent pas de variable locale, " << endl
           << "et se contentent de renvoyer une référence sur le rationnel courant" << endl;
//      r.affecter();
//      cout << "r=" << r << ", r5=" << r5 << endl;
//      r = ++r5;
//      cout << "r = ++r5; "<< endl << "r=" << r << ", r5=" << r5 << endl;

//      r.affecter();
//      cout << endl << "r=" << r << ", r5=" << r5 << endl;
//      r = --r5;
//      cout << "r = --r5; "<< endl << "r=" << r << ", r5=" << r5 << endl;
   }

 
   // 18: Destruction des objets :
   // On arrive à la fin du main, donc les variables qui lui sont locales sont
   // détruites. Pour les instances de Ratio (c'est-à-dire les variables du type
   // Ratio) qui doivent être détruites, un appel au destructeur ~Ratio() est
   // automatiquement effectué pour chacune d'entre elles.
//   cout << endl << endl
//        << "18: Destruction de r1, r2, r3, r4 et r5 :" << endl;

   
   return 0;
}
