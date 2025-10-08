#include <iostream>
#include <exception>
#include <math.h>

using namespace std;

#include "Vecteur.h"

// TODO : Problème de gestion de mémoire du tab
Vecteur::Vecteur()
{
    this->n = 0;
    this->t = NULL;
}

Vecteur::Vecteur(int n, long double valInit)
{
    this->n = n;
    this->t = new long double[n];
    for (int i = 0; i < n; i++)
    {
        this->t[i] = valInit;
    }
}

Vecteur::Vecteur(int n, long double *t)
{
    this->n = n;
    this->t = new long double[n];
    for (int i = 0; i < n; i++)
    {
        this->t[i] = t[i];
    }
}

Vecteur::~Vecteur()
{
    delete[] t;
}

Vecteur::Vecteur(const Vecteur &v)
{
    this->n = v.n;
    this->t = v.t;
}

int Vecteur::size() const
{
    return this->n;
}

Vecteur &Vecteur::operator=(const Vecteur &v)
{
    if (this != &v)
    {
        this->n = v.n;
        this->t = v.t;
    }
    return *this;
}

long double Vecteur::operator[](unsigned int i) const
{
    return this->t[i];
}

long double &Vecteur::operator[](unsigned int i)
{
    return this->t[i];
}

long double Vecteur::norme()
{
    long double somme = 0.0;
    for (int i = 0; i < this->n; i++)
    {
        somme += t[i] * t[i];
    }
    return sqrtl(somme);
}

void Vecteur::normalise()
{
    long double norme = this->norme();
    for (int i = 0; i < this->n; i++)
    {
        this->t[i] = this->t[i] / norme;
    }
}

ostream &operator<<(ostream &os, const Vecteur &v)
{
    os << "<" << v.n << ":";
    for (int i = 0; i < v.n; i++)
    {
        os << v.t[i];
        if (i < v.n - 1)
        {
            os << ",";
        }
    }
    os << ">";
    return os;
}

Vecteur operator-(const Vecteur &v)
{
    long double *t2 = new long double[v.n];
    for (int i = 0; i < v.n; i++)
    {
        t2[i] = -v.t[i];
    }
    Vecteur result(v.n, t2);
    delete[] t2;
    return result;
}

Vecteur operator*(const Vecteur &v, const long double x)
{
    long double *t2 = new long double[v.n];
    for (int i = 0; i < v.n; i++)
    {
        t2[i] = v.t[i] * x;
    }

    Vecteur result(v.n, t2);
    delete[] t2;
    return result;
}

Vecteur operator*(const long double x, const Vecteur &v)
{
    return v * x;
}
