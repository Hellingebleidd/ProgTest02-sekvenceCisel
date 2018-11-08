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
    }

    if (*lo > *hi)
        return -1;

    return 0;
}

int main() {
    long hi, lo;
    char operacia;
    long i, cislo, tmpNajdlhsieNuly;
    long sekvence = 0, nul = 0, cifer = 0;

    //ak je spracovanie neuspesne (-1), skonci s chybou
    if (spracujVstupGetChar(&hi, &lo, &operacia) == -1){
        printf("Nespravny vstup.\n");
        return -1;
    }
//    printf("lo=%ld, hi=%ld, operacia=%c\n", lo, hi, operacia);

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

