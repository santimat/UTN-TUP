// convertir a mayusculas

#include <stdio.h>

void convertir(char *nombre)
{
    int i = 0;

    while (*(nombre + i) != '\0')
    {
        if (*(nombre + i) >= 'a' && *(nombre + i) <= 'z')
        {
            *(nombre + i) -= 32;
        }
        i++;
    }
}
int main()
{
    char nombre[] = "Santino";

    convertir(nombre);

    printf("Nombre en mayus %s", nombre);
}