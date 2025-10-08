#include <iostream>
using namespace std;

#include "Ratio.h"

Ratio::Ratio(int num, int den)
{
    this->num = num;
    this->den = den;
    cout << "Ratio(" << this->num << "," << this->den << ")" << endl;
}

void Ratio::ecrire() const
{
    cout << num << "/" << den;
}

void Ratio::affecter(int num, int den)
{
    this->num = num;
    this->den = den;
}

float Ratio::valeur_reelle() const
{
    return num / (float)den;
}

void Ratio::inverser()
{
    int temp = this->den;
    this->den = this->num;
    this->num = temp;
}

Ratio::Ratio(const Ratio &r)
{
    this->num = r.num;
    this->den = r.den;
    cout << "Ratio(" << this->num << "," << this->den << ")" << endl;
}

Ratio::~Ratio()
{
    cout << "~Ratio(" << this->num << "," << this->den << ")" << endl;
}

int Ratio::numerateur() const
{
    return this->num;
}

int Ratio::denominateur() const
{
    return this->den;
}

Ratio &Ratio::operator=(const Ratio &r)
{
    if (this != &r)
    {
        num = r.numerateur();
        den = r.denominateur();
    }
    return *this;
}

Ratio Ratio::operator+(const Ratio &r) const
{
    int num, den;
    if (r.denominateur() == this->den)
    {
        num = this->num + r.numerateur();
        den = this->den;
    }
    else
    {
        int common_den = this->den * r.denominateur();
        int adjusted_num1 = this->num * r.denominateur();
        int adjusted_num2 = r.numerateur() * this->den;

        num = adjusted_num1 + adjusted_num2;
        den = common_den;
    }
    return Ratio(num, den);
}

Ratio Ratio::operator-(const Ratio &r) const
{
    int num, den;
    if (r.denominateur() == this->den)
    {
        num = this->num - r.numerateur();
        den = this->den;
    }
    else
    {
        int common_den = this->den * r.denominateur();
        int adjusted_num1 = this->num * r.denominateur();
        int adjusted_num2 = r.numerateur() * this->den;

        num = adjusted_num1 - adjusted_num2;
        den = common_den;
    }
    return Ratio(num, den);
}

Ratio Ratio::operator*(const Ratio &r) const
{
    int num, den;
    num = this->num * r.numerateur();
    den = this->den * r.denominateur();
    return Ratio(num, den);
}

Ratio Ratio::operator/(const Ratio &r) const
{
    int num = this->num * r.denominateur();
    int den = this->den * r.numerateur();

    return Ratio(num, den);
}

Ratio &Ratio::operator+=(const Ratio &r)
{
    int num, den;
    if (r.denominateur() == this->den)
    {
        num = this->num + r.numerateur();
        den = this->den;
    }
    else
    {
        int common_den = this->den * r.denominateur();
        int adjusted_num1 = this->num * r.denominateur();
        int adjusted_num2 = r.numerateur() * this->den;

        num = adjusted_num1 + adjusted_num2;
        den = common_den;
    }

    this->num = num;
    this->den = den;

    return *this;
}

Ratio &Ratio::operator-=(const Ratio &r)
{
    int num, den;
    if (r.denominateur() == this->den)
    {
        num = this->num - r.numerateur();
        den = this->den;
    }
    else
    {
        int common_den = this->den * r.denominateur();
        int adjusted_num1 = this->num * r.denominateur();
        int adjusted_num2 = r.numerateur() * this->den;

        num = adjusted_num1 - adjusted_num2;
        den = common_den;
    }

    this->num = num;
    this->den = den;

    return *this;
}

Ratio &Ratio::operator*=(const Ratio &r)
{
    int num, den;
    num = this->num * r.numerateur();
    den = this->den * r.denominateur();
    this->num = num;
    this->den = den;

    return *this;
}

Ratio &Ratio::operator/=(const Ratio &r)
{
    int num = this->num * r.denominateur();
    int den = this->den * r.numerateur();

    this->num = num;
    this->den = den;

    return *this;
}

bool Ratio::operator==(const Ratio &r) const
{
    bool numEqual = this->num*r.denominateur() == r.numerateur()*this->den;
    return numEqual;
}

bool Ratio::operator!=(const Ratio &r) const
{   
    bool numEqual = this->num*r.denominateur() == r.numerateur()*this->den;
    return !numEqual;
}

Ratio &Ratio::operator++()
{
    this->num = this->num + this->den;
    return *this;
}

Ratio Ratio::operator++(int)
{
    this->num += this->den;
    return Ratio(this->num, this->den);
}

Ratio &Ratio::operator--()
{
    this->num = this->num - this->den;
    return *this;
}

Ratio Ratio::operator--(int)
{
    this->num -= this->den;
    return Ratio(this->num, this->den);
}

ostream &operator<<(ostream &os, const Ratio &r)
{
    os << r.num << "/" << r.den;
    return os;
}

istream &operator>>(istream &is, Ratio &r)
{
    char c;
    is >> r.num;
    if ((c = is.get()) == '/')
    {
        is >> r.den;
    }
    else
    {
        is.putback(c);
        if (c != '\n')
            is.clear(ios::badbit);
    }
    return is;
}