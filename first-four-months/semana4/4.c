#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // <- iniciar semilla

    int numero[20];
    int cuadrado[20];
    int cubo[20];

    printf("Numero\tCuadrado\tCubo\n");
    // // Llenar array de numeros
    for (int i = 0; i < 20; i++)
    {
        numero[i] = rand() % 101;
        cuadrado[i] = numero[i] * numero[i];
        cubo[i] = numero[i] * numero[i] * numero[i];
        printf("%d\t%d\t\t%d", numero[i], cuadrado[i], cubo[i]);
        printf("\n");
    }

    return 0;
}
