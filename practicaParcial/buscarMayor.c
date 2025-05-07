// Pide al usuario las dimensiones (filas y columnas) de una matriz bidimensional.
// Pide al usuario que ingrese los elementos de la matriz.
// Utiliza bucles for anidados para encontrar el elemento más grande de la matriz y mostrar su valor y su posición (fila y columna).

#include <stdio.h>

void pedirSize(int *filas, int *columnas);
void cargarMatriz(int filas, int columnas, int nums[filas][columnas]);
void mostrarMayor(int filas, int columnas, int nums[filas][columnas]);

int main()
{
    int filas = 0, columnas = 0;

    pedirSize(&filas, &columnas);
    int nums[filas][columnas];

    cargarMatriz(filas, columnas, nums);

    mostrarMayor(filas, columnas, nums);
    return 0;
}

void pedirSize(int *filas, int *columnas)
{
    // Cuando se pasa por puntero una variable no se le pone el ampersand por que este ya tiene la direccion de memoria
    printf("Ingrese el numero de filas que desea\n");
    scanf("%d", filas);
    printf("Ahora ingrese la cantidad columnas\n");
    scanf("%d", columnas);
}

void cargarMatriz(int filas, int columnas, int nums[filas][columnas])
{
    for (int fila = 0; fila < filas; fila++)
    {
        for (int columna = 0; columna < columnas; columna++)
        {
            printf("Ingrese el valor de la fila %d en la columna %d\n", fila + 1, columna + 1);
            scanf("%d", &nums[fila][columna]);
        }
    }
}

void mostrarMayor(int filas, int columnas, int nums[filas][columnas])
{
    int mayor[3] = {0, 0, 0};
    for (int fila = 0; fila < filas; fila++)
    {
        for (int columna = 0; columna < columnas; columna++)
        {
            if (nums[fila][columna] > mayor[0])
            {
                mayor[0] = nums[fila][columna];
                mayor[1] = fila;
                mayor[2] = columna;
            }
        }
    }

    printf("El mayor numero es el %d, se encontraba en la posicion %d en la columna %d\n", mayor[0], mayor[1] + 1, mayor[2] + 1);
}