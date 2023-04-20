#include "..\library\data_structure.h"

int main(int argc, char const *argv[])
{
 
    List *list = InitList();

    list = insertItemTo(createItem(10), list);
    list = insertItemTo(createItem(12), list);
    list = insertItemTo(createItem(120), list);
    printList(list);

    return 0;
}
