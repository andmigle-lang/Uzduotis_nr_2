// Uzduotis_nr_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "palyginimas.h"
#include "Generuoti_failai.h"
#include "is_number.h"
#include "mediana.h"
#include "Simple.h"
#include "Studentas.h"
#include <chrono>
#include "Studentas_klase.h"
#include "palyginimas_class.h"
#include "Generuoti_failai_class.h"
#include "Simple_class.h"

#define CATCH_CONFIG_RUNNER
#include "catch2/catch.hpp"

using std::cin;
using std::cout;
using std::to_string;
using std::endl;
using std::chrono::high_resolution_clock;
using std::chrono::duration;

int main(int argc, char* argv[]) {
    string versija_pr;
    int versija;
    cout << "Ar norite dirbti su programa v1.0 versija (rasyti 1), ar su v1.1 versija (rasyti 2), ar su v1.2 versija (rasyti 3), ar su v1.5 versija (rasyti 4), ar su versija v2.0 (rasyti 5): ";
    while (true) {
        cin >> versija_pr;
        if (isNumber(versija_pr)) {
            if (stoi(versija_pr) == 1 || stoi(versija_pr) == 2 || stoi(versija_pr) == 3||stoi(versija_pr)==4 || stoi(versija_pr) == 5) {
                versija = stoi(versija_pr);
                break;
            }
            else {
                cout << "Ivedete neteisinga duomeni (galima vesti tik 1, 2, 3, 4 arba 5): ";
            }
        }
        else {
            cout << "Ivedete neteisinga duomeni (galima vesti tik 1, 2, 3, 4 arba 5): ";
        }
    }
    if (versija == 5) {
        cout << "Testavimas su Catch2 testais"<<endl;
        return Catch::Session().run(argc, argv);
    }

    if (versija == 4) {
        cout << "Tikrinama v1.4: "<<endl;
        //Tikrinama, ar galima sukurti objekta z1. Atkomentuoti ir bandyti sukompiliuoti, kad parodytume, kad neveikia
        //Zmogus z1;
    }
    if (versija == 3) {

        string choice_good_pr;
        int choice_good;
        cout << "Ar tikrinti operator>> ir operator<< veikima (rasyti 1), ar rule of 3 (rasyti 2)? ";
        while (true) {
            cin >> choice_good_pr;
            if (isNumber(choice_good_pr)) {
                if (stoi(choice_good_pr) == 1 || stoi(choice_good_pr) == 2) {
                    choice_good = stoi(choice_good_pr);
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

        if (choice_good == 2) {
            Studentas_klase s1;
            cout << "Iveskite pirmo studento duomenis (s1):" << endl;
            cin >> s1;

            cout << "\nOriginalus studentas (s1): " << s1 << endl;

            //Kopijavimo konstruktorius
            Studentas_klase s2(s1);
            cout << "\nKopijuotas studentas (s2): " << s2 << endl;

            //Kopijavimo priskirties operatorius
            Studentas_klase s3;
            cout << "\nIveskite dar viena studenta (s3):" << endl;
            cin >> s3;

            cout << "\nPries priskyrima studentas (s3): " << s3 << endl;
            s3 = s1;
            cout << "Po priskyrimo studentas (s3): " << s3 << endl;

            s1.~Studentas_klase();
            cout << "Isvedamas studentas (s1), kad butu patikrinta, ar veikia desktruktorius: " << endl;
            cout << s1 << endl;
        }

        else if (choice_good == 1) {
            string pasirink_pr;
            int pasirink;
            cout << "Ar norite dirbti su vektoriais (rasyti 1), ar list'ais (raysti 2): ";
            while (true) {
                cin >> pasirink_pr;
                if (isNumber(pasirink_pr)) {
                    if (stoi(pasirink_pr) == 1 || stoi(pasirink_pr) == 2) {
                        pasirink = stoi(pasirink_pr);
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
            vector <Studentas_klase> Grupe_vector;
            list <Studentas_klase> Grupe_list;
            string pasirinkimas_pries_pr;
            int pasirinkimas_pries;
            cout << "Pasirinkite, ar norite, kad duomenys butu skaitomi is studentai.txt failo (rasyti 1), ar ne (rasyti 2): ";
            while (true) {
                cin >> pasirinkimas_pries_pr;
                if (isNumber(pasirinkimas_pries_pr)) {
                    if (stoi(pasirinkimas_pries_pr) == 1 || stoi(pasirinkimas_pries_pr) == 2) {
                        pasirinkimas_pries = stoi(pasirinkimas_pries_pr);
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
            if (pasirinkimas_pries == 1) {
                if (pasirink == 1) {
                    skaitymas_class(Grupe_vector);
                }
                else {
                    skaitymas_class(Grupe_list);
                }
            }
            else {
                cout << "Kiek studentu grupeje? ";
                string m_pr;
                int m;
                while (true) {
                    cin >> m_pr;
                    if (isNumber(m_pr)) {
                        if (stoi(m_pr) >= 0) {
                            m = stoi(m_pr);
                            break;
                        }
                        else {
                            cout << "Ivedete neteisinga duomeni (galima ivesti tik sveikaji skaiciu, nemazesni uz 0). Kiek studentu grupeje? ";
                        }
                    }
                    else {
                        cout << "Ivedete neteisinga duomeni (galima ivesti tik sveikaji skaiciu, nemazesni uz 0). Kiek studentu grupeje? ";
                    }
                }
                if (pasirink == 1) Grupe_vector.reserve(m);
                for (auto z = 0; z < m; z++) {
                    if (pasirink == 1) {
                        Grupe_vector.push_back(Stud_iv_class(z + 1));
                    }
                    else {
                        Grupe_list.push_back(Stud_iv_class(z + 1));
                    }
                }
            }
            if (pasirink == 1) {
                sort(Grupe_vector.begin(), Grupe_vector.end(), palyginimas_vardas_class);
            }
            else {
                Grupe_list.sort(palyginimas_vardas_class);
            }

            string out_choice_pr;
            int out_choice;
            cout << "Ar norite isvesti i ekrana (rasyti 1) ar i faila (rasyti 2)? ";
            while (true) {
                cin >> out_choice_pr;
                if (isNumber(out_choice_pr)) {
                    out_choice = stoi(out_choice_pr);
                    if (out_choice == 1 || out_choice == 2) {
                        break;
                    }
                    else {
                        cout << "Neteisinga ivestis. Iveskite 1 arba 2: ";
                    }
                }
                else {
                    cout << "Neteisinga ivestis. Iveskite 1 arba 2: ";
                }
            }

            if (out_choice == 1) {
                if (pasirink == 1) {
                    for (auto& s : Grupe_vector) cout << s << endl;
                }
                else {
                    for (auto& s : Grupe_list) cout << s << endl;
                }
            }
            else {
                if (pasirink == 1) rasymas_class(Grupe_vector);
                else rasymas_class(Grupe_list);
                cout << "Rezultatai issaugoti faile 'rezultatai.txt'" << endl;
            }
        }
    }

    else if (versija == 2) {
        vector<int> dydziai = { 100000, 1000000 };
        vector<double> vid_skaitymas(dydziai.size(), 0.0);
        vector<double> vid_rusiavimas(dydziai.size(), 0.0);
        vector<double> vid_dalijimas(dydziai.size(), 0.0);
        vector<double> vid_vargsiukai(dydziai.size(), 0.0);
        vector<double> vid_kietiakai(dydziai.size(), 0.0);
        cout << "\nPasirinkite, pagal kuri parametra rusiuosite " << endl;
        cout << "(1 - pagal varda, 2 - pagal pavarde, 3 - pagal galutini pazymi): ";
        string pasirinkimas_pr;
        int pasirinkimas;
        while (true) {
            cin >> pasirinkimas_pr;
            if (isNumber(pasirinkimas_pr)) {
                pasirinkimas = stoi(pasirinkimas_pr);
                if (pasirinkimas >= 1 && pasirinkimas <= 3) {
                    break;
                }
                else {
                    cout << "Ivedete neteisinga duomeni (galima vesti tik skaicius 1, 2 arba 3): ";
                }
            }
            else {
                cout << "Ivedete neteisinga duomeni (galima vesti tik skaicius 1, 2 arba 3): ";
            }
        }

        string spr;
        string spr_pr;
        cout << "Ar isvesti galutini vidurki/mediana/abu (irasykite zodi mazosiomis raidemis)? ";
        while (true) {
            cin >> spr_pr;
            if (spr_pr == "vidurki" || spr_pr == "mediana" || spr_pr == "abu") {
                spr = spr_pr;
                break;
            }
            else {
                cout << "Ivedete neteisinga duomeni. Iveskite tik viena is siu zodziu: vidurki/mediana/abu: ";
            }
        }

        const int runs = 3;
        int a = dydziai.size();
        //struct
        cout << "\nTikrinamas struct veikimas su vektoriais: " << endl;

        for (int j = 0; j < runs; j++) {
            cout << "\n" << j + 1 << " iteracija:" << endl;

            for (int i = 0; i < a; i++) {
                int size = dydziai[i];
                string input_file = "Generuoti_studentai" + to_string(size) + ".txt";
                vector<Studentas> Grupe1;
                double diff_skaitymas1 = 0.0;
                double diff_rusiavimas1 = 0.0;
                double diff_irasu_dalijimo1 = 0.0;
                double diff_irasymas_i_vargsiuku_faila1 = 0.0;
                double diff_irasymas_i_kietiaku_faila1 = 0.0;

                skaitymas_is_generuoto_failo(Grupe1, input_file, diff_skaitymas1);
                studentu_rusiavimas(Grupe1, size,
                    diff_rusiavimas1,
                    diff_irasu_dalijimo1,
                    diff_irasymas_i_vargsiuku_faila1,
                    diff_irasymas_i_kietiaku_faila1, pasirinkimas, 3, spr);

                vid_skaitymas[i] += diff_skaitymas1;
                vid_rusiavimas[i] += diff_rusiavimas1;
                vid_dalijimas[i] += diff_irasu_dalijimo1;
                vid_vargsiukai[i] += diff_irasymas_i_vargsiuku_faila1;
                vid_kietiakai[i] += diff_irasymas_i_kietiaku_faila1;
                cout << size << " irasu testo laikas: " << diff_skaitymas1 + diff_rusiavimas1 + diff_irasu_dalijimo1 + diff_irasymas_i_vargsiuku_faila1 + diff_irasymas_i_kietiaku_faila1 << " s" << endl;
            }
        }
        cout << "\nVIDURKIAI IS " << runs << " ITERACIJU: " << endl;
        for (int i = 0; i < a; ++i) {
            cout << "\nFailo dydis: " << dydziai[i] << endl;
            cout << "Skaitymo vidurkis: " << (vid_skaitymas[i] / runs) << " s" << endl;
            cout << "Rusiavimo vidurkis: " << (vid_rusiavimas[i] / runs) << " s" << endl;
            cout << "Dalijimo vidurkis: " << (vid_dalijimas[i] / runs) << " s" << endl;
            cout << "Vargsiuku irasymo vidurkis: " << (vid_vargsiukai[i] / runs) << " s" << endl;
            cout << "Kietiaku irasymo vidurkis: " << (vid_kietiakai[i] / runs) << " s" << endl;
        }

        //Nunulinami laiko sumavimo vektoriai
        for (int i = 0; i < dydziai.size(); i++) {
            vid_skaitymas[i] = 0.0;
            vid_rusiavimas[i] = 0.0;
            vid_dalijimas[i] = 0.0;
            vid_vargsiukai[i] = 0.0;
            vid_kietiakai[i] = 0.0;
        }

        //class
        cout << "\nTikrinamas class veikimas su vektoriais: " << endl;
        for (int j = 0; j < runs; j++) {
            cout << "\n" << j + 1 << " iteracija:" << endl;

            for (int i = 0; i < a; i++) {
                int size = dydziai[i];
                string input_file = "Generuoti_studentai" + to_string(size) + ".txt";
                vector<Studentas_klase> Grupe1;
                double diff_skaitymas1 = 0.0;
                double diff_rusiavimas1 = 0.0;
                double diff_irasu_dalijimo1 = 0.0;
                double diff_irasymas_i_vargsiuku_faila1 = 0.0;
                double diff_irasymas_i_kietiaku_faila1 = 0.0;

                skaitymas_is_generuoto_failo_class(Grupe1, input_file, diff_skaitymas1);
                studentu_rusiavimas_class(Grupe1, size, diff_rusiavimas1, diff_irasu_dalijimo1,
                    diff_irasymas_i_vargsiuku_faila1, diff_irasymas_i_kietiaku_faila1,
                    pasirinkimas, 3, spr);

                vid_skaitymas[i] += diff_skaitymas1;
                vid_rusiavimas[i] += diff_rusiavimas1;
                vid_dalijimas[i] += diff_irasu_dalijimo1;
                vid_vargsiukai[i] += diff_irasymas_i_vargsiuku_faila1;
                vid_kietiakai[i] += diff_irasymas_i_kietiaku_faila1;
                cout << size << " irasu testo laikas: " << diff_skaitymas1 + diff_rusiavimas1 + diff_irasu_dalijimo1 + diff_irasymas_i_vargsiuku_faila1 + diff_irasymas_i_kietiaku_faila1 << " s" << endl;
            }
        }
        cout << "\nVIDURKIAI IS " << runs << " ITERACIJU: " << endl;
        for (int i = 0; i < a; ++i) {
            cout << "\nFailo dydis: " << dydziai[i] << endl;
            cout << "Skaitymo vidurkis: " << (vid_skaitymas[i] / runs) << " s" << endl;
            cout << "Rusiavimo vidurkis: " << (vid_rusiavimas[i] / runs) << " s" << endl;
            cout << "Dalijimo vidurkis: " << (vid_dalijimas[i] / runs) << " s" << endl;
            cout << "Vargsiuku irasymo vidurkis: " << (vid_vargsiukai[i] / runs) << " s" << endl;
            cout << "Kietiaku irasymo vidurkis: " << (vid_kietiakai[i] / runs) << " s" << endl;
        }
    }


    else {
        string d_pr;
        int d;
        cout << "Ar norite dirbti su studentai.txt failais/rasyti duomenis rankomis/generuoti (rasyti 1), ar su generuotais failais (5 failai su nuo 1000 iki 10000000 studentu) (rasyti 2): ";
        while (true) {
            cin >> d_pr;
            if (isNumber(d_pr)) {
                if (stoi(d_pr) == 1 || stoi(d_pr) == 2) {
                    d = stoi(d_pr);
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
        if (d == 1) {
            string pasirink_pr;
            int pasirink;
            cout << "Ar norite dirbti su vektoriais (rasyti 1), ar list'ais (raysti 2): ";
            while (true) {
                cin >> pasirink_pr;
                if (isNumber(pasirink_pr)) {
                    if (stoi(pasirink_pr) == 1 || stoi(pasirink_pr) == 2) {
                        pasirink = stoi(pasirink_pr);
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
            vector <Studentas> Grupe_vector;
            list <Studentas> Grupe_list;
            string pasirinkimas_pries_pr;
            int pasirinkimas_pries;
            cout << "Pasirinkite, ar norite, kad duomenys butu skaitomi is studentai.txt failo (rasyti 1), ar ne (rasyti 2): ";
            while (true) {
                cin >> pasirinkimas_pries_pr;
                if (isNumber(pasirinkimas_pries_pr)) {
                    if (stoi(pasirinkimas_pries_pr) == 1 || stoi(pasirinkimas_pries_pr) == 2) {
                        pasirinkimas_pries = stoi(pasirinkimas_pries_pr);
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
            if (pasirinkimas_pries == 1) {
                if (pasirink == 1) {
                    skaitymas(Grupe_vector);
                }
                else {
                    skaitymas(Grupe_list);
                }
            }
            else {
                cout << "Kiek studentu grupeje? ";
                string m_pr;
                int m;
                while (true) {
                    cin >> m_pr;
                    if (isNumber(m_pr)) {
                        if (stoi(m_pr) >= 0) {
                            m = stoi(m_pr);
                            break;
                        }
                        else {
                            cout << "Ivedete neteisinga duomeni (galima ivesti tik sveikaji skaiciu, nemazesni uz 0). Kiek studentu grupeje? ";
                        }
                    }
                    else {
                        cout << "Ivedete neteisinga duomeni (galima ivesti tik sveikaji skaiciu, nemazesni uz 0). Kiek studentu grupeje? ";
                    }
                }
                if (pasirink == 1) Grupe_vector.reserve(m);
                string pasirinkimas_pr;
                int pasirinkimas;
                for (auto z = 0; z < m; z++) {
                    cout << "Pasirinkite, ar pazymius studentui nr. " << z + 1 << " ivesite rankomis (rasyti 1), ar norite, kad jie butu generuoti atsitiktinai (rasyti 2): ";
                    while (true) {
                        cin >> pasirinkimas_pr;
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
                        if (pasirink == 1) {
                            Grupe_vector.push_back(Stud_iv(z + 1));
                            cout << "Studento nr. " << z + 1 << " adresas atmintyje: "
                                << &Grupe_vector.back() << '\n';
                        }
                        else {
                            Grupe_list.push_back(Stud_iv(z + 1));
                            cout << "Studento nr. " << z + 1 << " adresas atmintyje: "
                                << &Grupe_list.back() << '\n';
                        }
                    }
                    else {
                        if (pasirink == 1) {
                            Grupe_vector.push_back(Stud_iv_atsitiktinai(z + 1));
                            cout << "Studento nr. " << z + 1 << " adresas atmintyje: "
                                << &Grupe_vector.back() << '\n';
                        }
                        else {
                            Grupe_list.push_back(Stud_iv_atsitiktinai(z + 1));
                            cout << "Studento nr. " << z + 1 << " adresas atmintyje: "
                                << &Grupe_list.back() << '\n';
                        }
                    }
                }
            }
            if (pasirink == 1) {
                cout << "Studentu vektoriaus adresas atmintyje: " << &Grupe_vector << '\n';
            }
            else {
                cout << "Studentu list'o adresas atmintyje: " << &Grupe_list << '\n';
            }
            if (pasirink == 1) {
                sort(Grupe_vector.begin(), Grupe_vector.end(), palyginimas_vardas);
            }
            else {
                Grupe_list.sort(palyginimas_vardas);
            }
            string spr;
            string spr_pr;
            cout << "Ar isvesti galutini vidurki/mediana/abu (irasykite zodi mazosiomis raidemis)? ";
            while (true) {
                cin >> spr_pr;
                if (spr_pr == "vidurki" || spr_pr == "mediana" || spr_pr == "abu") {
                    spr = spr_pr;
                    break;
                }
                else {
                    cout << "Ivedete neteisinga duomeni. Iveskite tik viena is siu zodziu: vidurki/mediana/abu: ";
                }
            }
            if (pasirink == 1) {
                rasymas(Grupe_vector, spr);
            }
            else {
                rasymas(Grupe_list, spr);
            }
        }
        else {
            vector<int> sizes = { 1000, 10000, 100000, 1000000, 10000000 };
            cout << "Jei failai jau sukurti, rasykite 1, o jei ne, tai rasykite 2: ";
            string irasas_pr;
            int irasas;
            while (true) {
                cin >> irasas_pr;
                if (isNumber(irasas_pr)) {
                    if (stoi(irasas_pr) == 1 || stoi(irasas_pr) == 2) {
                        irasas = stoi(irasas_pr);
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
            if (irasas == 2) {
                cout << "Kiek pazymiu sugeneruoti kieviename is siu failu (nuo 1 iki 20)? ";
                string paz_sk_pr;
                int paz_sk;
                while (true) {
                    cin >> paz_sk_pr;
                    if (isNumber(paz_sk_pr)) {
                        if (stoi(paz_sk_pr) <= 20 && stoi(paz_sk_pr) >= 1) {
                            paz_sk = stoi(paz_sk_pr);
                            break;
                        }
                        else {
                            cout << "Ivedete neteisinga duomeni (galima vesti tik sveikus skaicius nuo 1 iki 20): ";
                        }
                    }
                    else {
                        cout << "Ivedete neteisinga duomeni (galima vesti tik sveikus skaicius nuo 1 iki 20): ";
                    }
                }
                for (int size : sizes) {
                    failu_generavimas(size, paz_sk);
                }
            }

            vector<double> vid_skaitymas(sizes.size(), 0.0);
            vector<double> vid_rusiavimas(sizes.size(), 0.0);
            vector<double> vid_dalijimas(sizes.size(), 0.0);
            vector<double> vid_vargsiukai(sizes.size(), 0.0);
            vector<double> vid_kietiakai(sizes.size(), 0.0);
            int a = sizes.size();
            const int runs = 3;
            cout << "\nPasirinkite, pagal kuri parametra rusiuosite " << endl;
            cout << "(1 - pagal varda, 2 - pagal pavarde, 3 - pagal galutini pazymi): ";
            string pasirinkimas_pr;
            int pasirinkimas;
            while (true) {
                cin >> pasirinkimas_pr;
                if (isNumber(pasirinkimas_pr)) {
                    pasirinkimas = stoi(pasirinkimas_pr);
                    if (pasirinkimas >= 1 && pasirinkimas <= 3) {
                        break;
                    }
                    else {
                        cout << "Ivedete neteisinga duomeni (galima vesti tik skaicius 1, 2 arba 3): ";
                    }
                }
                else {
                    cout << "Ivedete neteisinga duomeni (galima vesti tik skaicius 1, 2 arba 3): ";
                }
            }
            string spr;
            string spr_pr;
            cout << "Ar isvesti galutini vidurki/mediana/abu (irasykite zodi mazosiomis raidemis)? ";
            while (true) {
                cin >> spr_pr;
                if (spr_pr == "vidurki" || spr_pr == "mediana" || spr_pr == "abu") {
                    spr = spr_pr;
                    break;
                }
                else {
                    cout << "Ivedete neteisinga duomeni. Iveskite tik viena is siu zodziu: vidurki/mediana/abu: ";
                }
            }

            cout << "Ar testuoti su vektoriais (rasyti 1), ar su list'ais (rasyti 2): ";
            string vector_ar_list_pr;
            int vector_ar_list;
            while (true) {
                cin >> vector_ar_list_pr;
                if (isNumber(vector_ar_list_pr)) {
                    if (stoi(vector_ar_list_pr) == 1 || stoi(vector_ar_list_pr) == 2) {
                        vector_ar_list = stoi(vector_ar_list_pr);
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

            cout << "Kuria strategija tikrinti (rasyti 1, 2 arba 3): ";
            string strategija_pr;
            int strategija;
            while (true) {
                cin >> strategija_pr;
                if (isNumber(strategija_pr)) {
                    strategija = stoi(strategija_pr);
                    if (strategija >= 1 && strategija <= 3) {
                        break;
                    }
                    else {
                        cout << "Ivedete neteisinga duomeni (galima vesti tik skaicius 1, 2 arba 3): ";
                    }
                }
                else {
                    cout << "Ivedete neteisinga duomeni (galima vesti tik skaicius 1, 2 arba 3): ";
                }
            }

            //Testavimas su vector tipu
            if (vector_ar_list == 1) {
                cout << "\nTestavimas su vektoriais: " << endl;
                for (int j = 0; j < runs; j++) {
                    cout << "\n" << j + 1 << " iteracija:" << endl;

                    for (int i = 0; i < a; i++) {
                        int size = sizes[i];
                        string input_file = "Generuoti_studentai" + to_string(size) + ".txt";
                        vector<Studentas> Grupe1;

                        double diff_skaitymas1 = 0.0;
                        double diff_rusiavimas1 = 0.0;
                        double diff_irasu_dalijimo1 = 0.0;
                        double diff_irasymas_i_vargsiuku_faila1 = 0.0;
                        double diff_irasymas_i_kietiaku_faila1 = 0.0;

                        skaitymas_is_generuoto_failo(Grupe1, input_file, diff_skaitymas1);
                        studentu_rusiavimas(Grupe1, size,
                            diff_rusiavimas1,
                            diff_irasu_dalijimo1,
                            diff_irasymas_i_vargsiuku_faila1,
                            diff_irasymas_i_kietiaku_faila1, pasirinkimas, strategija, spr);

                        vid_skaitymas[i] += diff_skaitymas1;
                        vid_rusiavimas[i] += diff_rusiavimas1;
                        vid_dalijimas[i] += diff_irasu_dalijimo1;
                        vid_vargsiukai[i] += diff_irasymas_i_vargsiuku_faila1;
                        vid_kietiakai[i] += diff_irasymas_i_kietiaku_faila1;
                        cout << size << " irasu testo laikas: " << diff_skaitymas1 + diff_rusiavimas1 + diff_irasu_dalijimo1 + diff_irasymas_i_vargsiuku_faila1 + diff_irasymas_i_kietiaku_faila1 << " s" << endl;
                    }

                }

                cout << "\nVIDURKIAI IS " << runs << " ITERACIJU: " << endl;
                for (int i = 0; i < a; ++i) {
                    cout << "\nFailo dydis: " << sizes[i] << endl;
                    cout << "Skaitymo vidurkis: " << (vid_skaitymas[i] / runs) << " s" << endl;
                    cout << "Rusiavimo vidurkis: " << (vid_rusiavimas[i] / runs) << " s" << endl;
                    cout << "Dalijimo vidurkis: " << (vid_dalijimas[i] / runs) << " s" << endl;
                    cout << "Vargsiuku irasymo vidurkis: " << (vid_vargsiukai[i] / runs) << " s" << endl;
                    cout << "Kietiaku irasymo vidurkis: " << (vid_kietiakai[i] / runs) << " s" << endl;
                }
            }

            //Testavimas su sarasais (list)
            else if (vector_ar_list == 2) {
                cout << "\nTestavimas su list'ais: " << endl;
                for (int j = 0; j < runs; ++j) {
                    cout << "\n" << j + 1 << " iteracija:" << endl;

                    for (int i = 0; i < a; ++i) {
                        int size = sizes[i];
                        string input_file = "Generuoti_studentai" + to_string(size) + ".txt";
                        list<Studentas> Grupe1;

                        double diff_skaitymas1 = 0.0;
                        double diff_rusiavimas1 = 0.0;
                        double diff_irasu_dalijimo1 = 0.0;
                        double diff_irasymas_i_vargsiuku_faila1 = 0.0;
                        double diff_irasymas_i_kietiaku_faila1 = 0.0;

                        skaitymas_is_generuoto_failo(Grupe1, input_file, diff_skaitymas1);
                        studentu_rusiavimas(Grupe1, size,
                            diff_rusiavimas1,
                            diff_irasu_dalijimo1,
                            diff_irasymas_i_vargsiuku_faila1,
                            diff_irasymas_i_kietiaku_faila1, pasirinkimas, strategija, spr);

                        vid_skaitymas[i] += diff_skaitymas1;
                        vid_rusiavimas[i] += diff_rusiavimas1;
                        vid_dalijimas[i] += diff_irasu_dalijimo1;
                        vid_vargsiukai[i] += diff_irasymas_i_vargsiuku_faila1;
                        vid_kietiakai[i] += diff_irasymas_i_kietiaku_faila1;
                        cout << size << " irasu testo laikas: " << diff_skaitymas1 + diff_rusiavimas1 + diff_irasu_dalijimo1 + diff_irasymas_i_vargsiuku_faila1 + diff_irasymas_i_kietiaku_faila1 << " s" << endl;
                    }
                }

                cout << "\nVIDURKIAI IS " << runs << " ITERACIJU: " << endl;
                for (int i = 0; i < a; ++i) {
                    cout << "\nFailo dydis: " << sizes[i] << endl;
                    cout << "Skaitymo vidurkis: " << (vid_skaitymas[i] / runs) << " s" << endl;
                    cout << "Rusiavimo vidurkis: " << (vid_rusiavimas[i] / runs) << " s" << endl;
                    cout << "Dalijimo vidurkis: " << (vid_dalijimas[i] / runs) << " s" << endl;
                    cout << "Vargsiuku irasymo vidurkis: " << (vid_vargsiukai[i] / runs) << " s" << endl;
                    cout << "Kietiaku irasymo vidurkis: " << (vid_kietiakai[i] / runs) << " s" << endl;
                }
            }
        }
    }
    return 0;
}

