#include <stdio.h>
#include <stdlib.h> // <- importante para poder hacer uso de malloc()

typedef struct Node
{
    // dato
    int num;
    // Puntero al siguiente
    struct Node *sig;
} Node;

// retorna un puntero hacia un nodo
Node *createNode(int value)
{
    // puntero a un nuevo nodo
    // Se castea el resultado ya que malloc retorna un puntero generico (void *), de esta forma hacemos que el puntero que retorne apunte a un tipo de dato nodo
    // asignamos el espacio de memoria en tiempo de ejecucion con malloc
    // le pasamos el tamaño que va a ocupar la estructura Node
    Node *newNode = (Node *)malloc(sizeof(Node));

    // si malloc, retorna null es porque no se pudo asignar la memoria
    if (newNode == NULL)
    {
        printf("Error: no se pudo asignar memoria para el nuevo puntero");
        exit(1);
    }

    // En caso de que si se haya reservado la memoria
    newNode->num = value; // <- almacenamos el dato

    newNode->sig = NULL; // inicializamos el puntero en nulo, porque no sabemos si va a tener un siguiente

    return newNode;
}

// Head sería el primer elemento de la lista, es decir el punto de partidad desde donde comenzamos a leer nuestra lista, se pasa como puntero a un puntero, porque queremos poder modificar su valor en caso de que el valor que vayamos a ingresar sea el primero
void insertLast(Node **head, int value)
{
    // Creamos el nuevo nodo que vamos a insertar
    Node *newNode = createNode(value);

    // revisamos que si no hay elementos en la lista
    if (*head == NULL)
    {
        // añadimos el nuevo nodo al principio
        *head = newNode;
        return;
    }

    // En caso de que no sea el primer elemento de la lista, hay que iterar para buscar el ultimo
    // puntero para iterar
    Node *temp = *head;

    // iteramos hasta que el puntero al siguiente sea nulo, es decir el ultimo elemento de la lista
    while (temp->sig != NULL)
    {
        // almacenamos el puntero del ultimo elemento de la lista
        temp = temp->sig; // <- al asignar a la variable de esta forma, no estamos modificando como tal la lista original
    }

    // ahora si guardamos el nuevo puntero al final
    temp->sig = newNode; // al usar -> estamos modificando la lista original
}

Node *getOddList(Node *head)
{
    Node *l1 = NULL; // <- nueva lista con los valores impares

    Node *temp = head; // <- variable temporal para iterar la lista principal
    while (temp != NULL)
    {
        // si el dato es impar
        if (temp->num % 2 != 0)
        {
            // insertamos a lo ultimo de la nueva lista, el dato
            insertLast(&l1, temp->num); // <- l1, pasa con &, ya que inserlast trabaja con un puntero a un puntero
        }
        // movemos al siguiente elemento de la lista
        temp = temp->sig;
    }

    return l1;
}

void showList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->num);
        temp = temp->sig;
    }
    printf("Fin\n");
}

int main()
{
    Node *mainList = NULL;
    insertLast(&mainList, 3);
    insertLast(&mainList, 8);
    insertLast(&mainList, 15);
    insertLast(&mainList, 22);
    insertLast(&mainList, 7);
    insertLast(&mainList, 10);
    insertLast(&mainList, 5);
    insertLast(&mainList, 14);
    insertLast(&mainList, 1);
    insertLast(&mainList, 9);
    printf("Lista original\n");
    showList(mainList);

    // Obtener nueva lista solo con los valores impares
    Node *oddList = getOddList(mainList);
    printf("Lista de impares\n");
    showList(oddList);
    return 0;
}