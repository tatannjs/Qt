class Ratio
{
private:
   int num, den; // numérateur et dénominateur

public:
   Ratio(int num = 0, int den = 1);
   void ecrire() const;
   void affecter(int num = 0, int den = 1);
   float valeur_reelle() const;
   void inverser();
   Ratio(const Ratio & r);
   ~Ratio();
   int numerateur() const;
   int denominateur() const;
   friend ostream & operator << (ostream & os, const Ratio & r);
   friend istream & operator >> (istream & is, Ratio & r);
   Ratio & operator = (const Ratio & r);
   // Ratio operator - () const;
   Ratio operator + (const Ratio & r) const;
   Ratio operator - (const Ratio & r) const;
   Ratio operator * (const Ratio & r) const;
   Ratio operator / (const Ratio & r) const;
   Ratio & operator += (const Ratio & r);
   Ratio & operator -= (const Ratio & r);
   Ratio & operator *= (const Ratio & r);
   Ratio & operator /= (const Ratio & r);
   bool operator == (const Ratio & r) const;
   bool operator != (const Ratio & r) const;
   Ratio & operator ++ ();
   Ratio operator ++ (int);
   Ratio & operator -- ();
   Ratio operator -- (int);
};
