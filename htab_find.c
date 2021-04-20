// htab_find.c
// Řešení IJC-DU2, příklad 2, 19.4.2021
// Autor: Kirill Mikhailov, FIT
// Přeloženo: Apple Clang version 12.0.0


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "privatelib.h"
#include "htab.h"

/* Looking for element with key == "key" and returns pointer to it if was found.  *
 *  Otherwise, returns NULL                                                       */
htab_pair_t * htab_find(htab_t * t, htab_key_t key)
{
    if(t == NULL)
    {
        fprintf(stderr, "%s ---> ERROR: Hash table doesn't exist", __func__ );
        return NULL;
    }

    /* If even hash of "key" wasn't found in table, there's no point in looking further */
    if(t->itemPtrsArr[htab_hash_function(key) % t->arr_size] == NULL)
    {
        return NULL;
    }

    /* If element (pair) with key == "key" will be found, this will be returned by function */
    htab_pair_t * found;

    htab_item_t * buffer = t->itemPtrsArr[htab_hash_function(key) % t->arr_size];

    while(buffer != NULL)
    {
        if (strcmp(buffer->itemData->key, key) == 0) {
            found = buffer->itemData;
            return found;
        } else buffer = buffer->next;
    }

    /* ------------ This point will be reached if pair with the same key wasn't found -------------- */
    return NULL;
}
