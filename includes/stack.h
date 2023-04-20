#pragma once

#include "item.h"

typedef struct stack
{
    Item *top;
    struct stack *next;
} Stack;


extern Stack* startStack();
extern Stack *Push(Stack *, Item *);
extern void Pop(Stack *);
extern Stack *freeStack(Stack *);
extern void printStack(Stack *);
