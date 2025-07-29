#include <stdio.h>

int main()
{

    int matriz[3][4];
    matriz[0][0] = 2;
    matriz[0][1] = 5;
    matriz[0][2] = 15;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d", matriz[i][j]);
            printf("\n");
        }
    }
}