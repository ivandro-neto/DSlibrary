#include "../includes/item.h"
#include <stdlib.h>
#include <stdio.h>


Item *createItem(int value){
    Item *ite = (Item*)malloc(sizeof(Item));
    ite->value = value;
    ite->next = NULL;

    return ite;
}