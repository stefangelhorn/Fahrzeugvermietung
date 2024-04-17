
// menue.h

#pragma once
#include <iostream>
#include <vector>

class Menue
{
    public:
    std::string menueText;
    int auswahl;
    
    std::string print()
    {
        return '<' + std::to_string(auswahl) + "> " + menueText + '\n';
    }
;
    
};

std::vector<Menue> hauptMenu{
    {"Ende", 0}, 
    {"Fahrzeuge neu", 1},
    {"Kunde neu", 2},
    {"Vertrag neu", 3},
    {"Listen", 4}
};

std::vector<Menue> listeMenu{
    {"Kundenliste", 1},
    {"Fahrzeugliste", 2},
    {"Zurück zum Hauptmenü", 0}
};

int auswahlEingabe(int);
int menue();
void menueListe();