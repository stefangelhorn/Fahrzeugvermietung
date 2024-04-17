#include "vermietung.h"
#include "menue.h"
#include <fstream>

int main()
{
    Agentur agentur;
    cout << agentur.getAgentur();

    Datum heute;
    heute.setDatum();
    heute.print();
 
    
    do
    {
        ;
    }
    while ( menue() > 0);
    
    
    return 0;
}

int menue()
{
    int menueAuswahl;

    for(auto element : hauptMenu )
    {
        cout << element.print();
    }

    menueAuswahl = auswahlEingabe(hauptMenu.size() - 1);
 
    switch (menueAuswahl)
    {
    case 0:
        std::cout << "--> Programm beendet.\n";
        kundenSpeichern();
        break;

    case 1:
        gehtNochNicht();
        break;

    case 2:
        kunden.push_back(neuKunde());
        break;

    case 3:
        gehtNochNicht();
        break;

    case 4:
        menueListe();
        break;

    default:
        break;
    }

    return menueAuswahl;
}

void gehtNochNicht()
{
    std::cout << "Geht leider noch nicht ..." << std::endl;
}

void menueListe()
{
    for (auto element : listeMenu)
    {
        cout << element.print();
    }

    switch (auswahlEingabe(listeMenu.size() - 1))
    {
    case 1:
        kundenListeAusgeben();
        break;
    case 2:
        gehtNochNicht();
        break;
    }
}

int auswahlEingabe(int max)
{
    int eingabe;
    do
    {
        cout << "Eingabe: ";

        while (!(cin >> eingabe))
        {
            cin.clear();   
            cin.ignore(LLONG_MAX, '\n');
        }
    } while (eingabe > max || eingabe < 0);
    return eingabe;
}

Kunde neuKunde()
{
    Kunde kunde;

    cin.clear();
    cin.ignore(LLONG_MAX, '\n');
    cout << "Bitte geben sie ihren Namen ein: ";
    getline(cin, kunde.name);
    cout << "Telefonnummer: ";
    getline(cin, kunde.telefon);
    cout << "Strasse: ";
    getline(cin, kunde.strasse);
    cout << "PLZ: ";
    getline(cin, kunde.plz);
    cout << "Ort: ";
    getline(cin, kunde.ort);
    kunde.nr = 1000 + kunden.size() + 1; 
    
    return kunde;
}

void kundenListeAusgeben()
{
    for(auto element : kunden)
    {
        cout << element.kundeKomplett();
    }
}

void kundenSpeichern()
{
    string datei = "kundendaten.txt";
    
    ofstream kundendaten (datei);
    if (!(kundendaten.is_open()))
    {
        cout << datei << " konnte nicht geöffnet werden!" << endl;
        return;
    }
    
    for(auto element : kunden)
    {
        kundendaten << element.kundeKomplett();
    }
    kundendaten.close();
}

void kundenLaden()
{
    // Datei öffnen
    // prüfen, ob es geklappt hat

    // Zeile für Zeile einlesen
        // Zeile zerlegen nach Komma
        // in ein Kundenobjekt speichern
        // push_back
    // Datei schließen
}