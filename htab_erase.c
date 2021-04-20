// htab_erase.c
// Řešení IJC-DU2, příklad 2, 19.4.2021
// Autor: Kirill Mikhailov, FIT
// Přeloženo: Apple Clang version 12.0.0


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "privatelib.h"
#include "htab.h"

/* Function "erasing" element of hash-table according to the key
 *      Returns TRUE, if it was deleted, otherwise - FALSE */
bool htab_erase(htab_t * t, htab_key_t key)
{
    if(t == NULL)
    {
        fprintf(stderr, "%s ---> ERROR: Hash-Table doesn't exist", __func__);
        return false;
    }

    if(htab_find(t, key) == NULL)  /* Checks, if item with key == "key" exists in table */
    {
        fprintf(stderr, "%s ---> ERROR: The node you want to delete wasn't found\n", __func__);
        return false;
    }

   htab_item_t * buffer = t->itemPtrsArr[(htab_hash_function(key) % t->arr_size)];

    while(buffer != NULL)
    {
        if (buffer->next == NULL)  /* If next element (according to buffer) points to nowhere(NULL) */
        {
            if(strcmp(buffer->itemData->key, key) == 0)
            {
                free((char*)buffer->itemData->key);
                free(buffer->itemData);
                free(buffer);
                t->itemPtrsArr[(htab_hash_function(key) % t->arr_size)] = NULL;
                t->size--;
                return true; /* Successfully deleted */
            }
        }
        else if (strcmp(buffer->next->itemData->key, key) == 0)  /* If next element points SOMEWHERE */
        {
            htab_item_t * tmp = buffer->next->next;
            free((char*)buffer->next->itemData->key);
            free(buffer->next->itemData);
            free(buffer->next);
            buffer->next = tmp;
            t->size--;
            return true;  /* Successfully deleted */
        }
        else buffer = buffer->next;
    }

    /* ------------- FUNCTION WILL NEVER REACH THIS POINT -------------- */
    return false;
}
