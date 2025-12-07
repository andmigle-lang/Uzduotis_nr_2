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
