#pragma once

#include "datum.h"
#include <fstream>
#include <sstream>
#include <vector>

class Kunde
{
public:
    int nr;
    string name;
    string strasse;
    string plz;
    string ort;
    string telefon;

    Kunde(){}
    Kunde(int nr, const std::string& name, const std::string& strasse, const std::string plz, const std::string& ort, const std::string& telefon);
    string getKunde() const {return name + ", " + ort;}
    string kundeKomplett() const;
};


class Fahrzeug
{
public:
    string farbe;
    string hersteller;
    string modell;
    int baujahr;
    bool verfuegbarkeit;
    string motor;
    int leistung;
    double preisProStunde;
    double preisProTag;
    double preisProWoche;
    double preisProKm;
    int kmStand;
    string art;
    string kennzeichen;

//    Fahrzeug(){};
    Fahrzeug(const std::string& farbe, const std::string& hersteller, const std::string& modell, int baujahr, bool verfuegbar, const std::string& motor, 
    int leistung, double preisProStunde, double preisProTag, double preisProWoche, double preisProKm, int kmStand, 
    const std::string& art, const std::string& kennzeichen);
};

vector<string> Fahrzeugarten 
{ 
    "PKW", "LKW", "Motorrad", "Roller", "Quad", "Bus", "Wohnmobil"
};

class Agentur
{
    std::vector<Kunde> kunden;
    std::vector<Fahrzeug> fahrzeuge;
    
public:
    string name, strasse, plz, ort;

    Agentur(const std::string& name, const std::string& strasse, const std::string& plz, const std::string& ort, const std::string& filenameKunden = "kundendaten.txt", const std::string& filenameFahrzeuge = "fahrzeugdaten.txt");


    string getAgentur()const;

    bool kundenLaden(const std::string& filename);
    bool kundenSpeichern(const std::string& filename) const;
    void kundenListeAusgeben() const;

    bool fahrzeugdatenLaden(const std::string& filename);
};


class Mietvertrag
{   
public:    
    Datum beginn;
    Datum ende;
    int kmStandBeginn;
    int kmStandEnde;
    string fahrzeugKennzeichen;
    int kundenNr;

    Mietvertrag(){};
    Mietvertrag(const Datum& beginn, const Datum& ende, int kmStandBeginn, int kmStandEnde, const std::string& kennzeichen, int kundenNr);
};


void gehtNochNicht();
vector <Kunde> kunden;
Kunde neuKunde();



