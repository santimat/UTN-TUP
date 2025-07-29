#include <stdio.h>

void returnMayor(int num, int num2);

int main()
{
    int num, num2 = 0;
    printf("Ingrese un numero\n");
    scanf("%d", &num);
    printf("Ingrese otro numero\n");
    scanf("%d", &num2);

    returnMayor(num, num2);
    return 0;
}

void returnMayor(int num, int num2)
{
    if (num > num2)
    {
        printf("El mayor es: %d", num);
    }
    else
    {
        printf("El mayor es: %d", num2);
    }
}