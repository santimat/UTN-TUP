#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int elem;
    datosEnteros *sig;
} datosEnteros;

void recorrerLista(datosEnteros *pl)
{
    datosEnteros *aux = pl;

    while (aux != NULL)
    {
        printf("%d", aux->elem);
        aux = aux->sig; // <- movemos el puntero, para imprimir el siguiente
    }
}

int main()
{
    return 0;
}