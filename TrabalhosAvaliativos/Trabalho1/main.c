#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
====================
Compare
    Compara a string "word" de tamanho "lenWord" com a string "licensePlate" de tamanho "lenPlate".
    Retorna 0 se a string "word" não tiver todas as letras de "licensePlate", ou o tamanho de "word" se tiver todas as letras, ignorando se são maiúsculas ou minúsculas, números e espaços.
====================
*/
int Compare( char * licensePlate, char * word, int lenPlate, int lenWord );

/*
====================
ShortestCompletingWord
    Compara as palavras do array de strings "words", de tamanho "wordsSize", com a string "licensePlate". 
    Retorna a menor string de "words" que possua todas as letras de "licensePlate", ignorando se são maiúsculas ou minúsculas, números e espaços.
====================
*/
char * ShortestCompletingWord( char * licensePlate, char ** words, int wordsSize );

int main( int argc, char const *argv[] ) {
    char * licensePlate = "Ah71752";
    int wordsSize = 10;
    char * words[] = { "suggest", "letter", "of", "husband", "easy", "education", "drug", "prevent", "writer", "old"};
    printf ( "%s", ShortestCompletingWord( licensePlate, words, wordsSize ) );
    return 0;
}

int Compare( char * licensePlate, char * word, int lenPlate, int lenWord ) {
    int test = 0;
    char * temp = ( char * ) malloc ( sizeof ( char ) * ( lenWord+1 ) );
    strcpy ( temp, word );
    for ( int i = 0; i < lenPlate; i++ ) {
        for ( int j = 0; j < lenWord; j ++ ) {
            if ( licensePlate[i] == temp[j] ) {
                temp[ j ] = ' ';
                test ++;
                j = lenWord;
            }
        }
        if ( i + 1 != test ) {
            free( temp );
            return 0;
        } 
    }
    free( temp );
    return lenWord;
}

char * ShortestCompletingWord( char * licensePlate, char ** words, int wordsSize ) {
    char * retorno = NULL;
    int lenPlate = 0;
    for ( int i = 0; licensePlate[i] != '\0'; i ++ ) {
        if ( isalpha( licensePlate[i] ) ) {
            lenPlate ++;
        }
    }
    char * cleanLicense = ( char * ) malloc ( sizeof ( char ) * lenPlate );
    lenPlate = 0;
    for ( int i = 0; licensePlate[i] != '\0'; i ++ ) {
        if ( isalpha ( licensePlate[i] ) ) {
            cleanLicense[lenPlate] = tolower( licensePlate[i] );
            lenPlate ++;
        }
    }
    int retSize;
    for( int i = 0; i < wordsSize; i++ ){
        int lenWord = strlen ( words[i] );
        if( retorno == NULL ) {
            retSize = Compare ( cleanLicense, * ( words + i ), lenPlate, lenWord );
            if( retSize ){    
                retorno = * ( words + i );
            }
        } else if ( retSize > lenWord ) {
            int temp = Compare ( cleanLicense, * ( words + i ), lenPlate, lenWord );
            if ( temp ) {
                retSize = temp;
                retorno = * ( words + i );
            }
        }
    }
    free ( cleanLicense );
    return retorno;
}
