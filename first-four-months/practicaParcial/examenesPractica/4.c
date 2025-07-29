#include <stdio.h>

void motrarSiEsPar(int num);
void pedirNumeros(int nums[], int largo);
void calcularParesEImpares(int nums[], int largo, int *pares, int *impares);

int main()
{

    int num = 0, pares = 0, impares = 0;
    int largo = 10;
    int nums[largo];

    printf("Ingrese un numero\n");
    scanf("%d", &num);

    motrarSiEsPar(num);

    printf("### Ingrese 10 numeros enteros ###\n");
    pedirNumeros(nums, largo);
    calcularParesEImpares(nums, largo, &pares, &impares);
    printf("Hay %d numeros pares y %d impares\n", pares, impares);

    return 0;
}

void motrarSiEsPar(int num)
{

    if (num % 2 == 0)
    {
        printf("El numero %d es par\n", num);
    }
    else
    {
        printf("El numero %d es impar\n", num);
    }
}

void pedirNumeros(int nums[], int largo)
{
    for (int i = 0; i < largo; i++)
    {
        printf("Ingrese el #%d numero\n", i + 1);
        scanf("%d", &nums[i]);
    }
}

void calcularParesEImpares(int nums[], int largo, int *pares, int *impares)
{
    for (int i = 0; i < largo; i++)
    {
        if (nums[i] % 2 == 0)
        {
            (*pares)++;
        }
        else
        {
            (*impares)++;
        }
    }
}