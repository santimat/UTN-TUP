#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int nums;
    struct Nodo *sig;
} Nodo;

Nodo *crearNodo(int valor)
{
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));

    if (nuevoNodo == NULL)
    {
        printf("Error: no se pudo asignar la memoria correctamente");
        exit(1);
    }

    nuevoNodo->nums = valor;
    nuevoNodo->sig = NULL;
}

void insertarAlFinal(Nodo **cabeza, int valor)
{
    Nodo *nuevoNodo = crearNodo(valor);

    if (*cabeza == NULL)
    {
        *cabeza = nuevoNodo;
        return;
    }

    // Buscar ultimo nodo
    Nodo *temp = *cabeza;
    while (temp->sig != NULL)
    {
        temp = temp->sig;
    }

    temp->sig = nuevoNodo;
}

Nodo *listaImpares(Nodo *cabeza)
{
    Nodo *actual = cabeza;
    Nodo *lista2 = NULL;

    while (actual != NULL && actual->nums % 2 != 0)
    {
        insertarAlFinal(&lista2, actual->nums);
        actual = actual->sig;
    }
    return lista2;
}

void mostrarLista(Nodo *cabeza)
{
    Nodo *actual = cabeza;
    if (actual == NULL)
    {
        printf("La lista esta vacia\n");
        return;
    }

    while (actual != NULL)
    {
        printf("%d -> ", actual->nums);
        actual = actual->sig;
    }
    printf("Fin\n");
}

int main()
{
    Nodo *lista = NULL;
    insertarAlFinal(&lista, 3);
    insertarAlFinal(&lista, 8);
    insertarAlFinal(&lista, 15);
    insertarAlFinal(&lista, 22);
    insertarAlFinal(&lista, 7);
    insertarAlFinal(&lista, 14);
    insertarAlFinal(&lista, 9);
    insertarAlFinal(&lista, 2);
    insertarAlFinal(&lista, 11);
    insertarAlFinal(&lista, 18);
    insertarAlFinal(&lista, 5);
    insertarAlFinal(&lista, 12);
    insertarAlFinal(&lista, 17);
    insertarAlFinal(&lista, 20);
    insertarAlFinal(&lista, 1);
    insertarAlFinal(&lista, 6);
    insertarAlFinal(&lista, 13);
    insertarAlFinal(&lista, 4);
    insertarAlFinal(&lista, 19);
    insertarAlFinal(&lista, 10);

    Nodo *lista2 = listaImpares(lista);
    mostrarLista(lista2);
    return 0;
}