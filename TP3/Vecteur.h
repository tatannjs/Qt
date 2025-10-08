class Erreur : public exception
{
private:
   string cause;

public:
   Erreur(string c) throw() : cause(c) {}
   ~Erreur() throw() {}
   const char *what() const throw() { return cause.c_str(); }
};

class Vecteur
{
private:
   long double *t;
   int n;

public:
   Vecteur();
   Vecteur(int n, long double valInit = 0);
   Vecteur(int n, long double *t);
   ~Vecteur();
   Vecteur(const Vecteur &v);

   int size() const;
   Vecteur &operator=(const Vecteur &v);
   long double operator[](unsigned int i) const;
   long double &operator[](unsigned int i);
   friend ostream &operator<<(ostream &os, const Vecteur &v);
   //      friend istream & operator >> (istream & is, Vecteur & v);
   friend Vecteur operator-(const Vecteur &v);
   friend Vecteur operator*(const Vecteur &v, const long double x);
   friend Vecteur operator*(const long double x, const Vecteur &v);
   //      friend Vecteur operator + (const Vecteur & v1, const Vecteur & v2);
   //      friend Vecteur operator - (const Vecteur & v1, const Vecteur & v2);
   //      friend long double operator * (const Vecteur & v1, const Vecteur & v2);
   //      friend Vecteur operator ^ (const Vecteur & v1, const Vecteur & v2);
   long double norme();
   void normalise();
   //      Vecteur appliquer1(long double (*) (long double)) const;
   //      friend Vecteur appliquer2(long double (*) (long double, long double),
   //                                const Vecteur &, const Vecteur &) throw(Erreur);
};
