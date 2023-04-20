#include "../library/data_structure.h"
#include <stdio.h>

int main()
{
    int array[11] = {24, 66, 71, 13, 17, 23, 49, 31, 37, 82, 11};
    int size = sizeof(array) / sizeof(array[0]);

    struct BinaryTree *tree = InitTree();
    /* AddNode(tree, 24);
    AddNode(tree, 66);
    AddNode(tree, 71);
    AddNode(tree, 13);
    AddNode(tree, 17);
    AddNode(tree, 23);
    AddNode(tree, 49);
    AddNode(tree, 31);
    AddNode(tree, 37);
    AddNode(tree, 82);
    AddNode(tree, 11); */
    AddNodeArray(tree, array, size);

    PreOrderTransversal(tree->root);
    sms("\n");
    InOrderTransversal(tree->root);
    sms("\n");
    PostOrderTransversal(tree->root);
    sms("\n");

    deleteNodeTree(tree, 17);

    PreOrderTransversal(tree->root);
    sms("\n");
    InOrderTransversal(tree->root);
    sms("\n");
    PostOrderTransversal(tree->root);
    sms("\n");
    
    deleteNodeTree(tree, 17);
    return 0;
}