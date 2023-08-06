#include <stdio.h>

/*
====================
fillCups
    Tem três dispensas com 3 conteúdos diferentes, e precisa preencher um total de "amount[0]", "amount[1]" e "amount[2]" de copos,
    sendo cada "amount[]" quantos copos com aquele conteúdo devem ser preenchidos.
    Retorna quantos segundos demora para preencher os copos, podendo utilizar até 2 dispensas diferentes por segundo.
====================
*/
int fillCups ( int * amount, int amountSize ) {
    int r = 0;
    if ( ( amount[0] ) > ( amount[1] + amount[2] ) ) {
        r = amount[0] - ( amount[1] + amount[2] );
    } else if ( ( amount[1] ) > ( amount[0] + amount[2] ) ) {
        r = amount[1] - ( amount[0] + amount[2] );
    } else if ( ( amount[2] ) > ( amount[0] + amount[1] ) ) {
        r = amount[2] - ( amount[1] + amount[0] );
    } else {
        r = ( amount[0] + amount[1] + amount[2] ) % 2;
    }
    r = r + ( ( amount[0] + amount[1] + amount[2] - r ) / 2 );
    return r;
}

int main () {
    int amount[3] = { 5, 4, 4};
    int amountSize = 3;
    printf( "%d", fillCups ( amount, amountSize ) );
}
