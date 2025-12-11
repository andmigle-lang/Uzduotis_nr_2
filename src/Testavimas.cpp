#include <iostream>

#include "catch2/catch.hpp"

#include "Studentas_klase.h"

#include <sstream>

using std::stringstream;

TEST_CASE("Default constructor", "[Default][Constructor]") {
    Studentas_klase stud;
    REQUIRE(stud.vardas() == "");
    REQUIRE(stud.pavarde() == "");
    REQUIRE(stud.egzaminas() == 0);
    REQUIRE(stud.galutinis() == 0.0);
    REQUIRE(stud.mediana_galutinis() == 0.0);
}

TEST_CASE("Copy constructor", "[Copy][Constructor]") {
    stringstream ss("Jonas Jonaitis 10 9 8");
    Studentas_klase stud;
    stud.skaityk_studenta_class(ss);

    Studentas_klase KopijaStud(stud);
    REQUIRE(KopijaStud == stud);
}

TEST_CASE("Copy Assignment operator", "[Copy][Assignment][Operator]") {
    stringstream ss("Petras Petraitis 7 6 5");
    Studentas_klase stud;
    stud.skaityk_studenta_class(ss);

    Studentas_klase KopijaStud;
    KopijaStud = stud;
    REQUIRE(KopijaStud == stud);
}
