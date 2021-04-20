// htab_move.c
// Řešení IJC-DU2, příklad 2, 19.4.2021
// Autor: Kirill Mikhailov, FIT
// Přeloženo: Apple Clang version 12.0.0


#include <stdlib.h>
#include <stdio.h>
#include "privatelib.h"
#include "htab.h"


/* Creates new hash-table, COPIES content of hash-table "from" to new hash-table
 *      then  CLEANS (not DELETES) "old" hash-table  */
htab_t *htab_move(size_t n, htab_t *from)
{
    if (from == NULL)
    {
        fprintf(stderr, "%s ---> ERROR: Hash-table that you want to move doesn't exist\n", __func__);
        exit (1);
    }

    htab_t* to = htab_init(n);  /* LOOK, a new hash-table is born. Nature is amazing... I'm crying... */

    if (to == NULL)
    {
        fprintf(stderr, "%s ---> ERROR: New Hash-Table wasn't initiated\n", __func__);
        exit (1);
    }



    for(size_t i = 0; i < from->arr_size; i++)
    {
        htab_item_t *buffer = from->itemPtrsArr[i];
        while (buffer != NULL)
        {
            htab_pair_t *newPair = htab_lookup_add(to,buffer->itemData->key); /* buffer of new "pairs" key-value in new table */
            if(newPair == NULL)
            {
                fprintf(stderr, "%s ---> ERROR: Allocation of new pair failed\n", __func__);
                return NULL;
            }
            buffer = buffer->next;
        }
    }

    htab_clear(from);

    return to;

}


