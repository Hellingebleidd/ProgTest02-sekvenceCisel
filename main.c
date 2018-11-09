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



int main() {
    long hi, lo, cislo,j;
    char operacia;
    int cifra=0,  binC[10], nula=0, s=0, sekv=0 ;


    //ak je spracovanie neuspesne (-1), skonci s chybou
    if (spracujVstupGetChar(&hi, &lo, &operacia) == -1)
        return vypisNespravnyVstup();


    for (j = lo; j <= hi; j++) {
        cislo=j;
        while (cislo>0){            //ak je lo=0 tak to neurobi nic, ale ak nastavim cislo >=0 tak to nefunguje absolutne
            binC[j]=cislo %2;
            cislo=cislo/2;
            cifra++;
            if (binC[j]==0) {
                nula++;
                s++;
            }
            else s=0;
            if (sekv<s) sekv=s;
        }
    }
    switch(operacia){
        case 'l':
            printf("Cifer: %d\n",cifra);
            break;
        case 'z':
            printf("Nul: %d\n", nula);
            break;
        case 's':
            printf("Sekvence: %d\n", sekv);
            break;
        default:
            printf ("Nespravny vstup.\n");
    }

    return 0;
}


