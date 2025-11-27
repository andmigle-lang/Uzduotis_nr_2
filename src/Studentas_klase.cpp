#include "Studentas_klase.h"
#include <sstream>
#include <numeric>
#include <iostream>
#include "mediana.h"
#include "is_number.h"
#include <random>
#include <iomanip>

using std::endl;
using std::cout;
using std::string;
using std::accumulate;
using std::istream;
using std::stoi;
using std::cin;
using std::setw;
using std::setprecision;
using std::left;


Zmogus::Zmogus() 
    : var_(""), pav_("") {
}

//Zmogus::Zmogus(istream& is) {
//    skaityk_zmogu(is);
//}

Zmogus::~Zmogus() {
    std::cout << "Destruktorius sukurtas zmogui " << var_ << " " << pav_ << std::endl;
    var_.clear();
    pav_.clear();
}

Zmogus::Zmogus(const Zmogus& z) : var_(z.var_), pav_(z.pav_) {
    std::cout << "Kopijavimo konstruktorius sukurtas zmogui " << var_ << " " << pav_ << std::endl;
}

Zmogus& Zmogus::operator=(const Zmogus& z) {
    if (this == &z) return *this;
    var_ = z.var_;
    pav_ = z.pav_;
    std::cout << "Kopijavimo priskirties operatorius sukurtas zmogui " << z.var_ << " " << z.pav_ << std::endl;
    return *this;
}




Studentas_klase::Studentas_klase()
    : paz_(), egz_(0), gal_(0.0), med_(0.0) {
}

Studentas_klase::Studentas_klase(istream& is) : paz_(), egz_(0), gal_(0.0), med_(0.0) {
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

Studentas_klase::~Studentas_klase() {
    std::cout << "Destruktorius sukurtas studentui " << var_ << " " << pav_ << std::endl;
    /*var_.clear();
    pav_.clear();*/
    paz_.clear();
    egz_ = 0;
    gal_ = 0;
    med_ = 0;
}

Studentas_klase::Studentas_klase(const Studentas_klase& s)
    : Zmogus(s), paz_(s.paz_), egz_(s.egz_), gal_(s.gal_), med_(s.med_) {
    std::cout << "Kopijavimo kontruktorius sukurtas studentui " << s.var_ << " " << s.pav_ << std::endl;
}

Studentas_klase& Studentas_klase::operator=(const Studentas_klase& s) {
    if (this == &s) return *this;
    var_ = s.var_;
    pav_ = s.pav_;
    paz_ = s.paz_;
    egz_ = s.egz_;
    gal_ = s.gal_;
    med_ = s.med_;
    std::cout << "Kopijavimo priskirties operatorius sukurtas studentui " << s.var_ << " " << s.pav_ << std::endl;
    return *this;
}


std::istream& operator>>(std::istream& in, Studentas_klase& s) {
    if (&in == &std::cin) {
        std::cout << "Ar siam studentui ivesite rankiniu budu (rasyti 1), ar generuosite atsitiktinai (rasyti 2): ";
        string pasirinkimas_pr;
        int pasirinkimas;
        while (true) {
            std::cin >> pasirinkimas_pr;
            if (isNumber(pasirinkimas_pr)) {
                if (stoi(pasirinkimas_pr) == 1 || stoi(pasirinkimas_pr) == 2) {
                    pasirinkimas = stoi(pasirinkimas_pr);
                    break;
                }
                else {
                    cout << "Ivedete neteisinga duomeni (galima vesti tik 1 arba 2): ";
                }
            }
            else {
                cout << "Ivedete neteisinga duomeni (galima vesti tik 1 arba 2): ";
            }
        }

        if (pasirinkimas == 1) {
            cout << "Vardas: "; in >> s.var_;
            cout << "Pavarde: "; in >> s.pav_;
            cout << "Veskite studento pazymius (1-10). 0 ivedimas zymi pazymiu pabaiga: " << endl;
            s.paz_.clear();
            int n = 1;
            string laik_paz_pr;
            while (true) {
                cout << "Pazymys nr. " << n << ": ";
                in >> laik_paz_pr;
                if (isNumber(laik_paz_pr) && stoi(laik_paz_pr) <= 10 && stoi(laik_paz_pr) >= 1) {
                    s.paz_.push_back(stoi(laik_paz_pr));
                    n++;
                }
                else if (isNumber(laik_paz_pr) && stoi(laik_paz_pr) == 0) {
                    break;
                }
                else {
                    cout << "Ivedete neteisinga duomeni (galima ivesti tik sveikaji skaiciu nuo 1 iki 10 arba 0 uzbaigti). Veskite studento pazymius (1-10). 0 ivedimas zymi pazymiu pabaiga: " << endl;
                }
            }
            cout << "Iveskite egzamino pazymi: ";
            string egz_pr;
            while (true) {
                in >> egz_pr;
                if (isNumber(egz_pr) && stoi(egz_pr) >= 1 && stoi(egz_pr) <= 10) {
                    s.egz_ = stoi(egz_pr);
                    break;
                }
                else {
                    cout << "Ivedete neteisinga duomeni (galima ivesti tik sveikaji skaiciu nuo 1 iki 10). Iveskite egzamino pazymi: ";
                }
            }
            s.skaiciuok_galutinius();
        }
        else {
            cout << "Vardas: "; in >> s.var_;
            cout << "Pavarde: "; in >> s.pav_;
            s.paz_.clear();
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_int_distribution<int> dist(1, 21);
            int pazymiu_sk = dist(mt);
            cout << "Atsitiktinai generuojamu pazymiu skaicius (gali buti nuo 0 iki 20 pazymiu): " << pazymiu_sk << endl;
            cout << "Isvedami atsitiktinai generuojami pazymiai: " << endl;
            std::mt19937 mt1(rd());
            std::uniform_int_distribution<int> dist1(1, 10);
            for (int i = 0; i < pazymiu_sk; i++) {
                int laik_paz = dist1(mt1);
                cout << "Generuotas pazymys nr. " << i + 1 << ": " << laik_paz << endl;
                s.paz_.push_back(laik_paz);
            }
            s.egz_ = dist1(mt1);
            cout << "Isvedamas sugeneruotas egzamino pazymys: " << s.egz_ << endl;
            s.skaiciuok_galutinius();
        }
    }
    else {
        s.skaityk_studenta_class(in);
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const Studentas_klase& s) {
    if (&out == &std::cout) {
        out << s.var_ << ' ' << s.pav_;
        if (!s.paz_.empty()) {
            out << " Pazymiai: [";
            for (size_t i = 0; i < s.paz_.size(); i++) {
                if (i != 0) {
                    out << " ";
                }
                out << s.paz_[i];
            }
            out << "]";
        }
        else {
            out << "[]";
        }
        out << " egzaminas : " << s.egz_;
        out << " | galutinis (Vid.): " << s.gal_;
        out << " | galutinis (Med.): " << s.med_;

    }
    else {
        out << std::setw(20) << std::left << s.var_
            << std::setw(20) << std::left << s.pav_
            << std::setw(18) << std::left << std::fixed << std::setprecision(2) << s.gal_
            << std::setw(18) << std::left << std::fixed << std::setprecision(2) << s.med_
            << '\n';
    }
    return out;
}
