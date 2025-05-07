// Escribí un programa en C que permita al usuario ingresar 8 números enteros de
// tres cifras (entre 100 y 999). Luego, utilizando funciones:
// 1. Cargar el arreglo con los 8 números, validando que estén entre 100 y 999.
// 2. Contar cuántos de esos números tienen al menos un dígito repetido.
// 3. Calcular y mostrar la suma total de todos los dígitos de los 8 números.
// 4. Mostrar en pantalla aquellos números que tienen todos sus dígitos
// diferentes.
// No usar variables globales.
// Usar al menos 2 funciones además del main().
// Validar el rango de entrada correctamente.

#include <stdio.h>

void cargarArray(int numeros[], int longitud);
int contarDigitosRepetidos(int numeros[], int longitud);
int sumarDigitos(int numeros[], int longitud);
void mostrarNumerosDiferentes(int numeros[], int longitud);

int main()
{
    int longitud = 2;
    int numeros[longitud];
    cargarArray(numeros, longitud);

    int digitosRepetidos = contarDigitosRepetidos(numeros, longitud);
    printf("Numeros con digitos repetidos: %d\n", digitosRepetidos);

    int sumaDigitos = sumarDigitos(numeros, longitud);
    printf("Suma de los digitos: %d\n", sumaDigitos);

    mostrarNumerosDiferentes(numeros, longitud);
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
        if (num < 100 || num > 999)
        {
            printf("El numero debe estar entre 100 y 999\n");
        }
        else
        {
            numeros[i] = num;
            i++;
        }
    } while (i < longitud);
}

int contarDigitosRepetidos(int numeros[], int longitud)
{
    int cont = 0;
    for (int i = 0; i < longitud; i++)
    {
        int nums = numeros[i];
        int num3 = nums % 10;
        int num2 = nums % 100 / 10;
        int num1 = nums % 1000 / 10 / 10;
        if (num1 == num2 || num2 == num3 || num1 == num3)
        {
            cont++;
        }
    }
    return cont;
}

int sumarDigitos(int numeros[], int longitud)
{
    int suma = 0;
    for (int i = 0; i < longitud; i++)
    {
        int nums = numeros[i];
        int num3 = nums % 10;
        int num2 = nums % 100 / 10;
        int num1 = nums % 1000 / 10 / 10;
        suma += num1 + num2 + num3;
    }
    return suma;
}

void mostrarNumerosDiferentes(int numeros[], int longitud)
{
    printf("Numeros con digitos diferentes\n");
    for (int i = 0; i < longitud; i++)
    {
        int nums = numeros[i];
        int num3 = nums % 10;
        int num2 = nums % 100 / 10;
        int num1 = nums % 1000 / 10 / 10;
        if (num1 != num2 && num2 != num3 && num1 != num3)
        {
            printf("%d\n", nums);
        }
    }
}