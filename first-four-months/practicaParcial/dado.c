// Pide al usuario cuántas veces quiere lanzar un dado virtual.
// Utiliza un bucle for para simular los lanzamientos (generando números aleatorios entre 1 y 6).
// Muestra el resultado de cada lanzamiento.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tirarDado(int lanzamientos);
void pedirLanzamientos(int lanzamientos);


int main()
{
    srand(time(NULL));

    int lanzamientos = 0;
    printf("Ingrese la cantidad de veces que desea lanzar el dado\n");
    scanf("%d", &lanzamientos);
    tirarDado(lanzamientos);
    return 0;
}

void tirarDado(int lanzamientos)
{
    for (int i = 0; i < lanzamientos; i++)
    {
        printf("En el #%d tiro salio el numero %d\n", i + 1, rand() % 6 + 1);
    }
}