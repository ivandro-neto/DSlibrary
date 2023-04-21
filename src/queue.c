#include "../includes/queue.h"
#include "../includes/messeges.h"
#include <stdlib.h>
#include <stdio.h>

Queue *InitQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->next = queue->item = NULL;
    return queue;
}

Queue* addItemToQueue(Item *item, Queue *queue)
{
    Queue *new_queue = InitQueue();

    if (new_queue->next == NULL)
    {
        new_queue->item = item;
        new_queue->next = NULL;
    }else{
        new_queue->item = item;
        new_queue->next = queue;
    }
    return new_queue;
}

Queue* removeItemFromQueue(Queue *queue)
{
    Queue *temp = queue;
    queue = queue->next;
    free(temp);
    return queue; 
}

void printQueue(Queue *queue)
{
}
