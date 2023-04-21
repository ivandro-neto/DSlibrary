#pragma once
#include "item.h"
#include "messeges.h"

typedef struct queue
{
    Item *item;
    struct queue *next;
} Queue;

Queue *InitQueue();
Queue *addItemToQueue(Item *, Queue *);
Queue *removeItemFromQueue(Queue *);
void printQueue(Queue *);
