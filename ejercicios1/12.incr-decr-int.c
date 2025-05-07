#include <stdio.h>

int main()
{
    int num = 0;
    printf("Ingrese un numero entero:\n");
    scanf("%i", &num);
    printf("Valor original -> %i\n", num);
    printf("Pre incremento -> %i\n", num++, num);
    printf("Post incremento -> %i\n", num);
    printf("Pre decremento -> %i\n", --num, num);
    printf("Post decremento -> %i", --num);
    return 0;
}