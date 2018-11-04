#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 40


int main() {
    int lo = 0, hi = 0;      //interval
    char operacia;  //pozadovana operacia
    char vstup[MAX_LEN];    //vstupny retazec

    printf("Zadejte interval:\n");
    scanf(" %40s", vstup);

    //prva kontrola na dlzku
    if (strlen(vstup) < 7 ) {
        printf("Nespravny vstup.\n");
        return -1;
    }

    //hlada prvy <
    if (vstup[0] != "<") {
        printf("Nespravny vstup.\n");
        return -1;
    }

    //nacita lo
    int i = 1;
    while (vstup[i] != ";") {
        if (vstup[i] < "0" || vstup[i] > "9") {
            printf("Nespravny vstup.\n");
            return -1;
        }
        lo = (10 * lo) + atoi(vstup[i]);

        if(++i >= strlen(vstup)){
            printf("Nespravny vstup.\n");
            return -1;
        }
    }

    //posun za ;
    if(++i >= strlen(vstup)){
        printf("Nespravny vstup.\n");
        return -1;
    }

    //nacita hi
    while (vstup[i] != ">") {
        if (vstup[i] < "0" || vstup[i] > "9") {
            printf("Nespravny vstup.\n");
            return -1;
        }
        hi = (10 * hi) + atoi(vstup[i]);
        if(++i >= strlen(vstup)){
            printf("Nespravny vstup.\n");
            return -1;
        }
    }






    return 0;
}