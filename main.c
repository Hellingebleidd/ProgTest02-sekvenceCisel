#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int vypisNespravnyVstup() {
    printf("Nespravny vstup.\n");
    return -1;
}

int spracujVstupGetChar(long *hi, long *lo, char *operacia) {
    char stateMachine[] = "<AB;C x";  //prechody medzi stavmi <9;9> x
    int state = 0;  //aktualny stav
    char c;         //precitana hodnota
    long cislo = 0;  //pomocna hodnota cislo

    printf("Zadejte interval:\n");

    while ((c = (char) getchar()) != '\n') {
        switch (stateMachine[state]) {

            case '<':       //prvy zobacik
                if (c != '<')
                    return -1;
                state++;
                break;

            case 'A':       //musi byt cislo
                if (c < '0' || c > '9')
                    return -1;
                state++;
                cislo = c - '0';  //zapise cislo
                break;

            case 'B':       //musi byt cislo, alebo ;
                if (c == ';') {
                    state++;
                    *lo = cislo;
                } else if (c < '0' || c > '9')
                    return -1;
                cislo = (cislo * 10) + (c - '0');  //zapise cislo
                break;

            case ';':       //musi byt cislo
                if (c < '0' || c > '9')
                    return -1;
                state++;
                cislo = c - '0';  //zapise cislo
                break;

            case 'C':       //musi byt cislo, alebo >
                if (c == '>') {
                    state++;
                    *hi = cislo;
                } else if (c < '0' || c > '9')
                    return -1;
                cislo = (cislo * 10) + (c - '0');  //zapise cislo
                break;

            case ' ':       //ocakava medzeru
                if (c != ' ')
                    return -1;
                state++;
                break;

            case 'x':       //pozadovana operacia lzs
                if (c != 'l' && c != 'z' && c != 's')
                    return -1;
                state++;
                *operacia = c;
                break;

            default:
                return -1;
        }
//        printf("%c.", c);
    }
//    printf("\nVsetko v poriadku\n lo=%ld hi=%ld \n", *lo, *hi);
    if (*lo > *hi)
        return -1;

    return 0;
}


int main() {
    char retazec[3000] = "";
    int pocitadlo = 0;
    long hi, lo;
    char operacia;
    long cislo, tmp;


    //ak je spracovanie neuspesne (-1), skonci s chybou
//    if (spracujVstupGetChar(&hi, &lo, &operacia) == -1)
//        return vypisNespravnyVstup();
//    printf("lo=%ld, hi=%ld, operacia=%c\n", lo, hi, operacia);

    //testovanie 1683;1999
    lo = 10;
    hi = 20;
    //cisla nie je potrebno zobrazovat, preto retazec nebudem otacat
    for (cislo = lo; cislo <= hi; ++cislo) {
        tmp = cislo;
        do {
            retazec[pocitadlo++] = (char) ((tmp % 2) + '0');
        } while ((tmp = tmp / 2) > 0);
        retazec[pocitadlo++] =' ';
    }

    printf("Binarne cislo je: %s, %d", retazec, pocitadlo);


    return 0;
}

