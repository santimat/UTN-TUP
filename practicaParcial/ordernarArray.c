// Ordenar un Array (Burbuja Simple):
// Declara un array de 10 números enteros inicializados directamente en el código (desordenados).
// Implementa el algoritmo de ordenamiento burbuja para ordenar el array de forma ascendente.
// Muestra el array original y el array ordenado.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializarArray(int nums[], int largo);
void ordenarArray(int nums[], int largo);
void mostrarArray(int nums[], int largo);

int main()
{
    srand(time(NULL));
    int largo = 10;
    int nums[largo];
    inicializarArray(nums, largo);
    printf("Array original\n");
    mostrarArray(nums, largo);

    ordenarArray(nums, largo);

    printf("Array ordenado\n");
    mostrarArray(nums, largo);

    return 0;
}

void inicializarArray(int nums[], int largo)
{
    for (int i = 0; i < largo; i++)
    {
        nums[i] = rand() % 100 + 1;
    }
}

void ordenarArray(int nums[], int largo)
{
    for (int i = 0; i < largo; i++)
    {
        for (int j = 0; j < largo - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

void mostrarArray(int nums[], int largo)
{
    for (int i = 0; i < largo; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}