#include "palyginimas_class.h"

bool palyginimas_vardas_class(const Studentas_klase& a, const Studentas_klase& b) {
    return a.vardas() < b.vardas();
}
bool palyginimas_pavarde_class(const Studentas_klase& a, const Studentas_klase& b) {
    return a.pavarde() < b.pavarde();
}
bool palyginimas_galutinis_class(const Studentas_klase& a, const Studentas_klase& b) {
    return a.galutinis() < b.galutinis();
}

bool palyginimas_2_strategija_class(const Studentas_klase& a, const Studentas_klase& b) {
    return a.galutinis() > b.galutinis();
}
bool partition_palyginimas_class(const Studentas_klase& s) {
    return s.galutinis() >= 5.0;
}