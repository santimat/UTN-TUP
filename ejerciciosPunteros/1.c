// Intercambio de valores

#include <stdio.h>

void swapNumbers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 5;
    int b = 10;

    printf("Antes del swap a = %d y b = %d\n", a, b);
    swapNumbers(&a, &b);
    printf("Despues del swap a = %d y b = %d\n", a, b);
    return 0;
}