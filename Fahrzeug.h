#ifndef FAHRZEUG_H
#define FAHRZEUG_H
#include <iostream>

class Fahrzeug
{
public:
    std::string farbe;
    std::string hersteller;
    std::string modell;
    int baujahr;
    bool verfuegbarkeit;
    std::string motor;
    int leistung;
    double preisProStunde;
    double preisProTag;
    double preisProWoche;
    double preisProKm;
    int kmStand;
    std::string art;
    std::string kennzeichen;

//    Fahrzeug(){};
    Fahrzeug(const std::string& farbe, const std::string& hersteller, const std::string& modell, int baujahr, bool verfuegbar, const std::string& motor, 
    int leistung, double preisProStunde, double preisProTag, double preisProWoche, double preisProKm, int kmStand, 
    const std::string& art, const std::string& kennzeichen);
};


#endif /* FAHRZEUG_H */
