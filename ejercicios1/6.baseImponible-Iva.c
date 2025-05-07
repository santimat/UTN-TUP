#include <stdio.h>

int main()
{
    float baseImponible = 0;
    const float IVA = 0.21;

    printf("Ingrese el valor de la factura sin el IVA:\n");
    scanf("%f", &baseImponible);

    baseImponible = baseImponible + (baseImponible * IVA);

    printf("El total de su factura es: $%.2f", baseImponible);
    return 0;
}