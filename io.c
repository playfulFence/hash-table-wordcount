// io.c
// Řešení IJC-DU2, příklad 2, 19.4.2021
// Autor: Kirill Mikhailov, FIT
// Přeloženo: Apple Clang version 12.0.0


#include <stdio.h>
#include <ctype.h> // for isspace
#include <stdbool.h>

/* Implementation limit of maximum length of word we can read */
#define MAX_WORD 127

/* This function reads single words from file. It's useful for our wordcount.c */
int read_word(char *s, int max, FILE* f)
{
    int fileChar;
    int charsWritten = 0;
    bool excessFlag = false; /* Will be true if MAX_WORD limit will be exceeded */

    while ((fileChar = fgetc(f)) != EOF)
    {
        if(isspace(fileChar))   /* if our readed char is space(or newline, or tab and so on, check isspace() reference) it breaks the cycle */
        {
            if (charsWritten == 0) continue;
            else break;
        }

        /* if word is longer, than MAX_WORD of words and excessFlag is still "false", it will print warning,
         *      but only one time, next time it will be ignored*/
        if((charsWritten >= (MAX_WORD - 1)) && (!excessFlag))
        {
            fprintf(stderr, "WARNING: You trying to read too long word!");
            excessFlag = true;
        }

        if (charsWritten < max - 1) s[charsWritten++] = fileChar;
    }

    /* Writes terminating sign at the end of array */
    if(charsWritten != 0) s[charsWritten] = '\0';

    /* If readed char is EOF(-1), returns EOF, IZI */
    if (fileChar == EOF) return EOF;

    return charsWritten;
}

