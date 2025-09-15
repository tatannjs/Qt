typedef enum {Numerique, DateCourt, DateLong} t_DateFormat;

class Date {
   private:
      static const string jours[7];
      static const string mois[12];
      
      time_t  tps;
   
   public:
      Date();
      Date(int j, int m, int a);
      Date(const Date & original);
      ~Date();
      string format(t_DateFormat format);
      int numJour();
      int nbJours(Date d);
};
