#pragma once
#include <vector>
#include <string>
#include <list>
#include "Studentas_klase.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <algorithm>
#include <numeric>
#include <iostream>
#include "is_number.h"

#include "palyginimas_class.h"

using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::right;
using std::fixed;
using std::setprecision;
using std::to_string;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::sort;
using std::getline;

template <typename T> void pagalbine_funkcija_class(vector <T>& Grupe, int pasirinkimas) {
    if (pasirinkimas == 1) {
        sort(Grupe.begin(), Grupe.end(), palyginimas_vardas_class);
    }
    else if (pasirinkimas == 2) {
        sort(Grupe.begin(), Grupe.end(), palyginimas_pavarde_class);
    }
    else if (pasirinkimas == 3) {
        sort(Grupe.begin(), Grupe.end(), palyginimas_galutinis_class);
    }
}

template <typename T> void pagalbine_funkcija_class(list <T>& Grupe, int pasirinkimas) {
    if (pasirinkimas == 1) {
        Grupe.sort(palyginimas_vardas_class);
    }
    else if (pasirinkimas == 2) {
        Grupe.sort(palyginimas_pavarde_class);
    }
    else if (pasirinkimas == 3) {
        Grupe.sort(palyginimas_galutinis_class);
    }
}

template <typename T> void pagalbine_funkc_2_strategija_class(vector <T>& Grupe) {
    sort(Grupe.begin(), Grupe.end(), palyginimas_2_strategija_class);
}

template <typename T> void pagalbine_funkc_2_strategija_class(list <T>& Grupe) {
    Grupe.sort(palyginimas_2_strategija_class);
}

template <typename T> void ar_naudoti_shrink_to_fit_class(vector <T>& Grupe) {
    Grupe.shrink_to_fit();
}

template <typename T> void ar_naudoti_shrink_to_fit_class(list <T>& Grupe) {
}

