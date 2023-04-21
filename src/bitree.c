#include "../includes/bitree.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "../includes/messeges.h"

static int ValueExist(struct node *root, int data)
{
    if (root != NULL)
    {
        if (data < *(int *)root->data)
            ValueExist(root->left, data);
        else if (data > *(int *)root->data)
            ValueExist(root->right, data);
        else if (data == *(int *)root->data)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

struct node *newNode(int data)
{
    struct node *newData = (struct node *)malloc(sizeof(struct node));
    if (newData == NULL)
        sms(ERROR_ALLOCATION);

    // converte o valor rebido em int para o tipo vazio
    int *data_prt = (int *)malloc(sizeof(int));
    if (data_prt == NULL)
        sms(ERROR_ALLOCATION);

    *data_prt = data;

    newData->data = (void *)data_prt;
    newData->left = newData->right = NULL;
    return newData;
}

struct BinaryTree *InitTree()
{
    struct BinaryTree *Bitree = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
    if (Bitree == NULL)
        sms(ERROR_ALLOCATION);

    Bitree->root = NULL;
    return Bitree;
}

static struct node *AddNodeRecursive(struct node *root, int data)
{
    struct node *newData = newNode(data);

    if (root == NULL)
        root = newData;
    else
    {
        if (data > *(int *)root->data)
            root->right = AddNodeRecursive(root->right, data);
        else
            root->left = AddNodeRecursive(root->left, data);
    }

    return root;
}

void AddNode(struct BinaryTree *tree, int data)
{
    tree->root = AddNodeRecursive(tree->root, data);
}

void AddNodeArray(struct BinaryTree *tree, int *array, int size)
{

    for (size_t i = 0; i < size; i++)
    {
        AddNode(tree, array[i]);
    }
    sms(S_ADDED);
}

static struct node *deleteNode(struct node *root, int data_key)
{

    if (root == NULL)
        return root;

    if (data_key < *(int *)root->data)
        root->left = deleteNode(root->left, data_key);

    else if (data_key > *(int *)root->data)
        root->right = deleteNode(root->right, data_key);

    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        root->data = findSuccessor(root, data_key)->data;

        root->right = deleteNode(root->right, *(int *)findSuccessor(root, data_key)->data);
    }

    return root;
}
struct node *findSuccessor(struct node *root, int data_key)
{
    struct node *new_successor = root->right;

    while (new_successor && new_successor->left != NULL)
    {
        new_successor = new_successor->left;
    }
    return new_successor;
}
struct node *findPredSuccessor(struct node *root, int data_key)
{
    struct node *new_successor = root->right;

    while (new_successor && new_successor->right != NULL)
    {
        new_successor = new_successor->right;
    }
    return new_successor;
}

void deleteNodeTree(struct BinaryTree *tree, int key)
{
    if (ValueExist(tree->root, key) == 1)
    {
        deleteNode(tree->root, key);
        sms(S_DELETE);
    }
    else
    {
        sms(ERROR_DOESNTEXIST);
    }
}

void PreOrderTransversal(struct node *focusNode)
{
    if (focusNode != NULL)
    {
        printf("%d -> ", *(int *)focusNode->data);
        PreOrderTransversal(focusNode->left);
        PreOrderTransversal(focusNode->right);
    }
}
void InOrderTransversal(struct node *focusNode)
{
    if (focusNode != NULL)
    {
        PreOrderTransversal(focusNode->left);
        printf("%d -> ", *(int *)focusNode->data);
        PreOrderTransversal(focusNode->right);
    }
}
void PostOrderTransversal(struct node *focusNode)
{
    if (focusNode != NULL)
    {
        PreOrderTransversal(focusNode->left);
        PreOrderTransversal(focusNode->right);
        printf("%d -> ", *(int *)focusNode->data);
    }
}
void Maximum(struct node *focusNode)
{
    if (focusNode != NULL)
    {
        Maximum(focusNode->right);
    }
    printf("%d -> ", *(int *)focusNode->data);
}
void Minimum(struct node *focusNode)
{
    if (focusNode != NULL)
    {
        Minimum(focusNode->left);
    }
    printf("%d -> ", *(int *)focusNode->data);
}