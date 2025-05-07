// a minusculas

// convertir a mayusculas

#include <stdio.h>

void convertir(char *nombre)
{
    int i = 0;

    while (*(nombre + i) != '\0')
    {
        if (*(nombre + i) >= 'A' && *(nombre + i) <= 'Z')
        {
            *(nombre + i) += 32;
        }
        i++;
    }
}
int main()
{
    char nombre[] = "SANTINO";

    convertir(nombre);

    printf("Nombre en minus %s", nombre);
}