// Studentu rusiavimas tik vektoriams
template <typename T> void studentu_rusiavimas_class(T& Grupe,
    int k,
    double& diff_rusiavimas1,
    double& diff_irasu_dalijimo1,
    double& diff_irasymas_i_vargsiuku_faila1,
    double& diff_irasymas_i_kietiaku_faila1,
    int i,
    int rusiavimo_strategija, const string& spr) {

    int pasirinkimas = i;
    auto start_rusiavimas = high_resolution_clock::now();

    pagalbine_funkcija_class(Grupe, pasirinkimas);

    duration<double> diff_rusiavimas = high_resolution_clock::now() - start_rusiavimas;
    cout << k << " irasu rusiavimo didejimo tvarka laikas, su sort funkcija: " << diff_rusiavimas.count() << " s" << endl;
    diff_rusiavimas1 = diff_rusiavimas.count();

    T vargsiukai;
    T kietiakai;

    // 1 strategija
    if (rusiavimo_strategija == 1) {
        vargsiukai.clear();
        kietiakai.clear();
        auto start_irasu_dalijimo = high_resolution_clock::now();
        for (const auto& studentas : Grupe) {
            if (studentas.galutinis() < 5.0) { 
                vargsiukai.push_back(studentas); 
            }
            else {
                kietiakai.push_back(studentas); 
            }
        }
        duration<double> diff_irasu_dalijimo = high_resolution_clock::now() - start_irasu_dalijimo;
        cout << k << " irasu dalijimo i dvi grupes laikas 1 strategija: " << diff_irasu_dalijimo.count() << " s" << endl;
        diff_irasu_dalijimo1 = diff_irasu_dalijimo.count();

        auto start_irasymas_i_vargsiuku_faila = high_resolution_clock::now();
        stringstream vargsiukai_buf;
        if (spr == "vidurki") {
            vargsiukai_buf << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << endl;
            for (int i = 0; i < 58; i++) vargsiukai_buf << "-";
        }
        else if (spr == "mediana") {
            vargsiukai_buf << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Med.)" << endl;
            for (int i = 0; i < 58; i++) vargsiukai_buf << "-";
        }
        if (spr == "abu") {
            vargsiukai_buf << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << setw(18) << left << "Galutinis (Med.)" << endl;
            for (int i = 0; i < 76; i++) vargsiukai_buf << "-";
        }

        
        vargsiukai_buf << endl;
        for (const auto& s : vargsiukai) {
            if (spr == "vidurki") {
                vargsiukai_buf << setw(20) << left << s.vardas()
                    << setw(20) << left << s.pavarde()
                    << setw(18) << left << fixed << setprecision(2) << s.galutinis() << endl;
            }
            else if (spr == "mediana") {
                vargsiukai_buf << setw(20) << left << s.vardas()
                    << setw(20) << left << s.pavarde()
                    << setw(18) << left << fixed << setprecision(2) << s.mediana_galutinis() << endl;
            }
            else if (spr == "abu") {
                vargsiukai_buf << setw(20) << left << s.vardas()
                    << setw(20) << left << s.pavarde()
                    << setw(18) << left << fixed << setprecision(2) << s.galutinis() << setw(18) << left << fixed << setprecision(2) << s.mediana_galutinis() << endl;
            }
        }
        string failo_vardas1 = "vargsiukai_class" + to_string(k) + ".txt";
        ofstream out_vargsiukai(failo_vardas1);
        out_vargsiukai << vargsiukai_buf.str();
        out_vargsiukai.close();
        duration<double> diff_irasymas_i_vargsiuku_faila = high_resolution_clock::now() - start_irasymas_i_vargsiuku_faila;
        cout << k << " irasu irasymo i vargsiuku faila laikas: " << diff_irasymas_i_vargsiuku_faila.count() << " s" << endl;
        diff_irasymas_i_vargsiuku_faila1 = diff_irasymas_i_vargsiuku_faila.count();

        auto start_irasymas_i_kietiaku_faila = high_resolution_clock::now();
        stringstream kietiakai_buf;
        if (spr == "vidurki") {
            kietiakai_buf << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << endl;
            for (int i = 0; i < 58; i++) kietiakai_buf << "-";
        }
        else if (spr == "mediana") {
            kietiakai_buf << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Med.)" << endl;
            for (int i = 0; i < 58; i++) kietiakai_buf << "-";
        }
        if (spr == "abu") {
            kietiakai_buf << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << setw(18) << left << "Galutinis (Med.)" << endl;
            for (int i = 0; i < 76; i++) kietiakai_buf << "-";
        }


        kietiakai_buf << endl;
        for (const auto& s : kietiakai) {
            if (spr == "vidurki") {
                kietiakai_buf << setw(20) << left << s.vardas()
                    << setw(20) << left << s.pavarde()
                    << setw(18) << left << fixed << setprecision(2) << s.galutinis() << endl;
            }
            else if (spr == "mediana") {
                kietiakai_buf << setw(20) << left << s.vardas()
                    << setw(20) << left << s.pavarde()
                    << setw(18) << left << fixed << setprecision(2) << s.mediana_galutinis() << endl;
            }
            else if (spr == "abu") {
                kietiakai_buf << setw(20) << left << s.vardas()
                    << setw(20) << left << s.pavarde()
                    << setw(18) << left << fixed << setprecision(2) << s.galutinis() << setw(18) << left << fixed << setprecision(2) << s.mediana_galutinis() << endl;
            }
        }
        string failo_vardas2 = "kietiakai_class" + to_string(k) + ".txt";
        ofstream out_kietiakai(failo_vardas2);
        out_kietiakai << kietiakai_buf.str();
        out_kietiakai.close();
        duration<double> diff_irasymas_i_kietiaku_faila = high_resolution_clock::now() - start_irasymas_i_kietiaku_faila;
        cout << k << " irasu irasymo i kietiaku faila laikas: " << diff_irasymas_i_kietiaku_faila.count() << " s" << endl;
        diff_irasymas_i_kietiaku_faila1 = diff_irasymas_i_kietiaku_faila.count();

        cout << "Surusiuota studentu:" << endl;
        cout << "Vargsai (< 5.0): " << vargsiukai.size() << " studentai" << endl;
        cout << "Kietiakai (>= 5.0): " << kietiakai.size() << " studentai" << endl;
    }

    // 2 strategija
    else if (rusiavimo_strategija == 2) {
        vargsiukai.clear();
        kietiakai.clear();
        auto start_irasu_dalijimo = high_resolution_clock::now();
        pagalbine_funkc_2_strategija_class(Grupe);
        /*sort(Grupe.begin(), Grupe.end(), palyginimas_2_strategija_class);*/
        while (!Grupe.empty() && Grupe.back().galutinis() < 5.0) {
            vargsiukai.push_back(Grupe.back());
            Grupe.pop_back();
        }
        /*Grupe.shrink_to_fit();*/
        ar_naudoti_shrink_to_fit_class(Grupe);
        /*if (pasirinkimas == 1) {
            sort(Grupe.begin(), Grupe.end(), palyginimas_vardas_class);
            sort(vargsiukai.begin(), vargsiukai.end(), palyginimas_vardas_class);
        }
        else if (pasirinkimas == 2) {
            sort(Grupe.begin(), Grupe.end(), palyginimas_pavarde_class);
            sort(vargsiukai.begin(), vargsiukai.end(), palyginimas_pavarde_class);
        }
        else {
            sort(Grupe.begin(), Grupe.end(), palyginimas_galutinis_class);
            sort(vargsiukai.begin(), vargsiukai.end(), palyginimas_galutinis_class);
        }*/
        pagalbine_funkcija_class(Grupe, pasirinkimas);
        pagalbine_funkcija_class(vargsiukai, pasirinkimas);

        duration<double> diff_irasu_dalijimo = high_resolution_clock::now() - start_irasu_dalijimo;
        cout << k << " irasu dalijimo i dvi grupes laikas 2 strategija: " << diff_irasu_dalijimo.count() << " s" << endl;
        diff_irasu_dalijimo1 = diff_irasu_dalijimo.count();


        auto start_irasymas_i_vargsiuku_faila = high_resolution_clock::now();
        stringstream vargsiukai_buf;
        if (spr == "vidurki") {
            vargsiukai_buf << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << endl;
            for (int i = 0; i < 58; i++) vargsiukai_buf << "-";
        }
        else if (spr == "mediana") {
            vargsiukai_buf << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Med.)" << endl;
            for (int i = 0; i < 58; i++) vargsiukai_buf << "-";
        }
        if (spr == "abu") {
            vargsiukai_buf << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << setw(18) << left << "Galutinis (Med.)" << endl;
            for (int i = 0; i < 76; i++) vargsiukai_buf << "-";
        }

        vargsiukai_buf << endl;
        for (const auto& s : vargsiukai) {
            if (spr == "vidurki") {
                vargsiukai_buf << setw(20) << left << s.vardas()
                    << setw(20) << left << s.pavarde()
                    << setw(18) << left << fixed << setprecision(2) << s.galutinis() << endl;
            }
            else if (spr == "mediana") {
                vargsiukai_buf << setw(20) << left << s.vardas()
                    << setw(20) << left << s.pavarde()
                    << setw(18) << left << fixed << setprecision(2) << s.mediana_galutinis() << endl;
            }
            else if (spr == "abu") {
                vargsiukai_buf << setw(20) << left << s.vardas()
                    << setw(20) << left << s.pavarde()
                    << setw(18) << left << fixed << setprecision(2) << s.galutinis() << setw(18) << left << fixed << setprecision(2) << s.mediana_galutinis() << endl;
            }
        }
        string failo_vardas1 = "vargsiukai_class" + to_string(k) + ".txt";
        ofstream out_vargsiukai(failo_vardas1);
        out_vargsiukai << vargsiukai_buf.str();
        out_vargsiukai.close();
        duration<double> diff_irasymas_i_vargsiuku_faila = high_resolution_clock::now() - start_irasymas_i_vargsiuku_faila;
        cout << k << " irasu irasymo i vargsiuku faila laikas: " << diff_irasymas_i_vargsiuku_faila.count() << " s" << endl;
        diff_irasymas_i_vargsiuku_faila1 = diff_irasymas_i_vargsiuku_faila.count();

        auto start_irasymas_i_kietiaku_faila = high_resolution_clock::now();
        stringstream kietiakai_buf;
        if (spr == "vidurki") {
            kietiakai_buf << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << endl;
            for (int i = 0; i < 58; i++) kietiakai_buf << "-";
        }
        else if (spr == "mediana") {
            kietiakai_buf << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Med.)" << endl;
            for (int i = 0; i < 58; i++) kietiakai_buf << "-";
        }
        if (spr == "abu") {
            kietiakai_buf << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << setw(18) << left << "Galutinis (Med.)" << endl;
            for (int i = 0; i < 76; i++) kietiakai_buf << "-";
        }


        kietiakai_buf << endl;
        for (const auto& s : Grupe) {
            if (spr == "vidurki") {
                kietiakai_buf << setw(20) << left << s.vardas()
                    << setw(20) << left << s.pavarde()
                    << setw(18) << left << fixed << setprecision(2) << s.galutinis() << endl;
            }
            else if (spr == "mediana") {
                kietiakai_buf << setw(20) << left << s.vardas()
                    << setw(20) << left << s.pavarde()
                    << setw(18) << left << fixed << setprecision(2) << s.mediana_galutinis() << endl;
            }
            else if (spr == "abu") {
                kietiakai_buf << setw(20) << left << s.vardas()
                    << setw(20) << left << s.pavarde()
                    << setw(18) << left << fixed << setprecision(2) << s.galutinis() << setw(18) << left << fixed << setprecision(2) << s.mediana_galutinis() << endl;
            }
        }
        string failo_vardas2 = "kietiakai_class" + to_string(k) + ".txt";
        ofstream out_kietiakai(failo_vardas2);
        out_kietiakai << kietiakai_buf.str();
        out_kietiakai.close();
        duration<double> diff_irasymas_i_kietiaku_faila = high_resolution_clock::now() - start_irasymas_i_kietiaku_faila;
        cout << k << " irasu irasymo i kietiaku faila laikas: " << diff_irasymas_i_kietiaku_faila.count() << " s" << endl;
        diff_irasymas_i_kietiaku_faila1 = diff_irasymas_i_kietiaku_faila.count();

        cout << "Surusiuota studentu:" << endl;
        cout << "Vargsai (< 5.0): " << vargsiukai.size() << " studentai" << endl;
        cout << "Kietiakai (>= 5.0): " << Grupe.size() << " studentai" << endl;
    }

    // 3 strategija
    else if (rusiavimo_strategija == 3) {
        vargsiukai.clear();
        kietiakai.clear();
        auto start_irasu_dalijimo = high_resolution_clock::now();
        auto vidurys = std::stable_partition(Grupe.begin(), Grupe.end(), partition_palyginimas_class);
        vargsiukai.resize(distance(vidurys, Grupe.end()));
        copy(vidurys, Grupe.end(), vargsiukai.begin());
        Grupe.erase(vidurys, Grupe.end());
        duration<double> diff_irasu_dalijimo = high_resolution_clock::now() - start_irasu_dalijimo;
        cout << k << " irasu dalijimo i dvi grupes laikas 3 strategija: " << diff_irasu_dalijimo.count() << " s" << endl;
        diff_irasu_dalijimo1 = diff_irasu_dalijimo.count();

        ar_naudoti_shrink_to_fit_class(Grupe);

        auto start_irasymas_i_vargsiuku_faila = high_resolution_clock::now();
        stringstream vargsiukai_buf;
        if (spr == "vidurki") {
            vargsiukai_buf << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << endl;
            for (int i = 0; i < 58; i++) vargsiukai_buf << "-";
        }
        else if (spr == "mediana") {
            vargsiukai_buf << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Med.)" << endl;
            for (int i = 0; i < 58; i++) vargsiukai_buf << "-";
        }
        if (spr == "abu") {
            vargsiukai_buf << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << setw(18) << left << "Galutinis (Med.)" << endl;
            for (int i = 0; i < 76; i++) vargsiukai_buf << "-";
        }

        vargsiukai_buf << endl;
        for (const auto& s : vargsiukai) {
            if (spr == "vidurki") {
                vargsiukai_buf << setw(20) << left << s.vardas()
                    << setw(20) << left << s.pavarde()
                    << setw(18) << left << fixed << setprecision(2) << s.galutinis() << endl;
            }
            else if (spr == "mediana") {
                vargsiukai_buf << setw(20) << left << s.vardas()
                    << setw(20) << left << s.pavarde()
                    << setw(18) << left << fixed << setprecision(2) << s.mediana_galutinis() << endl;
            }
            else if (spr == "abu") {
                vargsiukai_buf << setw(20) << left << s.vardas()
                    << setw(20) << left << s.pavarde()
                    << setw(18) << left << fixed << setprecision(2) << s.galutinis() << setw(18) << left << fixed << setprecision(2) << s.mediana_galutinis() << endl;
            }
        }
        string failo_vardas1 = "vargsiukai_class" + to_string(k) + ".txt";
        ofstream out_vargsiukai(failo_vardas1);
        out_vargsiukai << vargsiukai_buf.str();
        out_vargsiukai.close();
        duration<double> diff_irasymas_i_vargsiuku_faila = high_resolution_clock::now() - start_irasymas_i_vargsiuku_faila;
        cout << k << " irasu irasymo i vargsiuku faila laikas: " << diff_irasymas_i_vargsiuku_faila.count() << " s" << endl;
        diff_irasymas_i_vargsiuku_faila1 = diff_irasymas_i_vargsiuku_faila.count();

        auto start_irasymas_i_kietiaku_faila = high_resolution_clock::now();
        stringstream kietiakai_buf;
        if (spr == "vidurki") {
            kietiakai_buf << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << endl;
            for (int i = 0; i < 58; i++) kietiakai_buf << "-";
        }
        else if (spr == "mediana") {
            kietiakai_buf << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Med.)" << endl;
            for (int i = 0; i < 58; i++) kietiakai_buf << "-";
        }
        if (spr == "abu") {
            kietiakai_buf << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis (Vid.)" << setw(18) << left << "Galutinis (Med.)" << endl;
            for (int i = 0; i < 76; i++) kietiakai_buf << "-";
        }


        kietiakai_buf << endl;
        for (const auto& s : Grupe) {
            if (spr == "vidurki") {
                kietiakai_buf << setw(20) << left << s.vardas()
                    << setw(20) << left << s.pavarde()
                    << setw(18) << left << fixed << setprecision(2) << s.galutinis() << endl;
            }
            else if (spr == "mediana") {
                kietiakai_buf << setw(20) << left << s.vardas()
                    << setw(20) << left << s.pavarde()
                    << setw(18) << left << fixed << setprecision(2) << s.mediana_galutinis() << endl;
            }
            else if (spr == "abu") {
                kietiakai_buf << setw(20) << left << s.vardas()
                    << setw(20) << left << s.pavarde()
                    << setw(18) << left << fixed << setprecision(2) << s.galutinis() << setw(18) << left << fixed << setprecision(2) << s.mediana_galutinis() << endl;
            }
        }
        string failo_vardas2 = "kietiakai_class" + to_string(k) + ".txt";
        ofstream out_kietiakai(failo_vardas2);
        out_kietiakai << kietiakai_buf.str();
        out_kietiakai.close();
        duration<double> diff_irasymas_i_kietiaku_faila = high_resolution_clock::now() - start_irasymas_i_kietiaku_faila;
        cout << k << " irasu irasymo i kietiaku faila laikas: " << diff_irasymas_i_kietiaku_faila.count() << " s" << endl;
        diff_irasymas_i_kietiaku_faila1 = diff_irasymas_i_kietiaku_faila.count();

        cout << "Surusiuota studentu:" << endl;
        cout << "Vargsai (< 5.0): " << vargsiukai.size() << " studentai" << endl;
        cout << "Kietiakai (>= 5.0): " << Grupe.size() << " studentai" << endl;
    }

}

// Skaitomi generuoti failai
template <typename T> void skaitymas_is_generuoto_failo_class(T& Grupe,
    const string& failo_vardas,
    double& diff_skaitymas1) {

    auto start_skaitymas = high_resolution_clock::now();
    ifstream F(failo_vardas);
    if (!F) {
        cout << "Klaida: Nepavyko atidaryti failo " << failo_vardas << endl;
        exit(0);
    }

    string header;
    getline(F, header);

    while (F.peek() != EOF) {
        Studentas_klase temp;
        temp.skaityk_studenta_class(F);
        if (!F) {
            break;
        }
        Grupe.push_back(temp);
    }
    F.close();
    duration<double> diff_skaitymas = high_resolution_clock::now() - start_skaitymas;
    cout << "\nFailo is " << Grupe.size() << " irasu nuskaitymo laikas: " << diff_skaitymas.count() << " s" << endl;
    diff_skaitymas1 = diff_skaitymas.count();
    cout << "Duomenys nuskaityti is failo. Rastas studentu skaicius: " << Grupe.size() << endl;
}
