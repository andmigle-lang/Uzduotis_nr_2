#pragma once
#include <string>
#include <vector>
#include <istream>

using std::istream;
using std::vector;
using std::string;

class Studentas_klase {
private:
    string var_;
    string pav_;
    vector<int> paz_;
    int egz_;
    double gal_;
    double med_;
public:
    Studentas_klase();
    Studentas_klase(istream& is);

    //Getteriai
    inline string vardas() const { return var_; }
    inline string pavarde() const { return pav_; }
    inline double galutinis() const { return gal_; }
    inline double mediana_galutinis() const { return med_; }
    inline const vector<int>& pazymiai() const { return paz_; }
    inline int egzaminas() const { return egz_; }

    //Nuskaitomas studentas (setteris)
    istream& skaityk_studenta_class(istream& is);

    //Suskaiciuojami gal_ ir med_
    void skaiciuok_galutinius();

    ~Studentas_klase();
};