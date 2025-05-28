#include <stdio.h>
#include <stdlib.h>

void showTotalPerBranch(int sales[3][4])
{
    int total[3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            total[i] += sales[i][j];
        }
    }

    printf("La primer sucursal vendió un total de: %d\n", total[0]);
    printf("La segunda sucursal vendió un total de: %d\n", total[1]);
    printf("La tercer sucursal vendió un total de: %d\n", total[2]);
}

void showTotalPerMonth(int sales[3][4])
{
    int total[4];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            total[j] += sales[i][j];
        }
    }
    printf("El primer mes se vendio un total de: %d\n", total[0]);
    printf("El segundo mes se vendio un total de: %d\n", total[1]);
    printf("El tercer mes se vendio un total de: %d\n", total[2]);
    printf("El cuarto mes se vendio un total de: %d\n", total[3]);
}
void showMaxSalesBranch(int sales[3][4])
{
    int total[3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            total[i] += sales[i][j];
        }
    }
    if (total[0] > total[1] && total[0] > total[2])
    {
        printf("La primer sucursal es la que mas vendio\n");
    }
    else if (total[1] > total[2] && total[1] > total[0])
    {
        printf("La segundo sucursal es la que mas vendio\n");
    }
    else
    {
        printf("La tercer sucursal es la que mas vendio\n");
    }
}

int main()
{

    int sales[3][4] = {
        {1200, 1500, 1100, 1300},
        {1000, 1400, 1250, 1350},
        {900, 1200, 1150, 1400}};

    return 0;
}