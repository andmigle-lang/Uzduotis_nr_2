#include "Studentas_klase.h"
#include <sstream>
#include <numeric>
#include <iostream>
#include "mediana.h"
#include "is_number.h"

using std::endl;
using std::cout;
using std::string;
using std::accumulate;
using std::istream;
using std::stoi;

Studentas_klase::Studentas_klase()
    : var_(""), pav_(""), egz_(0), gal_(0.0), med_(0.0) {
}

Studentas_klase::Studentas_klase(istream& is) : Studentas_klase() {
    skaityk_studenta_class(is);
}

istream& Studentas_klase::skaityk_studenta_class(istream& is) {
    is >> var_ >> pav_;

    paz_.clear();
    while (is.peek() != '\n' && is.peek() != EOF) {
        string ivestis;
        is >> ivestis;
        if (isNumber(ivestis)) {
            int v = stoi(ivestis);
            if (v >= 1 && v <= 10) paz_.push_back(v);
            else {
                cout << "Studento nr. pazymiuose buvo klaida (ne sveikasis skaicius nuo 1 iki 10): " << ivestis << ". Klaida pasalinta is skaiciavimu" << endl;
            }
        }
        else {
            cout << "Studento nr. pazymiuose buvo klaida (ne sveikasis skaicius nuo 1 iki 10): " << ivestis << ". Klaida pasalinta is skaiciavimu" << endl;
        }
    }

    if (!paz_.empty()) {
        egz_ = paz_.back();
        paz_.pop_back();
    }
    else {
        egz_ = 0;
    }

    skaiciuok_galutinius();

    //Jei dar yra newline
    if (is.peek() == '\n') is.get();

    return is;
}


void Studentas_klase::skaiciuok_galutinius() {
    if (paz_.empty()) {
        gal_ = egz_ * 0.6;
        med_ = egz_ * 0.6;
    }
    else {
        int sum = accumulate(paz_.begin(), paz_.end(), 0);
        double avg = double(sum) / double(paz_.size());
        gal_ = avg * 0.4 + egz_ * 0.6;

        double mediana = Rask_mediana(paz_);
        med_ = mediana * 0.4 + egz_ * 0.6;
    }
}

Studentas_klase::~Studentas_klase() {};