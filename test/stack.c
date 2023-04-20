#include "..\library\data_structure.h"

int main(int argc, char const *argv[])
{

    Item* item = createItem(10); 
    Stack* stack = startStack();

    stack = Push(stack, item);
    printStack(stack);
 
   
   return 0;
}
