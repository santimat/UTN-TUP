#include <stdio.h>
void pedirYGuardarNumeros(int numeros[]);
void mostrarNumeros(int numeros[]);

int main()
{
    int numeros[10];
    pedirYGuardarNumeros(numeros);

    mostrarNumeros(numeros);
    return 0;
}

void pedirYGuardarNumeros(int numeros[])
{
    int cont = 0;
    do
    {
        printf("Ingrese el %d° numero\n", cont + 1);
        scanf("%d", &numeros[cont]);
        cont++;
    } while (cont < 10);
}

void mostrarNumeros(int numeros[])
{
    int mayor = numeros[0];
    int menor = numeros[0];
    for (int i = 1; i < 10; i++)
    {
        printf("%d\n", numeros[i]);
        if (numeros[i] < menor)
        {
            menor = numeros[i];
        }
        if (numeros[i] > mayor)
        {
            mayor = numeros[i];
        }
        if (i == 9)
        {
            printf("%d <- mayor\n", mayor);
            printf("%d <- menor\n", menor);
        }
    }
}