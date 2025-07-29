#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillMatrix(int matriz[][10]);
void showMatrix(int matriz[][10]);

int main()
{
    srand(time(NULL));
    int matriz[10][10];
    fillMatrix(matriz);
    showMatrix(matriz);
}

// Llenar matriz
void fillMatrix(int matriz[][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matriz[i][j] = (rand() % 101) + 200; // <- Iniciamos desde 200 el numero random y hacemos que llegue solo a 300
        }
    }
}

void showMatrix(int matriz[][10])
{
    int minMax[2] = {matriz[0][0], matriz[0][0]};
    int sum = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == j)
            {
                if (matriz[i][j] < minMax[0])
                {
                    minMax[0] = matriz[i][j];
                }
                if (matriz[i][j] > minMax[1])
                {
                    minMax[1] = matriz[i][j];
                }
                sum += matriz[i][j];
                printf("%d", matriz[i][j]);
            }
        }
        printf("\t");
    }
    printf("\n");
    printf("El minimo es %d y el maximo es %d\n", minMax[0], minMax[1]);
    printf("El promedio es %d\n", sum / 10);
}

// Crea una matriz de 10x10 con números aleatorios entre 200 y 300.
// Mostrá la matriz. Luego:
// • Mostrá los elementos que están en la diagonal principal (de [0][0] a [9][9]).
// • Calculá el máximo, mínimo y promedio de los elementos de esa diagonal.