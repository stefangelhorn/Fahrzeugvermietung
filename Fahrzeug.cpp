#include "Fahrzeug.h"

    Fahrzeug::Fahrzeug(const std::string& farbe, const std::string& hersteller, const std::string& modell, int baujahr, bool verfuegbar, const std::string& motor, 
    int leistung, double preisProStunde, double preisProTag, double preisProWoche, double preisProKm, int kmStand, 
    const std::string& art, const std::string& kennzeichen)
    : farbe(farbe), hersteller(hersteller), modell(modell), baujahr(baujahr), verfuegbarkeit(verfuegbar), motor(motor), 
    art(art), kennzeichen(kennzeichen){}
