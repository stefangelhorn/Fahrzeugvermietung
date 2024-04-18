#include "Kunde.h"

    Kunde::Kunde(int nr, const std::string& name, const std::string& strasse, const std::string plz, const std::string& ort, const std::string& telefon)
    : nr(nr), name(name), strasse(strasse), plz(plz), ort(ort), telefon(telefon){}



    std::string Kunde::kundeKomplett() const
    {
        return std::to_string(nr) + ',' + name + ',' + strasse + ',' + plz + ',' + ort + ',' + telefon + '\n';
    }
