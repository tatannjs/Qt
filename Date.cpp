#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

#include "Date.h"

Date::Date()
{
    cout << "Appel du constructeur de Date..." << endl;
    tps = time(NULL);
}

Date::Date(int j, int m, int a)
{
    cout << "Appel du constructeur de Date..." << endl;
    tps = time(NULL);
    struct tm *timeInfo = localtime(&tps);
    timeInfo->tm_mday = j;
    timeInfo->tm_mon = m - 1;
    timeInfo->tm_year = a - 1900;
    timeInfo->tm_hour = 0;
    timeInfo->tm_min = 0;
    timeInfo->tm_min = 0;
}

Date::Date(const Date &original) : tps(original.tps)
{
    cout << "Appel du constructeur de Date..." << endl;
}

Date::~Date()
{
    cout << "Appel du destructeur de Date..." << endl;
}

string Date::format(t_DateFormat format) {
    struct tm *timeinfo = localtime(&tps);
    ostringstream oss;
    if (format == Numerique) {
        oss << setfill('0') << setw(2) << timeinfo->tm_mday << "/"
            << setfill('0') << setw(2) << (timeinfo->tm_mon + 1) << "/"
            << (timeinfo->tm_year + 1900);
    }
    else if (format == DateCourt) {
        oss << jours[timeinfo->tm_wday] << " "
            << setfill('0') << setw(2) << timeinfo->tm_mday << " "
            << mois[timeinfo->tm_mon] << " "
            << (timeinfo->tm_year + 1900);
    }
    else if (format == DateLong) {
        oss << jours[timeinfo->tm_wday] << " "
            << setfill('0') << setw(2) << timeinfo->tm_mday << " "
            << mois[timeinfo->tm_mon] << " "
            << (timeinfo->tm_year + 1900) << ", "
            << setfill('0') << setw(2) << timeinfo->tm_hour << ":"
            << setfill('0') << setw(2) << timeinfo->tm_min;
    }
    return oss.str();
}
int Date::numJour() {
    return localtime(&tps)->tm_wday + 1; // tm_wday : 0=dimanche, ..., 6=samedi
}
int Date::nbJours(Date d) {
    return difftime(tps, d.tps) / (60 * 60 * 24);

}
const string Date::jours[7] = {"dimanche",
                               "lundi",
                               "mardi",
                               "mercredi",
                               "jeudi",
                               "vendredi",
                               "samedi"};

const string Date::mois[12] = {"janvier",
                               "fevrier",
                               "mars",
                               "avril",
                               "mai",
                               "juin",
                               "juillet",
                               "aout",
                               "septembre",
                               "octobre",
                               "novembre",
                               "décembre"};
