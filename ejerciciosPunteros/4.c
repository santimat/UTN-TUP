// Maximo de un array

#include <stdio.h>

int max(int *arr, int size)
{
    int max = 0;
    printf("direccion de memoria antes: %p\n", arr);
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) > max)
        {
            max = *(arr + i);
        }
    }
    printf("direccion de memoria despuesw: %p\n", arr);

    return max;
}

int main()
{
    int size = 10;
    int arr[] = {1, 2, 3, 4, 5, 60, 7, 8, 9, 10};
    int maxNumber = max(arr, size);

    printf("El numero maximo es %d", maxNumber);
}