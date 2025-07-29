// Acceso a array con punteros

#include <stdio.h>

int main()
{
    int nums[5] = {10, 20, 30, 40, 50};
    int *puntero = nums;
    for (int i = 0; i < 5; i++)
    {
        printf("%5d", *(puntero + i));
    }
}