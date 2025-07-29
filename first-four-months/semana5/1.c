// Escriba un programa en C que permita al usuario cargar 12 números enteros
// (entre 1 y 100) en un arreglo. Luego, realice las siguientes tareas utilizando
// funciones:
// • Una función para cargar el arreglo
// • Una función para calcular el promedio
// • Una función debe contar cuántos números son mayores al promedio de
// todos los números ingresados y retornar ese valor.
// • Otra función debe imprimir solo los números pares.

#include <stdio.h>

void cargarArray(int nums[], int longitud);
float calcularPromedio(int nums[], int longitud);
int obtenerMayoresAlPromedio(int nums[], int longitud, int promedio);
void imprimirNumerosPares(int nums[], int longitud);
void mostrarArray(int nums[], int longitud);

int main()
{
    int longitud = 12;
    int numeros[longitud];

    cargarArray(numeros, longitud);
    int promedio = calcularPromedio(numeros, longitud);
    int mayoresAlPromedio = obtenerMayoresAlPromedio(numeros, longitud, promedio);
    imprimirNumerosPares(numeros, longitud);
    mostrarArray(numeros, longitud);

    return 0;
}

void cargarArray(int nums[], int longitud)
{
    int i = 0;
    do
    {
        int num = 0;
        printf("Ingrese el numero #%d\n", i + 1);
        scanf("%d", &num);
        if (num < 1 || num > 100)
        {
            printf("El numero debe estar entre 1 y 100\n");
        }
        else
        {
            nums[i] = num;
            i++;
        }
    } while (i < 12);
}

float calcularPromedio(int nums[], int longitud)
{
    int promedio = 0;
    for (int i = 0; i < longitud; i++)
    {
        promedio += nums[i];
    }
    promedio = promedio / longitud;
    return promedio;
}

int obtenerMayoresAlPromedio(int nums[], int longitud, int promedio)
{
    for (int i = 0; i < longitud; i++)
    {
        int mayores = 0;
        if (nums[i] > promedio)
        {
            mayores++;
        }
        return mayores;
    }
}

void imprimirNumerosPares(int nums[], int longitud)
{
    printf("Numeros pares\n");
    for (int i = 0; i < longitud; i++)
    {
        if (nums[i] % 2 == 0)
        {
            printf("%d\n", nums[i]);
        }
    }
}

void mostrarArray(int nums[], int longitud)
{
    printf("Array original\n");
    for (int i = 0; i < longitud; i++)
    {
        printf("%d\n", nums[i]);
    }
}