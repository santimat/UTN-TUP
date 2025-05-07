#include <stdio.h>
int returnBool(int num);
int main()
{
    int num = 0;
    printf("Ingrese un numero\n");
    scanf("%d", &num);

    if (returnBool(num) == 1)
    {
        printf("El numero es positivo");
    }
    else
    {
        printf("El numero es negativo");
    }

    return 0;
}

int returnBool(int num)
{
    if (num > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}