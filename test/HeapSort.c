#include <stdio.h>
#include <stdlib.h>
#include "../library/data_structure.h"

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}
void swap(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}
void min_heapify(int arr[], int size, int current)
{
    int smallest = current;
    int left = 2 * current + 1;
    int right = 2 * current + 2;

    // Encontra o menor elemento entre o nó atual e seus filhos esquerdo e direito
    if (left < size && arr[left] < arr[smallest])
        smallest = left;

    if (right < size && arr[right] < arr[smallest])
        smallest = right;

    // Se o nó atual não for o menor, troca ele com o menor e chama heapify recursivamente para o subárvore afetada
    if (smallest != current)
    {
        swap(&arr[current], &arr[smallest]);

        min_heapify(arr, size, smallest);
    }
}

void heapify(int arr[], int size, int current)
{
    // primeiramente, localiza-se os elementos da esquerda e direita
    int largest = current;       // Inicialmente o maior valor será sempre o elemento raiz
    int left = 2 * current + 1;  // fórmula para achar o elemento esquerdo da árvore
    int right = 2 * current + 2; // fórmula para achar o elemento direito da árvore

    // Verifica-se se o indíce do elemento esquerdo está dentro do array e se o seu valor é maior que o maior valor
    if (left < size && arr[left] > arr[largest])
        largest = left;

    // Verifica-se se o indíce do elemento direito está dentro do array e se o seu valor é maior que o maior valor
    if (right < size && arr[right] > arr[largest])
        largest = right;

    // Verifica-se se o elemento selecionado se é o maior também
    if (current != largest)
    {
        // Caso não for os troque
        swap(&arr[largest], &arr[current]);
        // Depois pega o maior como o selecionado da próxima verificação
        printArray(arr, size);

        heapify(arr, size, largest);
    }
}
void MaxHeap(int arr[], int size)
{
    // Começando pelo último nó não-folha, chama heapify para cada nó em ordem reversa de nível para garantir um max heap válido
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);
}
void MinHeap(int arr[], int size)
{
    // Começando pelo último nó não-folha, chama heapify para cada nó em ordem reversa de nível para garantir um min heap válido
    for (int i = size / 2 - 1; i >= 0; i--)
        min_heapify(arr, size, i);
}
void HeapSort(int arr[], int size)
{
    // Gera um max heap apartir do array dado.
    MaxHeap(arr, size);
    /*
        Para min heap comenta a linha à cima e descomenta a linha abaixo
    */
    // MinHeap(arr, size);

    // Heap Sort
    for (int i = size - 1; i >= 0; i--)
    {
        // Troca a posição do primeiro elemento com o último do array
        swap(&arr[0], &arr[i]);
        // Elimina o último elemento e volta a reorganiza-los até sobrar um único elemento
        heapify(arr, i, 0);
        /*
            Para min heap comenta a linha à cima e descomenta a linha abaixo
        */
        // min_heapify(arr, i, 0);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 12, 9, 5, 6, 10, 20};
    int size = sizeof(arr) / sizeof(arr[0]); // Obtendo o tamanho do array
    printArray(arr, size);
    HeapSort(arr, size);
    printArray(arr, size);
    // OUTPUT::1 5 6 9 10 12 20
    return 0;
}
