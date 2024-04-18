#pragma once

#include "datum.h"
#include <fstream>
#include <sstream>
#include <vector>

vector<string> Fahrzeugarten 
{ 
    "PKW", "LKW", "Motorrad", "Roller", "Quad", "Bus", "Wohnmobil"
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


