#include <stdio.h>

// UTILS
void copyArray(int size, float copy[], float original[])
{
    for (int i = 0; i < size; i++)
    {
        copy[i] = original[i];
    }
}

// SORTS
void bubbleSort(int size, float notes[])
{
    float copyNotes[size];
    copyArray(size, copyNotes, notes);
    int swaps = 0;
    for (int i = 0; i < size; i++)
    {
        int flag = 0;
        for (int j = 0; j < size - 1; j++)
        {
            if (copyNotes[j] > copyNotes[j + 1])
            {
                float temp = copyNotes[j];
                copyNotes[j] = copyNotes[j + 1];
                copyNotes[j + 1] = temp;
                flag = 1;
                swaps++;
            }
        }
        // Si se terminan de comparar todos los numeros y no hay intercambios cortamos el bucle
        if (flag != 1)
        {
            break;
        }
    }

    // Mostrar array ordenado
    printf("Array ordenado con Bubble Sort\n");
    for (int i = 0; i < size; i++)
    {
        printf("%5.1f", copyNotes[i]);
    }
    printf("\nHubo %d intercambios\n", swaps);
}

void selectionSort(int size, float notes[])
{
    float copyNotes[size];
    copyArray(size, copyNotes, notes);
    int swaps = 0;
    int comparisons = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;

        for (int j = i + 1; j < size; j++)
        {
            if (notes[min_idx] > copyNotes[j])
            {
                // almacenamos el indice del más pequeño
                min_idx = j;
                comparisons++;
            }
        }

        // si el indice del minimo cambio realizamos el intercambio
        if (min_idx != i)
        {
            float temp = copyNotes[min_idx];
            copyNotes[min_idx] = copyNotes[i];
            copyNotes[i] = temp;
            swaps++;
        }
    }

    printf("Array ordenado con Selection Sort\n");
    for (int i = 0; i < size; i++)
    {
        printf("%5.2f", copyNotes[i]);
    }
    printf("\nHubo %d intercambios y %d comparaciones\n", swaps, comparisons);
}

void insertionSort(int size, float notes[])
{
    float copyNotes[size];
    copyArray(size, copyNotes, notes);
    int comparisons = 0;
    int swaps = 0;

    // arrancamos en 1 porque se asume que el primero ya está ordenado
    for (int i = 1; i < size; i++)
    {
        // Almacenamos la nota actual, esta es la que se va a colocar en la parte ordenada
        float key = copyNotes[i];
        // Creamos un indice j para recorrer la parte ordenada del array y asi saber cual es la posicion correcta de key
        int j = i - 1;

        // j >= 0 asegura que no salgamos del inicio del array, es decir que no nos vayamos a -1
        // copyNotes[k] > key esto es para que si el elemento de la izquierda es mayor a key, significa que esta tiene que ir más a la izquierda
        while (j >= 0 && copyNotes[j] > key)
        {
            comparisons++;
            // el elemento mayor se desplaza a la derecha haciendo lugar para el valor correcto
            copyNotes[j + 1] = copyNotes[j];
            swaps++;
            // restamos j en uno para que en la siguiente vuelta del while, revise el elemento más a la izquierda si es que hay uno
            j--;
        }
        // colocamos key en su valor correcto
        copyNotes[j + 1] = key;
        swaps++; // sumamos el colocar key en su lugar correcto
    }

    printf("Array ordenado con Insertion Sort\n");
    for (int i = 0; i < size; i++)
    {
        printf("%5.1f", copyNotes[i]);
    }
    printf("\nHubo %d comparaciones y %d intercambios\n", comparisons, swaps);
}

// DISPLAY

void showArray(int size, float notes[])
{
    printf("Array original\n");
    for (int i = 0; i < size; i++)
    {
        printf("%5.1f", notes[i]);
    }
    printf("\n");
}

void menu(int size, float notes[])
{
    int option = 0;
    do
    {
        printf("Selecciona una opcion:\n");
        printf("1 Ordenar usando Bubble sort\n");
        printf("2 Ordenar usando Selection sort\n");
        printf("3 Ordenar usando Insertion sort\n");
        printf("4 Mostrar el array original\n");
        printf("5 Salir\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            bubbleSort(size, notes);
            break;
        case 2:
            selectionSort(size, notes);
            break;
        case 3:
            insertionSort(size, notes);
            break;
        case 4:
            showArray(size, notes);
            break;
        default:
            printf("Adios!\n");
            break;
        }
    } while (option != 5);
}

int main()
{
    float notes[] = {7.5, 5.0, 9.2, 6.8, 8.1, 4.3, 7.0, 5.5, 9.9, 6.0};
    int size = sizeof(notes) / sizeof(notes[0]);
    menu(size, notes);
    return 0;
}