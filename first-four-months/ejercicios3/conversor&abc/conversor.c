#include <stdio.h>

// Constantes globales con los valores del dolar
const float ARS = 1068.55;
const float BRL = 4.98;
const float EUR = 0.92;

// Prototipos
float toDolar(int monedaOrigen, float cantidadAConvertir);
float obtenerResultado(int monedaDestino, float valorUSD);

int main()
{
    int monedaOrigen = 0;
    int monedaDestino = 0;
    float cantidadAConvertir = 0;

    printf("Ingrese su moneda de origen\n");
    printf("1: ARS\n2: USD\n3: EUR\n4: BRL\n");
    scanf("%i", &monedaOrigen);

    printf("Ingrese su moneda de destino\n");
    printf("1: ARS\n2: USD\n3: EUR\n4: BRL\n");
    scanf("%i", &monedaDestino);

    printf("Ingrese la cantidad a convertir\n");
    scanf(" %f", &cantidadAConvertir);

    float valorUSD = toDolar(monedaOrigen, cantidadAConvertir);

    float res = obtenerResultado(monedaDestino, valorUSD);
    printf("%.2f", res);
}

// convertir de la moneda elegida a usd
float toDolar(int monedaOrigen, float cantidadAConvertir)
{
    // variable para guardar el valor de la moneda elegida en dolares
    float valorUSD = 0;
    switch (monedaOrigen)
    {
    case 1:
        valorUSD = cantidadAConvertir / ARS;
        break;
    case 2:
        valorUSD = cantidadAConvertir;
        break;
    case 3:
        valorUSD = cantidadAConvertir / EUR;
        printf("%.2f", valorUSD);
        break;
    case 4:
        valorUSD = cantidadAConvertir / BRL;
        break;
    default:
        return printf("Opcion de origen no valida");
        break;
    }
    return valorUSD;
}

// calcular el resultado segundo la moneda destino elegida
float obtenerResultado(int monedaDestino, float valorUSD)
{
    float res = 0;
    // una vez convertida la moneda origen elegida en dolares, obtengo la moneda destino multiplicando el valor en dolares por su respectivo valor
    switch (monedaDestino)
    {
    case 1:
        res = valorUSD * ARS;
        break;
    case 2:
        res = valorUSD;
        break;
    case 3:
        res = valorUSD * EUR;
        break;
    case 4:
        res = valorUSD * BRL;
        break;
    default:
        printf("Opcion de destino no valida");
        break;
    }

    return res;
}