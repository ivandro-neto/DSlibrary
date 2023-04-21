#include <stdio.h>
#include <stdlib.h>
#include "..\includes\stack.h"
#include "../includes/item.h"

const int MAX_Stack = 4;
const int MAX_LIST = 2;

Stack* startStack()
{
    return NULL;
}

Stack* Push(Stack* stack,Item* item)
{
        Item* temp = (Item*) malloc(sizeof(Item));
        Stack* newStack = (Stack*) malloc(sizeof(Stack));
        
       
        if (!temp) {
            exit(1);
        }
 
        temp = item;

        if (stack == NULL)
        {
            newStack->top = temp;
            newStack->next = NULL;    
        }
        else
        {
            newStack->top = temp;
            newStack->top->next = stack->top;
        }
     return newStack;
    
}

void Pop(Stack* stack)
{

        if (stack->top == NULL) {
            exit(1);
        }
        else {
            Item* aux = stack->top;
            stack->top = aux->next;
            free(aux);
           
        }

}

Stack* freeStack(Stack* stack)
{
    Stack *temp = stack;
    stack = temp->next;
    free(temp);
    return stack;
}

void printStack(Stack* stack)
{
    for (Item *i = stack->top; i != NULL; i = i->next)
    {
        printf("item value :%.2f\n", i->value);
        
    }
   
}
