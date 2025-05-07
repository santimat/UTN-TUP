#include <stdio.h>

int main()
{
    int LONG = 15;
    int cont = 0;
    int numeros[LONG];
    do
    {
        printf("Ingrese numero\n");
        scanf("%d", &numeros[cont]);
        cont++;
    } while (cont < LONG);

    printf("ANTES\n");
    for (int i = 0; i < LONG; i++)
    {
        printf("%d\n", numeros[i]);
    }

    int ultimo = numeros[LONG - 1];
    for (int i = LONG; i > 0; i--)
    {
        numeros[i] = numeros[i - 1];
    }
    numeros[0] = ultimo;

    printf("DESPUES\n");
    for (int i = 0; i < LONG; i++)
    {
        printf("%d\n", numeros[i]);
    }
}