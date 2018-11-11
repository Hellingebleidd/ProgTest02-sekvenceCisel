#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long hi, lo, cislo, j;
    char operacia;
    int cifra = 0, binC, nula = 0, s = 0, sekv = 0;
    int vysledok;


    printf("Zadejte interval:\n");
    vysledok = scanf(" < %ld ; %ld > %c", &lo, &hi, &operacia);
    if (vysledok != 3 || (operacia != 'l' && operacia != 'z' && operacia != 's') || lo > hi || lo < 0 || hi < 0) {
        printf("Nespravny vstup.\n");
        return -1;
    }


    for (j = hi; j >= lo; j--) {
        cislo = j;
        do {            //ako napisem 0 alebo 9 cyhodi nespravny vstup
            binC = cislo % 2;
            cislo = cislo / 2;
            cifra++;
            if (binC == 0) {
                nula++;
                s++;
            } else
                s = 0;
            if (sekv < s) sekv = s;
        } while (cislo > 0);
    }
    switch (operacia) {
        case 'l':
            printf("Cifer: %d\n", cifra);
            break;
        case 'z':
            printf("Nul: %d\n", nula);
            break;
        case 's':
            printf("Sekvence: %d\n", sekv);
            break;
        default:
            printf("Nespravny vstup.\n");
    }

    return 0;
}


