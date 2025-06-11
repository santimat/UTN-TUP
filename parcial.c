#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int num;
    struct Nodo *sig;
} Nodo;

Nodo *crearNodo(int value)
{
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));

    if (nuevoNodo == NULL)
    {
        exit(1);
    }

    nuevoNodo->num = value;
    nuevoNodo->sig = NULL;

    return nuevoNodo;
}

void insertarFinal(Nodo **head, int value)
{
    Nodo *nuevoNodo = crearNodo(value);

    if (*head == NULL)
    {
        *head = nuevoNodo;
        return 0;
    }

    Nodo *temp = *head;

    while (temp->sig != NULL)
    {
        temp = temp->sig;
    }

    temp->sig = nuevoNodo;
}

void eliminar(Nodo **head, int value)
{

    if (*head == NULL)
    {
        printf("vacia");
        return;
    }

    Nodo *actual = *head;

    while (actual->sig != NULL && actual->sig->num != value)
    {
        actual = actual->sig;
    }

    if (actual->sig != NULL)
    {
        Nodo *temp = actual->sig;

        actual->sig = temp->sig;
        free(temp);
        return 1;
    }
}

void insertarAlInicio(Nodo **head, int value)
{
    Nodo *nuevoNodo = crearNodo(value);

    nuevoNodo->sig = *head;

    *head = nuevoNodo;
}

int main()
{
    Nodo *nodo = NULL;
    insertarFinal(&nodo, 10);
    insertarFinal(&nodo, 20);
    insertarFinal(&nodo, 30);
    insertarFinal(&nodo, 40);
    return 0;
}