#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
    long hi, lo;
    char operacia;
    long i, cislo, tmpNajdlhsieNuly;
    long sekvence = 0, nul = 0, cifer = 0;
    int vysledok;

    printf("Zadejte interval:\n");
    vysledok = scanf(" < %ld ; %ld > %c", &lo, &hi, &operacia);
    if (vysledok != 3 || (operacia != 'l' && operacia != 'z' && operacia != 's') || lo > hi || lo < 0 || hi < 0) {
        printf("Nespravny vstup.\n");
        return -1;
    }

    //cisla nie je potrebno zobrazovat, preto retazec nebudem otacat
    for (i = lo; i <= hi; ++i) {
        cislo = i;
        tmpNajdlhsieNuly = 0;
        do {
            switch (cislo % 2) {
                case 0:
                    tmpNajdlhsieNuly++;
                    nul++;
                    cifer++;
                    break;
                case 1:
                    if (sekvence < tmpNajdlhsieNuly)
                        sekvence = tmpNajdlhsieNuly;
                    tmpNajdlhsieNuly = 0;
                    cifer++;
                    break;
                default:
                    return -1;  //dajaka glupocina
            }
        } while ((cislo = cislo / 2) > 0);
        if (sekvence < tmpNajdlhsieNuly)
            sekvence = tmpNajdlhsieNuly;
    }

//    l pro výpočet celkové délky sekvence (počtu cifer),
//    z pro výpočet počtu nul v sekvenci,
//    s pro výpočet nejdelší kontinuální sekvence nul.
//    printf("Pro <%li;%li> -> Cifer: %li, Nul: %li, Sekvence: %li", lo, hi, cifer, nul, sekvence);
    switch (operacia) {
        case 'l':
            printf("Cifer: %li\n", cifer);
            break;

        case 'z':
            printf("Nul: %li\n", nul);
            break;
        case 's':
            printf("Sekvence: %li\n", sekvence);
            break;
        default:
            break;
    }

    return 0;
}

