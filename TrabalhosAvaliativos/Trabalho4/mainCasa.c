#include <stdio.h>
#include <stdlib.h>

/*
====================
quicksort
 Faz um quicksort de um vetor de vetores de acordo com o primeiro número de cada coluna
====================
*/
void quicksort( int ** intervals, int left, int right ) {
    int * mid, *temp, i, j;
    i = left;
    j = right;
    mid = intervals[( left + right ) / 2];
    do {
        while ( intervals[i][0] < mid[0] ) {
            i++;
        }
        while ( intervals[j][0] > mid[0] ) {
            j--;
        }
        if ( i <= j ) {
            temp = intervals[i];
            intervals[i] = intervals[j];
            intervals[j] = temp;
            i++;
            j--;
        }
    } while ( i <= j );
    if ( left < j ) {
        quicksort( intervals, left, j );
    }
    if ( i < right ){
        quicksort( intervals, i, right );
    }
}

/*
====================
merge
 Junta os intervalos que se sobrepõem
====================
*/
int ** merge( int ** intervals, int intervalsSize, int * intervalsColSize, int * returnSize, int ** returnColumnSizes ) {
    quicksort( intervals, 0, intervalsSize-1 );

    int ** ret = ( int ** ) malloc( sizeof( int * ) );
    int retSize = 0;
    * ret = ( int * ) malloc( sizeof( int ) * 2 );
    ret[0][0] = intervals[0][0];
    ret[0][1] = intervals[0][1];

    for( int i = 1; i < intervalsSize; i++ ) {          
        if ( ( intervals[i][0] > ret[retSize][1] ) || ( intervals[i][1] < ret[retSize][0] ) ) {
            retSize++;
            ret = realloc( ret, sizeof( int * ) * ( retSize + 1 ) );
            ret[retSize] = ( int * ) malloc( sizeof( int ) * 2 );
            ret[retSize][0] = intervals[i][0];
            ret[retSize][1] = intervals[i][1];
        } else {
            if ( ret[retSize][1] < intervals[i][1] ) {
                ret[retSize][1] = intervals[i][1];
            }
            if ( ret[retSize][0] > intervals[i][0] ) {
                ret[retSize][0] = intervals[i][0];
            }
        }
    }
    
    * returnSize = retSize+1;
    * returnColumnSizes = ( int * ) malloc( sizeof( int ) * ( * returnSize ) );
    for ( int i = 0; i < * returnSize; i++ ) {
        ( * returnColumnSizes )[i] = 2;
    }
    return ret;
}

int main() {
    int c0[2] = { 1, 3 };
    int c1[2] = { 2, 6 };
    int c2[2] = { 8, 10 };
    int c3[2] = { 15, 18 };
    int * intervals[4] = { c3, c0, c2, c1 };
    int intervalsSize = 4;
    int intervalsColSize = 2;
    int returnSize;
    int * returnColumnSizes;

    int ** ret = merge( intervals, intervalsSize, &intervalsColSize, &returnSize, &returnColumnSizes);

    for ( int i = 0; i < returnSize; i++ ){
        printf( "[ %d, %d ]", ret[i][0], ret[i][1] );
    }

    for ( int i = 0; i < returnSize; i++ ){
        free( ret[i] );
    }
    free( ret );
    free( returnColumnSizes );
}
