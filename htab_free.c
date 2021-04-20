// htab_free.c
// Řešení IJC-DU2, příklad 2, 19.4.2021
// Autor: Kirill Mikhailov, FIT
// Přeloženo: Apple Clang version 12.0.0


#include <stdlib.h>
#include <stdio.h>
#include "privatelib.h"
#include "htab.h"

/* Frees your hash-table */
void htab_free(htab_t *t)
{
    if (t == NULL)
    {
        fprintf(stderr, "%s ---> ERROR: No hash-table to be freed.", __func__);
        return;
    }

    /* Clears whole table before... */
    htab_clear(t);

    /* KABOOOM */
    free(t);
}
