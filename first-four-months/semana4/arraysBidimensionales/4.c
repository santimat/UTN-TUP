#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void fillMatrix(int matrix[][10]);
void filtrarYMostrarNumeros(int numeros[][10]);

int main()
{
    srand(time(NULL));
    int numeros[6][10];
    fillMatrix(numeros);
    filtrarYMostrarNumeros(numeros);
}

void fillMatrix(int numeros[][10])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int random = rand() % 1001;
            numeros[i][j] = random; // <- llenar el array con numeros entre 0 y 1000
        }
    }
}

void filtrarYMostrarNumeros(int numeros[][10])
{
    // Arrays para almacenar numero y posiciones
    int max[3] = {0, 0, 0};
    int min[3] = {numeros[0][0], 0, 0};

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (numeros[i][j] > max[0]) // <- si el numero actual es mas grande que el maximo
            {
                max[0] = numeros[i][j];
                max[1] = i + 1; // <- se suma 1 porque arranca en 0
                max[2] = j + 1;
            }
            if (numeros[i][j] < min[0])
            {
                min[0] = numeros[i][j];
                min[1] = i + 1;
                min[2] = j + 1;
            }
            printf("%d\t", numeros[i][j]);
        }
        printf("\n");
    }
    printf("El valor maximo es %d y se encuentra en la fila %d y columna %d", max[0], max[1], max[2]);
    printf("\n");
    printf("El valor minimo es %d y se encuentra en la fila %d y columna %d", min[0], min[1], min[2]);
    printf("\n");
}
// To Do Ejercicio 4 – Cargar aleatoriamente y hallar mínimo y máximo
// Crea una matriz de 6 filas por 10 columnas con números aleatorios entre 0 y 1000.
// Mostrá la matriz y luego informá:
// • El valor máximo y su posición (fila y columna).
// • El valor mínimo y su posición.
// Pistas:
// • Usá rand() % 1001 para obtener números de 0 a 1000.
// • Inicializá srand(time(NULL)) al principio.
// • Usá variables max, min, filaMax, colMax, etc. para guardar los valores y sus
// posiciones.
// • Dos bucles for anidados para recorrer.