#ifndef BITREE_H
#define BITREE_H
#include "messeges.h"
// BinaryTree implementation

struct node
{
    // Tipo de dados
    /*
        Neste caso irá se usar o tipo inteiro
        Mas pode se utilizar qualquer tipo
        ORIGINAL : void *data;
    */
   
    void *data;
    //The Methods above was modified to recieve integers, so you don't need to uncomment this anymore
    // int data;

    // Ramificações
    struct node *left, *right;
};

struct BinaryTree
{
    // A raiz da árvore
    struct node *root;
};


struct node *newNode(int);

struct BinaryTree *InitTree();

static struct node *AddNodeRecursive(struct node *, int);
static struct node *deleteNode(struct node *, int);

void AddNode(struct BinaryTree *, int);
void AddNodeArray(struct BinaryTree *, int *, int);

void deleteNodeTree(struct BinaryTree *, int);

void PreOrderTransversal(struct node *);
void InOrderTransversal(struct node *);
void PostOrderTransversal(struct node *);
#endif