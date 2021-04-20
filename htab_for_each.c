// htab_for_each.c
// Řešení IJC-DU2, příklad 2, 19.4.2021
// Autor: Kirill Mikhailov, FIT
// Přeloženo: Apple Clang version 12.0.0


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "privatelib.h"
#include "htab.h"

/* Uses some (*f) function (which returns pointer to htab_pair_t datatype)
 *          for every element in hash-table */
void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data))
{
    if (t == NULL)
    {
        fprintf(stderr, "%s ---> ERROR: Hash-table doesn't exist", __func__);
        return;
    }

    /* Will constantly change in while-cycle */
    htab_item_t * buffer;

    /* Checking all pointers (nodes) in main linked-list (hash-table) */
    for(size_t i = 0; i < t->arr_size; i++)
    {
        buffer = t->itemPtrsArr[i];
        while (buffer != NULL)
        {
            (*f)(buffer->itemData);
            /* Also checking chain-elements */
            buffer = buffer->next;
        }
    }
}
