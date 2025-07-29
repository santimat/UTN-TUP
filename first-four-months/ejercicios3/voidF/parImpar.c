#include <stdio.h>

void parImpar(int num);
int main()
{
    int num = 0;
    printf("Ingrese un numero\n");
    scanf("%d", &num);

    parImpar(num);
    return 0;
}

void parImpar(int num)
{
    if (num % 2 == 0)
    {
        printf("Numero par\n");
    }
    else
    {
        printf("Numero impar\n");
    }
}