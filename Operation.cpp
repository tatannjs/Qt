#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

#include "Operation.h"

int Operation::compteur = 0;
int Operation::nbOpEnCours = 0;

Operation::Operation(string libelle, float montant){
    compteur++;
    nbOpEnCours++;
    this->numero = compteur;

    this->date = Date();
    this->montant = montant;
    this->libelle = libelle;
    cout << "Appel du constructeur d'operation" << endl;
}

Operation::Operation(int j, int m, int a, string libelle, float montant){
    compteur++;
    nbOpEnCours++;
    this->numero = compteur;

    this->date = Date(j,m,a);
    this->montant = montant;
    this->libelle = libelle;
    cout << "Appel du constructeur d'operation avec date" << endl;
}

Operation::~Operation(){
    nbOpEnCours--;
    cout << "Appel du destructeur d'operation" << endl;
}

int Operation::getCompteur(){
    return compteur;
}

int Operation::getNbOpEnCours(){
    return nbOpEnCours;
}

int Operation::getNumero(){
    return this->numero;
}

Date Operation::getDate(){
    return this->date;
}

string Operation::getLibelle(){
    return this->libelle;
}

float Operation::getMontant(){
    return this->montant;
}

void Operation::afficher(){
    cout    << "Operation :" 
            << this->numero << " "
            << this->date.format(DateCourt) << " "
            << this->libelle << " "
            << this->montant
            << endl;
}
