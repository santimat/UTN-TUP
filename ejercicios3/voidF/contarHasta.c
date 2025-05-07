#include <stdio.h>

void contarHasta(int num);

int main()
{
    int num = 0;
    printf("Ingrese el numero hasta el que desea contar\n");
    scanf("%d", &num);

    contarHasta(num);
    return 0;
}

void contarHasta(int num)
{
    for (int i = 1; i <= num; i++)
    {
        printf("%d\n", i);
    }
}
