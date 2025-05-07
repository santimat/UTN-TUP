#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declaramos el puntero
    int *ptr;

    // Asignar memoria dinámica
    // (int *) es para indicar que ptr es un puntero a enteros
    ptr = (int *)malloc(5 * sizeof(int)); // Reserva memoria para 5 enteros

    if (ptr == NULL)
    {
        printf("No se pudo reservar memoria\n");
        return 1; // Indica que hubo un error
    }

    // Arreglo con valores
    for (int i = 0; i < 5; i++)
    {
        ptr[i] = (i + 1) * 10; // 10, 20, 30, 40, 50
    }

    // Imprimimos los valores
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", ptr[i]);
    }

    // Liberamos la memoria
    free(ptr); // <- de esta forma evitamos leaks (memoria no liberada)

    return 0;
}