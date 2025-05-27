#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int NumsEPositivos;
    struct Nodo *sig; // <- puntero siguiente, estructura recursiva
} Nodo;

Nodo *crearNodo(int valor)
{
    // se reserva memoria para el nuevo nodo
    // malloc reserva la memoria, con sizeof(Nodo) calculamos el espacio en bytes que ocupa la estructura Nodo
    // luego se castea para que sea un puntero de la estructura Nodo
    // se asigna a la variable nuevoNodo, que va ser un puntero a una estructua de tipo Nodo
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));

    if (nuevoNodo == NULL)
    {
        printf("Error: no se puedo asignar memoria para el nodo\n");
        exit(1);
    }

    // Inicializar el nodo con el valor dado
    nuevoNodo->NumsEPositivos = valor; // <- guardamos el valor ingresado
    nuevoNodo->sig = NULL;             // hacemos que este nodo sea el ultimo

    return nuevoNodo;
}

void insertarAlFinal(Nodo **cabeza, int valor)
{
    // Creo nuevo nodo
    Nodo *nuevoNodo = crearNodo(valor);

    // Si la lista esta vacía el nuevo nodo será la cabeza, es decir el primero
    if (*cabeza == NULL)
    {
        *cabeza = nuevoNodo;
        return;
    }

    // Encontrar el ultimo
    Nodo *temp = *cabeza;

    // recorremos hasta conseguir el puntero del ultimo elemento
    while (temp->sig != NULL)
    {
        // almacenamos el puntero del ultimo elemento de la lista
        temp = temp->sig;
    }

    // Insertar el nuevo nodo al final de la lista
    temp->sig = nuevoNodo;
}

void insertarAlInicio(Nodo **cabeza, int valor)
{
    // Crear nuevo nodo
    Nodo *nuevoNodo = crearNodo(valor);

    // El sigueinte del nuevo nodo será la cabeza actual
    nuevoNodo->sig = *cabeza;

    // La nueva cabeza (el primero), será el nuevo nodo
    *cabeza = nuevoNodo;
}

int buscar(Nodo *cabeza, int valor)
{
    Nodo *actual = cabeza;

    while (actual != NULL)
    {
        // Si lo encuentra retornamos 1
        if (actual->NumsEPositivos == valor)
        {
            return 1;
        }
        actual = actual->sig;
    }

    // Si no se encuentra el valor
    return 0;
}

int eliminar(Nodo **cabeza, int valor)
{
    // Si el valor esta en la cabeza
    if (*cabeza == NULL)
    {
        return 0;
    }

    // Si el valor esta en la cabeza
    if ((*cabeza)->NumsEPositivos == valor)
    {
        // Creamos un nodo temporal
        Nodo *temp = *cabeza; // <- temp va a tener el puntero al primero (cabeza)

        // La cabeza pasa a ser el siguiente del que eliminamos
        *cabeza = (*cabeza)->sig;
        free(temp); // <- limpiamos el espacio de memoria donde estaba el que queremos eliminar
        return 1;
    }

    // Buscar el nodo
    Nodo *actual = *cabeza;

    // Actual seria el puntero del anterior al que estamos revisando
    // Mientras el puntero del siguiente no sea nulo y el valor no sea el que estamos buscando seguimos iterando
    while (actual->sig != NULL && actual->sig->NumsEPositivos != valor)
    {
        // Aca nos va a quedar el puntero a la estructura que queremos eliminar
        actual = actual->sig;
    }

    // Si se encontró el valor
    if (actual->sig != NULL)
    {
        // creamos un temporal al siguiente del puntero con la estructura que queremos eliminar
        Nodo *temp = actual->sig;

        // actualizamos el siguiente para que sea el siguiente al que vamos a eliminar, asi no rompemos la lista
        actual->sig = temp->sig;

        free(temp); // <- limpiamos el espacio de memoria de la estrcutura que queriamos eliminar
        return 1;
    }

    // Si se llega aca es porque no se encontró el valor
    return 0;
}

void imprimirLista(Nodo *cabeza)
{
    Nodo *actual = cabeza;

    if (actual == NULL)
    {
        printf("la lista esta vacia\n");
        return;
    }

    printf("Lista:\n");
    while (actual != NULL)
    {
        printf("%d -> ", actual->NumsEPositivos);
        actual = actual->sig;
    }

    printf("Fin\n");
}

void liberarLista(Nodo **cabeza)
{
    Nodo *actual = *cabeza;
    Nodo *sig;

    // Liberar cada uno
    while (actual != NULL)
    {
        // almacenamos el puntero al siguiente
        sig = actual->sig;
        free(actual); // <- limpiamos el espacio de memoria
        actual = sig; // <- actualizamos la variable con la que estamos iterando
    }

    // Establecer la cabeza como null
    *cabeza = NULL;
}

int main()
{
    Nodo *lista = NULL; // inicializar lista vacia
    insertarAlFinal(&lista, 20);
    insertarAlFinal(&lista, 40);
    insertarAlFinal(&lista, 60);
    insertarAlFinal(&lista, 100);

    imprimirLista(lista);

    printf("El valor 20 esta en la lista? %s\n", buscar(lista, 20) ? "Si" : "No");
    printf("El valor 50 esta en la lista? %s\n", buscar(lista, 50) ? "Si" : "No");

    printf("Eliminando el 20...\n");
    eliminar(&lista, 20);
    imprimirLista(lista);

    // Liberar memoria
    liberarLista(&lista);
    printf("Memoria liberada\n");

    return 0;
}