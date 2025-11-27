#pragma once
#include <string>
#include <vector>
#include <istream>
#include <ostream>

using std::istream;
using std::ostream;
using std::vector;
using std::string;

class Zmogus {
protected:
    string var_;
    string pav_;
}

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

    //Nuskaitomas studentas (setteris?)
    istream& skaityk_studenta_class(istream& is);

    //Suskaiciuojami gal_ ir med_
    void skaiciuok_galutinius();

    ~Studentas_klase();
    //Kopijavimo konstruktorius
    Studentas_klase(const Studentas_klase& s);
    //Kopijavimo priskirties operatorius
    Studentas_klase& operator=(const Studentas_klase& s);


    friend std::istream& operator>>(std::istream& in, Studentas_klase& s);
    friend std::ostream& operator<<(std::ostream& out, const Studentas_klase& s);
};


