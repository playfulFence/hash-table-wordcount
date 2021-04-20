// htab_size.c
// Řešení IJC-DU2, příklad 2, 19.4.2021
// Autor: Kirill Mikhailov, FIT
// Přeloženo: Apple Clang version 12.0.0


#include <stdlib.h>
#include <stdio.h>
#include "privatelib.h"
#include "htab.h"


/* Returns actual size of your hash-table */
size_t htab_size(const htab_t * t)
{
    if (t == NULL)
    {
        fprintf(stderr, "%s ---> ERROR: Hash-table doesn't exist\n", __func__);
        exit (1);
    }

    return t->size;
}
