// Suma dos numeros usando punteros

#include <stdio.h>

int sumarPunteros(int *punteroA, int *punteroB)
{
    return (*punteroA + *punteroB);
}

int main()
{

    int a = 5;
    int b = 15;

    int *punteroA = &a;
    int *punteroB = &b;

    int suma = sumarPunteros(punteroA, punteroB);
    printf("La suma de los punteros es %d", suma);
    return 0;
}