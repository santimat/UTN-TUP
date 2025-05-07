// Matriz de Identidad:

// Crea una matriz bidimensional de 5x5.
// Utiliza bucles for anidados para llenar la matriz de manera que sea una matriz identidad (los elementos de la diagonal principal sean 1 y el resto sean 0).
// Muestra la matriz resultante.
// Suma de Diagonales de una Matriz:


#include <stdio.h>
void llenarMatriz(int filas, int columnas, int matriz[filas][columnas]);
void mostrarMatriz(int filas, int columnas, int matriz[filas][columnas]);

int main()
{
    int filas = 5, columnas = 5;
    int matriz[filas][columnas];

    llenarMatriz(filas, columnas, matriz);

    mostrarMatriz(filas, columnas, matriz);
    return 0;
}

void llenarMatriz(int filas, int columnas, int matriz[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (i == j)
            {
                matriz[i][j] = 1;
            }else{
                matriz[i][j] = 0;
            }
        }
    }
}

void mostrarMatriz(int filas, int columnas, int matriz[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf(" %d |", matriz[i][j]);
        }
        printf("\n");
    }
}