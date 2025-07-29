#include <stdio.h>

// tomamos dos numeros y los intercambiamos
void swap(int *x, int *y) // <- punteros
{
    // El * antes de la variable es el operador de desreferenciamiento
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int x = 10;
    int y = 20;

    printf("Antes del swap x = %d y = %d\n", x, y);
    swap(&x, &y);
    printf("Despues del swap x = %d y = %d\n", x, y);
    return 0;
}