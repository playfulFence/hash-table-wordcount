// htab_init.c
// Řešení IJC-DU2, příklad 2, 19.4.2021
// Autor: Kirill Mikhailov, FIT
// Přeloženo: Apple Clang version 12.0.0


#include <stdlib.h>
#include <stdio.h>
#include "privatelib.h"
#include "htab.h"

/* "Mother" of our hash-table. This function creates it !!! */
htab_t *htab_init(size_t n)
{
    htab_t *hashTable = malloc((sizeof(htab_item_t*) * n) + sizeof(htab_t));
    if(hashTable == NULL)
    {
        fprintf(stderr, "%s ---> ERROR: Hash-Table allocation failed", __func__ );  /* bruh... */
        return NULL;
    }
    hashTable->arr_size = n; /* Declared and CONSTANT count of array of pointers */
    hashTable->size = 0; /* But this one will change, according to count of actual recordings in table */
    for(size_t i = 0; i < n; i++)
    {
        hashTable->itemPtrsArr[i] = NULL;  /* STOP SEGFAULT */
    }

    return hashTable;
}
