#include <stdio.h>

int main()
{
    const float dolarTurista = 1364.03;
    float conversion = 0;
    printf("Ingrese su monto en pesos a convertir\n");
    scanf("%f", &conversion);

    conversion = conversion / dolarTurista;

    printf("Obtendras un monto de %.2f dolares", conversion);
    return 0;
}