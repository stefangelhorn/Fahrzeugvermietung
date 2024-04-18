#include "vermietung.h"
#include "menue.h"
#include "Agentur.h"

int main()
{

    Agentur agentur{"Scherzers Karren", "Scherzstrasse 4", "22458", "Delmenhorst"};
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
