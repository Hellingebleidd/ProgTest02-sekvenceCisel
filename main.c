#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 40

struct zadanie {
    char vstup[MAX_LEN];//vstupny retazec
    long lo, hi;         //interval
    int operacia;       //pozadovana operacia
};

int vypisNespravnyVstup() {
    printf("Nespravny vstup.\n");
    return -1;
}

int spracujVstup(struct zadanie *poziadavka) {
    int dlzka;              //dlzka vstupneho retazca
    char vstup[MAX_LEN], *subbuff;  //pracovny retazec

    strcpy(vstup, poziadavka->vstup);
    dlzka = (int) strlen(vstup);

    //prva kontrola na dlzku
    if (dlzka < 7)
        return vypisNespravnyVstup();
    //hlada prvy <
    if (vstup[0] != '<')
        return vypisNespravnyVstup();

    //kontroluje lo; zacina za <
    int i = 1;
    while (vstup[i] != ';') {
        if (vstup[i] < '0' || vstup[i] > '9' || ++i >= dlzka)
            return vypisNespravnyVstup();
    }
    //dostal sa na ; vypocita cislo
    poziadavka->lo = strtol(vstup + 1, &subbuff, 10);
    //do vstup skopiruje zvysok
    strcpy(vstup, subbuff);

    //kontroluje hi>
    i = 1;
    dlzka = (int) strlen(vstup);
    while (vstup[i] != '>') {
        if (vstup[i] < '0' || vstup[i] > '9' || ++i >= dlzka)
            return vypisNespravnyVstup();
    }
    //dostal sa na > vypocita cislo
    poziadavka->hi = strtol(vstup + 1, &subbuff, 10);
    //do vstup skopiruje zvysok
    strcpy(vstup, subbuff);

    //kontroluje operaciu: presne 3 znaky, [1] je ' ', [2] je zo zoznamu
    if (strlen(vstup) == 3 && vstup[1] == ' ' && (vstup[2] == 'l' || vstup[2] == 'z' || vstup[2] == 's'))
        poziadavka->operacia = vstup[2];
    else
        return vypisNespravnyVstup();

    return 1;

}


int main() {
//    char subbuff[MAX_LEN];  //pracovny retazec

    struct zadanie poziadavka;


    printf("Zadejte interval:\n");
    scanf(" %40s", poziadavka.vstup);

    //ak je spracovanie neuspesne (-1), skonci s chybou
    if (spracujVstup(&poziadavka) == -1)
        return -1;


    return 0;
}

