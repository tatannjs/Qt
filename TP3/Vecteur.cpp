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
    this->t = new long double[n];
    for (int i = 0; i < n; ++i)
    {
        this->t[i] = v.t[i];
    }
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
        this->t = new long double[n];
        for (int i = 0; i < n; ++i)
        {
            this->t[i] = v.t[i];
        }
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

Vecteur Vecteur::appliquer1(long double (*f1)(long double)) const
{
    for (int i = 0; i < this->n; i++)
    {
        this->t[i] = f1(this->t[i]);
    }
    return *this;
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

istream &operator>>(istream &is, Vecteur &v)
{
    char ch;
    int n;

    // Lire le caractère '<'
    is >> ch;
    if (ch != '<')
    {
        is.setstate(ios::failbit);
        return is;
    }

    // Lire la dimension
    is >> n;
    if (!is || n <= 0)
    {
        is.setstate(ios::failbit);
        return is;
    }

    // Lire le caractère ':'
    is >> ch;
    if (ch != ':')
    {
        is.setstate(ios::failbit);
        return is;
    }

    // Allouer un nouveau tableau pour les valeurs
    long double *t = new long double[n];
    for (int i = 0; i < n; ++i)
    {
        is >> t[i];
        if (i < n - 1)
        {
            is >> ch;
            if (ch != ',')
            {
                is.setstate(ios::failbit);
                delete[] t;
                return is;
            }
        }
    }

    // Lire le caractère de fin '>'
    is >> ch;
    if (ch != '>')
    {
        is.setstate(ios::failbit);
        delete[] t;
        return is;
    }

    // Mettre à jour le vecteur lu
    delete[] v.t; // libère l'ancien tableau
    v.n = n;
    v.t = new long double[n];
    for (int i = 0; i < n; ++i)
        v.t[i] = t[i];

    delete[] t;
    return is;
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

Vecteur operator+(const Vecteur &v1, const Vecteur &v2)
{
    if (v1.n != v2.n)
        throw Erreur("Erreur : les vecteurs n'ont pas la même dimension pour l'addition.");

    long double *t_res = new long double[v1.n];
    for (int i = 0; i < v1.n; ++i)
    {
        t_res[i] = v1.t[i] + v2.t[i];
    }

    Vecteur result(v1.n, t_res);
    delete[] t_res;
    return result;
}

Vecteur operator-(const Vecteur &v1, const Vecteur &v2)
{
    if (v1.n != v2.n)
        throw Erreur("Erreur : les vecteurs n'ont pas la même dimension pour l'addition.");

    long double *t_res = new long double[v1.n];
    for (int i = 0; i < v1.n; ++i)
    {
        t_res[i] = v1.t[i] - v2.t[i];
    }

    Vecteur result(v1.n, t_res);
    delete[] t_res;
    return result;
}

long double operator*(const Vecteur &v1, const Vecteur &v2)
{
    if (v1.n != v2.n)
        throw Erreur("Erreur : les vecteurs n'ont pas la même dimension pour le produit scalaire.");

    long double produit = 0.0;
    for (int i = 0; i < v1.n; ++i)
    {
        produit += v1.t[i] * v2.t[i];
    }

    return produit;
}

Vecteur operator^(const Vecteur &v1, const Vecteur &v2)
{
    if (v1.n != 3 || v2.n != 3)
        throw Erreur("Erreur : le produit vectoriel est défini uniquement pour des vecteurs de dimension 3.");

    long double t_res[3];
    t_res[0] = v1.t[1] * v2.t[2] - v1.t[2] * v2.t[1];
    t_res[1] = v1.t[2] * v2.t[0] - v1.t[0] * v2.t[2];
    t_res[2] = v1.t[0] * v2.t[1] - v1.t[1] * v2.t[0];

    return Vecteur(3, t_res);
}

Vecteur appliquer2(long double (*f2)(long double, long double), const Vecteur &v1, const Vecteur &v2)
{
    if (v1.n != v2.n)
        throw Erreur("Erreur : les vecteurs n'ont pas la même dimension pour la fonction");

    long double *t_res = new long double[v1.n];
    for (int i = 0; i < v1.n; i++)
    {
        t_res[i] = f2(v1.t[i], v2.t[i]);
    }
    Vecteur result(v1.n, t_res);
    delete[] t_res;
    return result;
}
