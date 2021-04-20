// privatelib.h
// Řešení IJC-DU2, příklad 2, 19.4.2021
// Autor: Kirill Mikhailov, FIT
// Přeloženo: Apple Clang version 12.0.0


#ifndef __PRIVATE_LIB_H__
#define __PRIVATE_LIB_H__

/* Here you can see complete definition of types from htab.h */

#include "htab.h"

typedef struct htab_item htab_item_t;

struct htab_item
{
    htab_item_t* next;
    htab_pair_t *itemData;
};

struct htab
{
    int size;  /* actual count of records in table, will be (inc)/(dec)remented if we gonna add/delete element from table */
    size_t arr_size;    /* Constant number of pointers to elements (will be same with number in htab_init function) */
    htab_item_t* itemPtrsArr[];
};

#endif // __PRIVATE_LIB_H__
