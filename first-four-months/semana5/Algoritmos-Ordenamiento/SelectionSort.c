#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillMatrix(int size, int nums[])
{
    for (int i = 0; i < size; i++)
    {
        nums[i] = rand() % 101;
    }
}

void showMatrix(int size, int nums[], int option)
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

void selectionSort(int size, int nums[])
{
    // el primer bucle va a hasta size - 1, porque el siguiente lo revisamos con el bucle interno
    for (int i = 0; i < size - 1; i++)
    {
        // almacenamos el indice, va a ser i ya que a medida que ordenamos vamos a dejar de revisar los ya acomodados
        int min_idx = i;
        // j arranca en i + 1, porque vamos colocando los menores al principio, entonces no se necesita revisar 2 veces
        for (int j = i + 1; j < size; j++)
        {
            // si el de la izquierda es mayor al de la derecha
            if (nums[min_idx] > nums[j])
            {
                // guardamos el indice del numero mas chico
                min_idx = j;
            }
        }

        // si el indice del numero mas chico no cambió significa que no tenemos que modificar nada
        if (min_idx != i)
        {
            // almacenamos el numero más pequeño de forma tempora
            int temp = nums[min_idx];
            // intercambios los numeros
            nums[min_idx] = nums[i];
            nums[i] = temp;
        }

        printf("Iteracion %d\n", i + 1);
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
    fillMatrix(size, numbers);
    showMatrix(size, numbers, 1);
    selectionSort(size, numbers);
    showMatrix(size, numbers, 0);
    return 0;
}