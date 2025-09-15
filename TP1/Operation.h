#include "Date.h"

class Operation {
   private:
      static  int compteur;
      static  int nbOpEnCours;
      int         numero;
      Date        date;
      string      libelle;
      float       montant;
   
   public:
      Operation(string libelle, float montant);
      Operation(int j, int m, int a, string libelle, float montant);
      ~Operation();
      static int getCompteur();
      static int getNbOpEnCours();
      int getNumero();
      Date getDate();
      string getLibelle();
      float getMontant();
      void afficher();
};

