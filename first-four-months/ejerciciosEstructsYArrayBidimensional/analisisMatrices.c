#include <stdio.h>
#include <stdlib.h>

void showTotalPerBranch(int sales[3][4])
{
    int total[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            total[i] += sales[i][j];
        }
        printf("Total sucursal nro#%d: $%d\n", i + 1, total[i]);
    }
}

void showTotalPerMonth(int sales[3][4])
{
    int total[4] = {0, 0, 0, 0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            total[j] += sales[i][j];
        }
    }

    for (int e = 0; e < 4; e++)
    {
        printf("Total del mes #%d: $%d\n", e + 1, total[e]);
    }
}

void showMaxSalesBranch(int sales[3][4])
{
    int totalPerBranch[3] = {0, 0, 0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            totalPerBranch[i] += sales[i][j];
        }
    }

    int max = -1;
    int maxSalesBranchIdx = -1;
    for (int i = 0; i < 3; i++)
    {
        if (totalPerBranch[i] > max)
        {
            max = totalPerBranch[i];
            maxSalesBranchIdx = i;
        }
    }

    printf("La sucursal numero #%d fue la que más vendió, con un total de %d", maxSalesBranchIdx + 1, max);
}

void showAverageSales(int sales[3][4])
{
    int total = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            total += sales[i][j];
        }
    }
    float average = (float)total / 12;

    printf("El promedio total de ventas es de  %.2f", average);
}

int main()
{

    int sales[3][4] = {
        {1200, 1500, 1100, 1300},
        {1000, 1400, 1250, 1350},
        {900, 1200, 1150, 1400}};

    showTotalPerBranch(sales);
    showTotalPerMonth(sales);
    showMaxSalesBranch(sales);
    showAverageSales(sales);
    return 0;
}