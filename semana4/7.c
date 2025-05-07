#include <stdio.h>

int main()
{
    int LONG = 5;
    int numeros[LONG];
    int cont = 0;
    do
    {
        printf("Ingrese el %d° numero\n", cont + 1);
        scanf("%d", &numeros[cont]);
        cont++;
    } while (cont < LONG);

    for (int i = 0; i < LONG; i++)
    {
        if (numeros[i] % 2 != 0)
        {
            printf("%d <- impar\n", numeros[i]);
        }
        else
        {
            printf("%d <- par\n", numeros[i]);
        }
    }
}