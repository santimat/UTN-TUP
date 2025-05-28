#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int nums;
    Node *sig;
} Node;

Node *createNode(int value)
{
    // Reservo espacio de memoria para el nuevo nodo
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Error: no se pudo asignar memoria para el nodo\n");
        exit(1);
    }

    newNode->nums = value;
    newNode->sig = NULL;

    return newNode;
}

void insertLast(Node **head, int value)
{
    Node *newNode = createNode(value);

    // si no hay elementos en la lista
    if (*head == NULL)
    {
        // añadimos al primero
        *head = newNode;
    }

    // en caso de que haya elementos en la lista buscamos el ultimo
    Node *temp = *head;
    while (temp != NULL)
    {
        // temp va a almacenar el puntero hacia el ultimo elemento de la lista
        temp = temp->sig;
    }

    // insertar al final el nuevo nodo
    temp->sig = newNode;
}

int main()
{
    Node *list = NULL;
    return 0;
}