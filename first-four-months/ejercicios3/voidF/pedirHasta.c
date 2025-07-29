#include <stdio.h>

void pedirNumero();

int main()
{
    pedirNumero();
    return 0;
}

void pedirNumero()
{
    int num = 0;
    do
    {
        printf("Ingrese un numero\n");
        scanf("%d", &num);
    } while (num < 0);
}