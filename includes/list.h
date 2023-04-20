#pragma once
#include "item.h"
//Types
typedef int position;
typedef struct list List;
typedef int Bool;

//Methods0
extern List* InitList();
extern int createEmptyList(List);
extern List* insertItemTo(Item*, List*);
extern void removeItemFrom(List*);
extern Item getItemFrom(position, List*);
extern void printList(List*);

/* Bool */ void isHeavyThan(List*);

