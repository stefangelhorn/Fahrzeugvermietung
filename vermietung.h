#pragma once

#include "datum.h"

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

    Fahrzeug();
};

vector<string> Fahrzeugarten 
{ 
    "PKW", "LKW", "Motorrad", "Roller", "Quad", "Bus", "Wohnmobil"
};

class Agentur
{
public:
    string name, strasse, plz, ort;

    Agentur():name("Auto-Gangster"), strasse("Hauptstraße 666"), plz("28203"), ort("Bremen"){};

    string getAgentur() 
    {
        return name + '\n' + strasse + '\n' + plz + " " + ort + '\n';
    }
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

    Mietvertrag();
};

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
    string getKunde() {return name + ", " + ort;}
    string kundeKomplett ()
    {
        return to_string(nr) + ',' + name + ',' + strasse + ',' + plz + ',' + ort + ',' + telefon + '\n';
    }
};

void gehtNochNicht();
vector <Kunde> kunden;
Kunde neuKunde();
void kundenLaden();
void kundenSpeichern();
void kundenListeAusgeben();



