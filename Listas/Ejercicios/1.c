#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Nodo
{
    int NumsEnPositivos;
    struct Nodo *sig;
} Nodo;

void *crearNodo(int valor)
{
    // reservo espacio de memoria
    // casteo a puntero de nodo struct
    // asigno a un nuevo struct
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));

    if (nuevoNodo == NULL)
    {
        printf("Error: no se pudo asignar la memoria correctamente\n");
        exit(1);
    }

    nuevoNodo->NumsEnPositivos = valor;
    nuevoNodo->sig = NULL;

    return nuevoNodo;
}

void insertarAlFinal(Nodo **cabeza, int valor)
{

    // Puntero al nuevo nodo
    Nodo *nuevoNodo = crearNodo(valor);

    // si la lista estaba vacia
    if (*cabeza == NULL)
    {
        // asignamos el nuevo nodo al primer puntero
        *cabeza = nuevoNodo;
        return;
    }

    // Encontrar el ultimo nodo
    Nodo *temp = *cabeza; // <- creamos un puntero al primer puntero para iterar

    // cuando este while termine en temp tendremos el puntero del ultimo nodo
    while (temp->sig != NULL)
    {
        // guardamos el puntero
        temp = temp->sig;
    }
    temp->sig = nuevoNodo; // <- asignamos al siguiente del que antes era el ultimo puntero, el nuevo puntero
}

void mostrarLista(Nodo *cabeza)
{
    Nodo *actual = cabeza;
    if (actual == NULL)
    {
        printf("La lista está vacia\n");
        return;
    }

    printf("Lista:\n");
    while (actual != NULL)
    {
        printf("%d -> ", actual->NumsEnPositivos);
        actual = actual->sig;
    }
    printf("Fin\n");
}

void mostrarMayores100(Nodo *cabeza)
{
    Nodo *actual = cabeza;
    if (actual == NULL)
    {
        printf("La lista está vacia\n");
        return;
    }

    while (actual != NULL && actual->NumsEnPositivos > 100)
    {
        printf("%d -> ", actual->NumsEnPositivos);
        actual = actual->sig;
    }
    printf("Fin\n");
}

int main()
{
    Nodo *lista = NULL;
    srand(time(NULL));
    insertarAlFinal(&lista, rand() % 201);
    insertarAlFinal(&lista, rand() % 201);
    insertarAlFinal(&lista, rand() % 201);
    insertarAlFinal(&lista, rand() % 201);

    mostrarLista(lista);
    printf("Mayores de 100 en la lista:\n");
    mostrarMayores100(lista);
}