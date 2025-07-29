#include <stdio.h>

int main()
{
    int num = 0;
    printf("Ingrese un numero entero positivo\n");
    scanf("%d", &num);

    int esPrimo = 1;
    for (int divisor = 2; divisor < num / 2; divisor++)
    {
        if (num % divisor == 0)
        {
            esPrimo = 0;
        }
    }

    if (esPrimo)
    {
        printf("%d es primo", num);
    }
    else
    {
        printf("%d no es primo", num);
    }
}