#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "phonebook_hash.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *e[])
{
    unsigned int idx = BKDRHash(lastName);
    entry *tmp = e[idx];

    while (tmp)
    {
        if (strcasecmp(lastName, tmp->lastName) == 0)
            return tmp;
        tmp = tmp->pNext;
    }

    return NULL;
}

void append(char lastName[], entry *e[])
{
    unsigned int idx = BKDRHash(lastName);
    entry *tmp = e[idx];

    tmp->pNext = (entry *)malloc(sizeof(entry));
    tmp = tmp->pNext;

    strcpy(tmp->lastName, lastName);
    tmp->pNext = NULL;

    e[idx] = tmp;
}

unsigned int BKDRHash(char *str)
{
    unsigned int hash = 0;

    while (*str)
    {
        hash = (hash<<5) - hash + (*str++);
    }

    return (hash % SIZE);
}
