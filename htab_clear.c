// htab_clear.c
// Řešení IJC-DU2, příklad 2, 19.4.2021
// Autor: Kirill Mikhailov, FIT
// Přeloženo: Apple Clang version 12.0.0


#include <stdlib.h>
#include <stdio.h>
#include "privatelib.h"
#include "htab.h"

/* Clears every record in hash-table (NOT DELETING THE TABLE) */
void htab_clear(htab_t *t)
{
    if (t == NULL)
    {
        fprintf(stderr, "%s ---> ERROR: No hash-table to be cleared. Ending program...", __func__);
        return;
    }


    for(size_t i = 0; i < t->arr_size; i++)
    {
        htab_item_t *buffer = t->itemPtrsArr[i];
        while(buffer != NULL)
        {
            htab_item_t *save_next = buffer->next; /* Saves pointer to the next item */
            free((char*)buffer->itemData->key);
            free(buffer->itemData);
            free(buffer);

            buffer = save_next;                    /* buffer is now pointer to (saved above) next item */
        }
        t->itemPtrsArr[i] = NULL;
    }

    t->size = 0;  /* Size is actual count of records in table, SOOO now it's 0 */
}
