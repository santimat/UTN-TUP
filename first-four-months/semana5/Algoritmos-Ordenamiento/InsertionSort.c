#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArr(int size, int nums[])
{
    for (int i = 0; i < size; i++)
    {
        nums[i] = rand() % 100 + 1;
    }
}

void showArray(int size, int nums[], int option)
{
    if (option == 1)
    {
        printf("Array original\n");
    }
    else
    {
        printf("Array ordenado\n");
    }
    for (int i = 0; i < size; i++)
    {
        printf("%5d", nums[i]);
    }
    printf("\n");
}

// Basicamente lo que hacemos con el selection sort es colocar el numero en su lugar correcto e ir desplazando desde esa posicion para la derecha los numeros que le siguen por ejemplo
// Vamos comparando el elemento de la izquierda con el de la derecha, en caso de que el de la izquierda sea mayor, este se desplaza a la derecha dejando el lugar, luego se compara el mismo con el derecha, si este es menor que el de siguiente se vuelde a desplazar, sino se deja ahi
// [1, 2, 10, 3]
// [1, 2, _, 10]
// [1, 2, 3, 10]
void insertionSort(int size, int nums[])
{
    // i arranca en 1 porque asumimos que el primero ya está ordenado
    for (int i = 1; i < size; i++)
    {
        // guardamos el valor en la posicion i
        int key = nums[i];
        int j = i - 1;

        // mientras j sea mayor igual a 0, para evitar errores porque no podemos acceder al indice -1
        // y mientras que el numero de la izquierda sea mayor al de la derecha
        while (j >= 0 && nums[j] > key)
        {
            // desplazamos el numero a la derecha
            nums[j + 1] = nums[j];
            j--;
        }
        // Ponemos el valor en la posicion i, en la posicion de j + 1 que sería la posicion correcta
        nums[j + 1] = key;

        printf("Array en la pasada %d\n", i);

        for (int k = 0; k < size; k++)
        {
            printf("%5d", nums[k]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    int size = 10;
    int numbers[size];
    fillArr(size, numbers);
    showArray(size, numbers, 1);
    insertionSort(size, numbers);
    showArray(size, numbers, 0);
    return 0;
}