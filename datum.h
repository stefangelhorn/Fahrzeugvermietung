// -----------------------------------------------------
// datum.h
// -----------------------------------------------------
#ifndef DATUM_H // Mehrfaches Inkludieren verhindern.
#define DATUM_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <vector>

using namespace std;

class Datum
{
private:
	short tag, monat, jahr;
public:
	Datum() : tag(1), monat(1), jahr(2000){}

	Datum( int tag, int monat, int jahr)			// überladener Konstruktor
	{
		if( !setDatum( tag, monat, jahr) )
			tag = 1; monat = 1; jahr = 2000; 		// Falls Datum ungültig.
	}
	void setDatum(); 								// Setzt das aktuelle Datum.
	bool setDatum( int tag, int monat, int jahr);	// setzt ein Datum und prüft es.

	int getTag()  { return tag; }
	int getMonat()  { return monat; }
	int getJahr() { return jahr; }

	bool getSchaltjahr();
	string asString();
	void print();
};

// und noch die Prototypen

bool isSchaltjahr(int);
int monatsTage(int, bool);
int datDiff(Datum&, Datum&);


#endif // DATUM_H
