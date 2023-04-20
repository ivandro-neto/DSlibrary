#pragma once

typedef struct item
{
    double value;
    struct item *next;
} Item;

extern Item *createItem(int);

