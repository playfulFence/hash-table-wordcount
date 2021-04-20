// wordcount.c
// Řešení IJC-DU2, příklad 2, 19.4.2021
// Autor: Kirill Mikhailov, FIT
// Přeloženo: Apple Clang version 12.0.0

/* This program takes some text from standard input                     *
 * and counts number of occurrences of every word in this text.         *
 * Created using hash-table like C-version of associative arrays in C++ */


#include <stdio.h>
#include "privatelib.h"
#include "htab.h"
#include "io.h"

/* I used an implement limit of 127 chars in one word   *
 *   (well, it's hard to find word longer)              */
#define MAX_WORD 127


/* Prints data from pair in htab in format "key"    "data")*/
void printWord(htab_pair_t *data)
{
    printf("%s\t%d\n", data->key, data->value);
}

int main(void)
{
    /* REMEMBER: NO REWINDS */
    FILE * cin = stdin;

    /*   It is better to use prime numbers, thus there are more indexing options.
       Also, if we take relatively large numbers(but not SO large, tho), then the
          program runs faster */

    htab_t * hashTable = htab_init(43969);

    /* Will constantly change in while-cycle */
    char bufferKey[MAX_WORD];

    /* Will be changed in while-cycle */
    htab_pair_t* bufferPair;

    while(read_word(bufferKey, MAX_WORD, cin) != EOF)
    {
        bufferPair = htab_lookup_add(hashTable, bufferKey);       /* Checking/looking for occurrences of Key in table. */
        bufferPair->value++;                                      /* Increments "value" of the found/newly created element */
    }

    /* Uses printWord function for each element of whole hash-table*/
    htab_for_each(hashTable, printWord);

    /* free created hash-table */
    htab_free(hashTable);
    return 0;
}
