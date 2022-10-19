// Nutzung von sizeof fuer Verbunde (structs)
//
// Fazit:
// Die Summe der Groessen der Einzelkomponenten ist im allgemeinen kleiner
// als die Groesse der Struktur. Das liegt am Alignement.

#include <stdio.h>
#define OK 0

struct adresse {
    // Alle char[] sind '\0' terminierte Strings.
    char strasse[20];     //        20
    char hausnummer[5];   //         5
    int  postleitzahl;    //         4
    char stadt[20];       //        20
};                        // Summe  49

struct student {
    char matrikelnummer[6]; // char[] wegen fuehrender Nullen in Matrikelnummern
    char studiengang[5];
    char nachname[20];
    char vorname[20];
    struct adresse wohnort; // Komponententyp ist selbst eine Struktur!
};

struct jadresse {
    char *strasse;
    char *hausnummer;
    int  postleitzahl;
    char *stadt;
};           

struct jstudent {
    char *matrikelnummer;
    char *studiengang;
    char *nachname;
    char *vorname;
    struct jadresse *wohnort;
};


int main(void) {
    struct adresse addr2;
    struct student stud2;
    struct jadresse addr3;
    struct jstudent stud3;

    printf("sizeof %s:%d, netto %d\n","addr2",(int) sizeof(addr2), 20+5+4+20 );
    printf("sizeof %s:%d, netto %d\n","stud2",(int) sizeof(stud2), 6+5+20+20+(int) sizeof(addr2) );
    printf("sizeof %s:%d, netto %d\n","addr3",(int) sizeof(addr3), 8+8+4+8 );
    printf("sizeof %s:%d, netto %d\n","stud3",(int) sizeof(stud3), 5*8 );

    printf("&strasse:\t%p\n&hausnummer:\t%p\n&postleitzahl:\t%p\n&stadt:\t\t%p\n",
        &addr3.strasse,&addr3.hausnummer,&addr3.postleitzahl,&addr3.stadt);
    return OK;
}
