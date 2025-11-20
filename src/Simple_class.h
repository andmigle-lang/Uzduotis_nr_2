#pragma once
#include "Studentas_klase.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <numeric>
#include "is_number.h"
#include "mediana.h"
#include <cstdlib>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::fixed;
using std::setprecision;
using std::left;
using std::right;
using std::setw;

Studentas_klase Stud_iv_class(int k);
Studentas_klase Stud_iv_atsitiktinai_class(int k);

template <typename T> void skaitymas_class(T& Grupe) {
    string failo_vardas;
    ifstream F;
    while (true) {
        cout << "Iveskite failo varda: ";
        cin >> failo_vardas;
        F.open(failo_vardas);
        if (F) {
            break;
        }
        else {
            string pasirink;
            while (true) {
                cout << "Failo nepavyko atidaryti. Ar norite bandyti dar karta (rasykite 1), ar norite uzbaigti programa (rasykite 2)? ";
                cin >> pasirink;
                if (pasirink == "1") {
                    break;
                }
                else if (pasirink == "2") {
                    exit(0);
                }
                else {
                    cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
                }
            }
        }
    }
    string pavadinimai;
    getline(F, pavadinimai);
    while (F.peek() != EOF) {
        Studentas_klase Pirmas;
        F >> Pirmas;
        Grupe.push_back(Pirmas);
    }
    F.close();
    cout << "Duomenys nuskaityti is failo. Rastas studentu skaicius: " << Grupe.size() << endl;
}

template <typename T> void rasymas_class(T Grupe) {
    ofstream R("rezultatai.txt");
    if (!R) {
        cout << "Klaida: Nepavyko sukurti arba atidaryti failo 'rezultatai.txt'. Patikrinkite direktorija ir teises." << endl;
        return;
    }
    R << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << setw(18) << left << "Galutinis (Med.)" << endl;
    for (int i = 0; i < 76; i++) {
        R << "-";
    }

    R << endl;
    for (auto studentas : Grupe) {
        R << studentas;
    }

    R.close();
}
