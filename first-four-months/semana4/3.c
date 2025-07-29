#include <stdio.h>

int main()
{
    int cont = 1;
    int numeros[10];
    do
    {
        printf("Ingrese el %i° de los numeros\n", cont);
        scanf("%i", &numeros[cont]);
        cont++;
    } while (cont <= 10);

    for (int i = 10; i > 0; i--)
    {
        printf("%i\n", numeros[i]);
    }
}