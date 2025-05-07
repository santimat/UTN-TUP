#include <stdio.h>

int main()
{
    char simbolos[10];

    simbolos[0] = 'a';
    simbolos[3] = '@';
    simbolos[5] = '!';

    for (int i = 0; i < 10; i++)
    {
        printf("%c\n", simbolos[i]);
    }
}

// Como en el caso de los numeros los valores no inicializados contienen basuraa

// a    <- incializado
//      <- no inicializado
// ê    <- no inicializado
// @    <- incializado
// ╣    <- no inicializado
// !    <- incializado