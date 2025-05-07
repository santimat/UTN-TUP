#include <stdio.h>

int main()
{
    char nombre[20] = "Santino";
    char *puntero = nombre;

    // mientras el puntero no apunte al final de la cadena
    while (*puntero != '\0')
    {
        // imprimimos el puntero
        printf("%c | %p\n", *puntero, puntero);
        // incrementamos el puntero, para que apunte al siguiente caracter
        puntero++;
    }

    return 0;
}