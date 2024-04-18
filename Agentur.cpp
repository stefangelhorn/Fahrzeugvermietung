#include "Agentur.h"
#include <fstream>
#include <sstream>

    std::string Agentur::getAgentur()const
    {
        return name + '\n' + strasse + '\n' + plz + " " + ort + '\n';
    }


    Agentur::Agentur(const std::string& name, const std::string& strasse, const std::string& plz, const std::string& ort, const std::string& filenameKunden = "kundendaten.txt", const std::string& filenameFahrzeuge = "fahrzeugdaten.txt")
    : name(name), strasse(strasse), plz(plz), ort(ort)
    {
        kundenLaden(filenameKunden);
        fahrzeugdatenLaden(filenameFahrzeuge);
    }

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
