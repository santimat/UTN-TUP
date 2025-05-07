#include <stdio.h>

int main()
{
    char numeros[12];
    numeros[0] = 2;
    numeros[1] = 4;
    numeros[2] = 10;

    for (int i = 0; i < 12; i++)
    {
        printf("%i\n", numeros[i]);
    }
}

// Los valores que no fueron inicializados tomaron valores basura.
// Resultado:
// 2
// 4
// 10
// 0
// -120
// 69
// -83
// 0
// 0
// 0
// 0
// 0