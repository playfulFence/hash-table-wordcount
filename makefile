CC = gcc
CFLAGS = -g -std=c99 -pedantic -Wall -Wextra

all : wordcount wordcount-dynamic tail

wordcount: wordcount.o io.o libhtab.a htab.h privatelib.h
		$(CC) $(CFLAGS) wordcount.o io.o -L. -static -lhtab -o wordcount

wordcount-dynamic: wordcount.o io.o libhtab.so htab.h privatelib.h
		$(CC) $(CFLAGS) wordcount.o io.o -L. -lhtab -o wordcount-dynamic

tail: tail.o
		$(CC) $(CFLAGS) tail.o -o tail

wordcount.o: wordcount.c
		$(CC) $(CFLAGS) -c wordcount.c -o wordcount.o

libhtab.a: htab_init.o htab_move.o htab_size.o htab_bucket_count.o htab_find.o htab_lookup_add.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o htab_hash_function.o htab.h privatelib.h
		ar -rcs libhtab.a htab_init.o htab_move.o htab_size.o htab_bucket_count.o htab_find.o htab_lookup_add.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o htab_hash_function.o

libhtab.so: htab_init.o htab_move.o htab_size.o htab_bucket_count.o htab_find.o htab_lookup_add.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o htab_hash_function.o htab.h privatelib.h
		$(CC) $(CFLAGS) -fPIC -shared htab_init.o htab_move.o htab_size.o htab_bucket_count.o htab_find.o htab_lookup_add.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o htab_hash_function.o -o libhtab.so

htab_init.o: htab_init.c
		$(CC) $(CFLAGS) -c htab_init.c -fPIC -o htab_init.o

htab_move.o: htab_move.c
		$(CC) $(CFLAGS) -c htab_move.c -fPIC -o htab_move.o

htab_size.o: htab_size.c
		$(CC) $(CFLAGS) -c htab_size.c -fPIC -o htab_size.o

htab_bucket_count.o: htab_bucket_count.c
		$(CC) $(CFLAGS) -c htab_bucket_count.c -fPIC -o htab_bucket_count.o

htab_find.o: htab_find.c
		$(CC) $(CFLAGS) -c htab_find.c -fPIC -o htab_find.o

htab_lookup_add.o: htab_lookup_add.c
		$(CC) $(CFLAGS) -c htab_lookup_add.c -fPIC -o htab_lookup_add.o

htab_erase.o: htab_erase.c
		$(CC) $(CFLAGS) -c htab_erase.c -fPIC -o htab_erase.o

htab_for_each.o: htab_for_each.c
		$(CC) $(CFLAGS) -c htab_for_each.c -fPIC -o htab_for_each.o

htab_clear.o: htab_clear.c
		$(CC) $(CFLAGS) -c htab_clear.c -fPIC -o htab_clear.o

htab_free.o: htab_free.c
		$(CC) $(CFLAGS) -c htab_free.c -fPIC -o htab_free.o

htab_hash_function.o: htab_hash_function.c
		$(CC) $(CFLAGS) -c htab_hash_function.c -fPIC -o htab_hash_function.o

tail.o: tail.c
		$(CC) $(CFLAGS) -c tail.c -o tail.o

io.o: io.c
	$(CC) $(CFLAGS) -c io.c -o io.o

clean:
	rm *.o *.a *.so