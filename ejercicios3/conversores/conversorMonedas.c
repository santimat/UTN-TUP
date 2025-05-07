#include <stdio.h>

int main()
{
    int monedaOrigen = 0;
    int moendaDestino = 0;
    float cantidadAConvertir = 0;
    printf("Seleccione su moneda de origen\n");
    printf("1: ARS, 2: BRL, 3: EUR, 4: USD");
    scanf("%i", &monedaOrigen);
    printf("Seleccione su moneda de destino\n");
    printf("1: ARS, 2: BRL, 3: EUR, 4: USD");
    scanf("%i", &moendaDestino);
    printf("Ingrese su cantidad a convertir\n");
    scanf("%f", &cantidadAConvertir);

    switch (monedaOrigen)
    {
    case 1:
    }

    return 0;
}