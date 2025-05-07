#include <stdio.h>

int main()
{
    int num1, num2, suma = 0;

    printf("Ingrese dos numeros enteros separados por coma: \n");
    scanf("%d,%d", &num1, &num2);
    suma = num1 + num2;
    printf("Sus numeros son %d y %d, la suma de ambos es %d", num1, num2, suma);
}