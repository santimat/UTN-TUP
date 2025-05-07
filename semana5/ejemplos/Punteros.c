#include <stdio.h>

int main()
{

    int num = 5;
    // creamos un puntero
    // con & obtenemos la direccion de memoria
    int *puntero;
    // guardamos la direccion de memoria de num
    puntero = &num;

    printf("Valor de num: %d\n", num);
    printf("Direccion de memoria de num: %p\n", &num);
    // %p imprime la direccion de memoria
    printf("Direccion de memoria de puntero: %p\n", puntero);
    printf("Valor de num desde el puntero: %d\n", *puntero); // <- usamos * para acceder al contenido del puntero
    return 0;
}