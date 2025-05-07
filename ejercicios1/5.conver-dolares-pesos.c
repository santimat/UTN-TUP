#include <stdio.h>

int main()
{
    const float dolarTurista = 1364.03;
    float conversion = 0;

    printf("Ingrese su monto a convertir en pesos\n");
    scanf("%f", &conversion);

    conversion = conversion * dolarTurista;

    printf("Obtendras %.2f pesos", conversion);
    return 0;
}