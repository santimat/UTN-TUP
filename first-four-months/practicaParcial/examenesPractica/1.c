#include <stdio.h>

void mostrarResultados(int num1, int num2);

int main()
{
    int num1 = 0, num2 = 0;
    pedirNumeros(&num1, &num2);
    mostrarResultados(num1, num2);

    return 0;
}

void pedirNumeros(int *num1, int *num2)
{
    // No se pone & en el scan porque la funcion ya toma directamente la direccion de memoria
    printf("Ingrese un numero");
    scanf("%d", num1);
    printf("Ingrese otro numero");
    scanf("%d", num1);
}
void mostrarResultados(int num1, int num2)
{
    printf("Suma de ambos: %d", num1 + num2);
    printf("Resta de ambos: %d", num1 - num2);
    printf("Multiplacion de ambos: %d", num1 * num2);
    // Casteamos el primer valor para evitar errores en caso de que de con coma
    printf("Division de ambos: %.2f", (float)num1 / num2);
}