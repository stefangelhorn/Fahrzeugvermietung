#ifndef KUNDE_H
#define KUNDE_H
#include <iostream>

class Kunde
{
public:
    int nr;
    std::string name;
    std::string strasse;
    std::string plz;
    std::string ort;
    std::string telefon;

    Kunde(){}
    Kunde(int nr, const std::string& name, const std::string& strasse, const std::string plz, const std::string& ort, const std::string& telefon);
    std::string getKunde() const {return name + ", " + ort;}
    std::string kundeKomplett() const;
};

#endif /* KUNDE_H */
