#include <stdio.h>

int returnInt(int num);

int main()
{

    int num = 0;
    printf("Ingrese un numero\n");
    scanf("%i", &num);

    printf("Tu numero al cuadrado es: %i", returnCuadrado(num));
    return 0;
}

int returnCuadrado(int num)
{
    return num * num;
}