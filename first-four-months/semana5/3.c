// Escribí un programa en C que permita al usuario ingresar 10 números enteros
// entre 1 y 1000. Luego, utilizando funciones:
// 1. Cargar los 10 números en un arreglo, validando que estén en el rango de 1
// a 1000.
// 2. Mostrar en pantalla únicamente los números primos que fueron ingresados.
// 3. Contar cuántos de los números ingresados son múltiplos de 5.
// 4. Calcular el promedio de los números que no son primos ni múltiplos de 5.
// No usar variables globales.
// Usar al menos 2 funciones además del main().
// Para verificar si un número es primo, hacé una función tipo int esPrimo(int num)
// que devuelva 1 si es primo, 0 si no. Los números primos son aquellos que SOLO pueden
// dividirse por 1 y por si mismos (división entera).

#include <stdio.h>
void cargarArray(int numeros[], int longitud);
void mostrarPrimos(int numeros[], int longitud);
void mostrarMultiplos5(int numeros[], int longitud);
float calcularPromedioNoPrimosNoMultiplos(int numeros[], int longitud);
int main()
{
    int longitud = 3;
    int numeros[longitud];

    cargarArray(numeros, longitud);

    mostrarPrimos(numeros, longitud);

    mostrarMultiplos5(numeros, longitud);

    float promedio = calcularPromedioNoPrimosNoMultiplos(numeros, longitud);
    printf("\nEl promedio de los numeros que no son primos ni multiplos de 5 es: %.2f\n", promedio);

    return 0;
}

void cargarArray(int numeros[], int longitud)
{
    int i = 0;
    do
    {
        int num = 0;
        printf("Ingrese el numero #%d\n", i + 1);
        scanf("%d", &num);
        if (num < 1 || num > 1000)
        {
            printf("El numero debe estar entre 1 y 1000\n");
        }
        else
        {
            numeros[i] = num;
            i++;
        }

    } while (i < longitud);
}
void mostrarPrimos(int numeros[], int longitud)

{

    printf("Numeros primos:\n");
    for (int i = 0; i < longitud; i++)
    {
        int numPrimo = esPrimo(numeros[i]);
        if (numPrimo == 1)
        {
            printf("%d\t", numeros[i]);
        }
    }
}
void mostrarMultiplos5(int numeros[], int longitud)
{
    printf("\nMutliplos de 5\n");
    for (int i = 0; i < longitud; i++)
    {
        if (numeros[i] % 5 == 0)
        {
            printf("%d\t", numeros[i]);
        }
    }
}
int esPrimo(int num)
{
    int primo = 0;
    if (num % 2 != 0 && num / num == 1 && num % 1 == 0)
    {
        primo = 1;
    }
    return primo;
}
float calcularPromedioNoPrimosNoMultiplos(int numeros[], int longitud)
{
    float sum = 0;
    for (int i = 0; i < longitud; i++)
    {

        int esprimo = esPrimo(numeros[i]);
        if (esprimo != 1 && numeros[i] % 5 != 0)
        {
            sum += numeros[i];
        }
    }

    return (float)sum / longitud;
}



