#ifndef AGENTUR_H
#define AGENTUR_H
#include "Kunde.h"
#include "Fahrzeug.h"

#include <vector>

class Agentur
{
    std::vector<Kunde> kunden;
    std::vector<Fahrzeug> fahrzeuge;
    
public:
    std::string name, strasse, plz, ort;

    Agentur(const std::string& name, const std::string& strasse, const std::string& plz, const std::string& ort, const std::string& filenameKunden = "kundendaten.txt", const std::string& filenameFahrzeuge = "fahrzeugdaten.txt");


    std::string getAgentur()const;

    bool kundenLaden(const std::string& filename);
    bool kundenSpeichern(const std::string& filename) const;
    void kundenListeAusgeben() const;

    bool fahrzeugdatenLaden(const std::string& filename);
};

#endif /* AGENTUR_H */
