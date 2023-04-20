#include <stdio.h>
#include <stdlib.h>
#include "..\includes\list.h"
#include "..\includes\messeges.h"
#include "../includes/item.h"

#define MAX_SIZE 10

// Types

typedef int Bool;
typedef int position;

typedef struct list
{
    Item *items;
    int size;
    struct list *next;
} List;

// Methods
List *InitList()
{
    List *empty = (List *)malloc(sizeof(List));
    empty->next = NULL;
    empty->size = 0;
    empty->items = NULL;
    return empty;
}

List *isEmptyList(List *list)
{
    return list;
}

List *insertItemTo(Item *item, List *list)
{
    Item *temp = (Item *)malloc(sizeof(Item));
    List *newlist = (List *)malloc(sizeof(List));

    if (list != NULL && list->size >= MAX_SIZE)
    {
        sms(ERROR_FULL_LIST);
        exit(1);
    }
    else
    {
        if (list == NULL)
        {
            temp->value = item->value;
            temp->next = NULL;
            newlist->size = 1;
            newlist->items = temp;
            sms(S_ALLOCATION);
        }
        else
        {
            temp->value = item->value;
            temp->next = list->items;
            newlist->size = list->size;
            newlist->items = temp;
            newlist->size++;
            sms(S_NEW_ALLOCATION);
        }
    }
    return newlist;
}

void removeItemFrom(List *list)
{
    Item *item = list->items;

    list->items = item->next;
    list->size--;

    free(item);
    sms(S_UPDATING);
}

Item getItemFrom(position pos, List *list)
{
    return list->items[pos];
}

void printList(List* list)
{
    List aux = *list;

    printf("PRINTING LIST...\n\n");
    while (aux.items != NULL)
    {
        printf("%.2f\n\n", aux.items->value);
        aux.items = aux.items->next;
    }

    sms(S_PRINT_LIST);
}

void isHeavyThan(List *list)
{
    for (Item *i = list->items; i != NULL; i = i->next)
    {
        for (Item *j = list->items; j->next != NULL; j = j->next)
        {
            if (j->value > j->next->value)
            {
                int value = j->value;
                j->value = j->next->value;
                j->next->value = value;
            }
        }
    }
}