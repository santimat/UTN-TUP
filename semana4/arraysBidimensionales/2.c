#include <stdio.h>

int main()
{
    int numeros[2][5];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("Ingrese el numero de la fila %d, columna %d", i + 1, j + 1);
            scanf("%d", &numeros[i][j]);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", numeros[i][j]);
        }
        printf("\n");
    }
}
