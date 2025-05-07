// invertir los elementos de un array

#include <stdio.h>

void invertirArray(int *arr, int size)
{

    int j = size - 1;
    for (int i = 0; i < j; i++)
    {
        int temp = *(arr + i);
        *(arr + i) = *(arr + j);
        *(arr + j) = temp;
        j--;
    }
}

int main()
{
    int size = 5;
    int arr[] = {1, 2, 3, 4, 5};
    invertirArray(arr, size);

    for (int i = 0; i < size; i++)
    {
        printf("%5d", arr[i]);
    }

    return 0;
}