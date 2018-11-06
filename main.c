#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


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


int binarneCislo(long cislo){
    int pocet,i;
    int bin[40];

    pocet=0;  //nastavi index na 0
    while(cislo>0) {
        bin[pocet]=cislo % 2;
        cislo=cislo/2;
        pocet++;
    }

    //vypise to bin. cislo v opacnom poradi
    //TODO: on ich nema vypisovat, iba pamatat si...
    for (i=(pocet-1); i>=0; i--){
        printf("%d", bin[i]);
    }

}



int main() {
    long hi, lo, cislo;
    char operacia;
    int poc,j;


    //ak je spracovanie neuspesne (-1), skonci s chybou
    if (spracujVstupGetChar(&hi, &lo, &operacia) == -1)
        return vypisNespravnyVstup();
    printf("lo=%ld, hi=%ld, operacia=%c\n", lo, hi, operacia);

    //vypise cisla binarne
    poc=hi-lo;
    for (j=0; j<=poc; j++){
        cislo=lo+j;
        printf(" ", binarneCislo(cislo));
    }

    return 0;
}

