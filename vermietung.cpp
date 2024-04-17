#include "vermietung.h"
#include "menue.h"
#include <fstream>
#include <climits>

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

    Kunde::Kunde(int nr, const std::string& name, const std::string& strasse, const std::string plz, const std::string& ort, const std::string& telefon)
    : nr(nr), name(name), strasse(strasse), plz(plz), ort(ort), telefon(telefon){}

    bool Agentur::kundenLaden(const std::string& filename)
    {
        int nr;
        std::string name, strasse, plz, ort, telefon, zeile;

        std::ifstream ifs(filename);

        if(!ifs.is_open())
        {
            std::cerr << "Fehler beim Einlesen der Kundendaten!\n";
            return false;
        }

        while(std::getline(ifs, zeile))
        {
            std::stringstream sstr(zeile);

            sstr >> nr;
            sstr.ignore();
            std::getline(sstr, name, ',');
            std::getline(sstr, strasse, ',');
            std::getline(sstr, plz, ',');            
            std::getline(sstr, ort, ',');
            sstr >> telefon;
            kunden.emplace_back(nr, name, strasse, plz, ort, telefon);
        }
        ifs.close();
        return true;
    }


    bool Agentur::kundenSpeichern(const std::string& filename) const
    {
        std::ofstream ofs(filename);

        if(!ofs.is_open())
        {
            std::cerr << "Datei " << filename << " konnte nicht geöffnet werden!\n";
            return false;
        }

        for(const auto& [nr, name, strasse, plz, ort, telefon] : kunden)
        {
            ofs << std::to_string(nr) << ',' << name << ',' << strasse << ',' << plz << ',' << ort << ',' << telefon << '\n';
        }
        ofs.close();
        return true;
    }


    void Agentur::kundenListeAusgeben() const
    {
        for(const auto& kunde : kunden)
        {
            std::cout << kunde.kundeKomplett();
        }
        std::cout << '\n';
    }

    string Kunde::kundeKomplett() const
    {
        return to_string(nr) + ',' + name + ',' + strasse + ',' + plz + ',' + ort + ',' + telefon + '\n';
    }

    string Agentur::getAgentur()const
    {
        return name + '\n' + strasse + '\n' + plz + " " + ort + '\n';
    }


    Agentur::Agentur(const std::string& name, const std::string& strasse, const std::string& plz, const std::string& ort, const std::string& filenameKunden = "kundendaten.txt", const std::string& filenameFahrzeuge = "fahrzeugdaten.txt")
    : name(name), strasse(strasse), plz(plz), ort(ort)
    {
        kundenLaden(filenameKunden);
        fahrzeugeLaden(filenameFahrzeuge);
    }


    Mietvertrag::Mietvertrag(const Datum& beginn, const Datum& ende, int kmStandBeginn, int kmStandEnde, const std::string& kennzeichen, int kundenNr)
    : beginn(beginn), ende(ende), kmStandBeginn(kmStandBeginn), kmStandEnde(kmStandEnde), fahrzeugKennzeichen(kennzeichen), kundenNr(kundenNr){}


    Fahrzeug::Fahrzeug(const std::string& farbe, const std::string& hersteller, const std::string& modell, int baujahr, bool verfuegbar, const std::string& motor, 
    int leistung, double preisProStunde, double preisProTag, double preisProWoche, double preisProKm, int kmStand, 
    const std::string& art, const std::string& kennzeichen)
    : farbe(farbe), hersteller(hersteller), modell(modell), baujahr(baujahr), verfuegbarkeit(verfuegbar), motor(motor), 
    art(art), kennzeichen(kennzeichen){}


    bool Agentur::fahrzeugdatenLaden(const std::string& filename)
    {
        std::ifstream ifs(filename);

        if(!ifs.is_open())
        {
            std::cerr << "Fehler beim Einlesen der Fahrzeugdaten!\n";
            return false;
        }

        std::string zeile, farbe, hersteller, modell, motor, art, kennzeichen;
        int baujahr, leistung, kmStand;
        bool verfuegbarkeit;
        double preisProStunde, preisProTag, preisProWoche, preisProKm;

        while(std::getline(ifs, zeile))
        {
            std::stringstream sstr(zeile);

            std::getline(sstr, farbe, ',');
            std::getline(sstr, hersteller, ',');
            std::getline(sstr, modell, ',');
            sstr >> baujahr;
            sstr.ignore();
            sstr >> verfuegbarkeit;
            sstr.ignore();
            std::getline(sstr, motor, ',');
            sstr >> leistung;
            sstr.ignore();
            sstr >> preisProStunde;
            sstr.ignore();
            sstr >> preisProTag;
            sstr.ignore();
            sstr >> preisProKm;
            sstr.ignore();
            sstr >> kmStand;
            sstr.ignore();
            std::getline(sstr, art, ',');
            sstr >> kennzeichen;
            fahrzeuge.emplace_back(farbe, hersteller, modell, baujahr, verfuegbarkeit, motor, leistung, preisProStunde, preisProTag, preisProWoche, preisProKm, kmStand, art, kennzeichen);
        }
        ifs.close();
    }