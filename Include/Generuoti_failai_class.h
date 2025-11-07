#pragma once
#include <vector>
#include <string>
#include "Studentas_klase.h"

using std::vector;
using std::string;

// Skatomi generuoti failai
void skaitymas_is_generuoto_failo_class(vector<Studentas_klase>& Grupe,
    const std::string& failo_vardas,
    double& diff_skaitymas1);

// Studentu rusiavimas tik vektoriams
void studentu_rusiavimas_class(vector<Studentas_klase>& Grupe,
    int k,
    double& diff_rusiavimas1,
    double& diff_irasu_dalijimo1,
    double& diff_irasymas_i_vargsiuku_faila1,
    double& diff_irasymas_i_kietiaku_faila1,
    int i,
    int rusiavimo_strategija, const string& spr);