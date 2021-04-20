# Hash-table libraries and functions for C

SO, this stuff was created as University Project. Here you can find some functions and libraries for creating, editing and doing different things with your hash-table.

Makefile creates static(libhtab.a) and shared(libhtab.so) variants of library.

htab.h - library, which includes (nearly)all declarations of functions and datatypes, that you require.

privatelib.h - private library, which FINALLY AND IRREVOCABLY defines few datatypes :D 

Also, you can find program(wordcount.c) which counts occurrences of different words from standard input(using hash-tables, of course).

------------------- SHORT DESCRIPTION -------------------

htab_t * htab_init(size_t n);    TABLE CONSTRUCTOR
htab_t * htab_move(size_t n, htab_t * from);    MOVES DATA TO NEW TABLE
size_t htab_size(const htab_t * t);    NUMBER OF RECORDS IN THE TABLE
size_t htab_bucket_count(const htab_t * t);   THE SIZE OF THE POINTERS ARRAY


htab_pair_t * htab_find(htab_t * t, htab_key_t key);    SEARCHING
htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key);    SEARCHING AND ADDING(IF WASN'T FOUND)


bool htab_erase(htab_t * t, htab_key_t key);    DELETES THE ENTERED RECORD


void htab_for_each(const htab_t * t, void (* f)(htab_pair_t * data));   GOES THROUGH ALL RECORDS AND CALLS THE FUNCTION f ON THEM

void htab_clear(htab_t * t);    DELETES ALL RECORDS
void htab_free(htab_t * t);     TABLE DESTRUCTOR
