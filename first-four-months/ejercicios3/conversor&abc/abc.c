#include <stdio.h>

int main()
{
    int cantidadLetras = 0;
    char letra;
    int exit = 1;
    do
    {
        printf("Ingresa la cantidad de letras\n");
        scanf("%d", &cantidadLetras);
        if (cantidadLetras < 0)
        {
            printf("Error intente de nuevo\n");
            continue;
        }

        printf("Ingrese la letra por la que desea iniciar\n");
        scanf(" %c", &letra);

        if ((letra >= 65 && letra <= 90) || (letra >= 97 && letra <= 122))
        {
            exit = 0;
        }
        else
        {
            printf("Error, intente de nuevo\n");
        }

    } while (exit);

    for (int i = 0; i < cantidadLetras; i++)
    {
        printf("%c\t", letra);
        letra++;
    }
}