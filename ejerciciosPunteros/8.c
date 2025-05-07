// calcular longitud de un string

#include <stdio.h>

int length(char *cadena)
{
    int i = 0;
    int longitud = 0;
    while (*(cadena + i) != '\0')
    {
        longitud++;
        i++;
    }
    return longitud;
}

int main()
{
    // El asterisco lo convierte en una constante
    char *cadena = "Hola como estas?";

    int longitud = length(cadena);

    printf("La cadena tiene %d caracteres", longitud);
    return 0;
}