// htab_lookup_add.c
// Řešení IJC-DU2, příklad 2, 19.4.2021
// Autor: Kirill Mikhailov, FIT
// Přeloženo: Apple Clang version 12.0.0


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "privatelib.h"
#include "htab.h"


/* If element with key == "key" already exists - function returns pointer to it *
 *  Otherwise, creates NEW element in hash-table with key == "key"              */
htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key)
{
    if(t == NULL)
    {
        fprintf(stderr, "%s ---> ERROR: Hash-Table doesn't exist\n", __func__);
        return NULL;
    }

    /* If "key" already exists, returns pointer to pair
     *  where the"key" was found */
    if(htab_find(t, key) != NULL) return htab_find(t, key);

    /* -------------- If "key" was found, here function run will stop ----------------- */

    /* Creating (so, allocating memory for) new element of hash-table */
    htab_item_t * new = malloc(sizeof(htab_item_t));
    new->itemData = malloc(sizeof(htab_pair_t));
    new->itemData->key = malloc(sizeof(char) * (strlen(key) + 1));
    strcpy((char*)new->itemData->key, key);
    new->itemData->value = 0;
    /* Points nowhere, because new element will be the last in "chain" */
    new->next = NULL;

    /* Checking if new item was successfully allocated */
    if(new == NULL || new->itemData == NULL || new->itemData->key == NULL)
    {
        fprintf(stderr, "%s ---> ERROR: Unable to create new item\n",__func__);
        return NULL;
    }



    if(t->itemPtrsArr[htab_hash_function(key) % t->arr_size] == NULL)
    {
        t->itemPtrsArr[htab_hash_function(key) % t->arr_size] = new;                /* If there's no chain in node with same hash - creates first (our new) element in this node */
        t->size++;     /* increments actual size of records in hash-table */
        return t->itemPtrsArr[htab_hash_function(key) % t->arr_size]->itemData;
    }

    /* Will constantly change in while-cycle */
    htab_item_t * buffer = t->itemPtrsArr[htab_hash_function(key) % t->arr_size];


    while(buffer != NULL)
    {
        if(strcmp(buffer->itemData->key, key) == 0)
        {
            return buffer->itemData;
        }
        if (buffer->next == NULL)
        {
            buffer->next = new;
            t->size++;
            return buffer->next->itemData;
        }
        buffer = buffer->next;
    }

    /* ---------- Will NEVER reach this point, made just for the function to return something ----------- */
    return NULL;
}
