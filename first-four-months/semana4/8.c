#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void llenarArray(int numeros[], int LONG);
void intercambiarNumeros(int numeros[], int LONG);
void mostrarNumeros(int numeros[], int LONG);

int main()
{
    srand(time(NULL));
    int LONG = 5;
    int numeros[LONG];

    llenarArray(numeros, LONG);
    intercambiarNumeros(numeros, LONG);
    mostrarNumeros(numeros, LONG);
}

void llenarArray(int numeros[], int LONG)
{
    for (int i = 0; i < LONG; i++)
    {
        numeros[i] = rand() % 101; // <- llenamos con numeros aleatorios entre 0 y 100
    }
}

void intercambiarNumeros(int numeros[], int LONG)
{

    int izq = 0;
    int der = LONG - 1;

    while (izq < der)
    {
        int numeroIzq = numeros[izq];
        int numeroDer = numeros[der];
        if (numeroIzq % 2 == 0)
        {
            izq++;
        }
        else if (numeroDer % 2 != 0)
        {
            der--;
        }
        else
        {
            int temp = numeros[izq];
            numeros[izq] = numeroDer;
            numeros[der] = temp;
            izq++;
            der--;
        }
    }

    // int huboIntercambio = 0;
    // for (int i = 1; i < LONG; i++) // <- for para repetir la validacion por la totalidad de elementos
    // {
    //     for (int j = 0; j < LONG - 1; j++) // <- for para validar elemento por elemento el array
    //     {
    //         if (numeros[j] % 2 != 0 && numeros[j + 1] % 2 == 0) // <- si el elemento es impar y el que le sigue par
    //         {
    //             int imp = numeros[j]; // <- variable temporal con el numero impar

    //             numeros[j] = numeros[j + 1]; // <- asigno el par donde estaba el impar

    //             numeros[j + 1] = imp; // <- asigno el impar donde estaba el par

    //             huboIntercambios = 1; // <- confirmo que hubo un intercambio
    //         }
    //     }
    //     if (huboIntercambios != 1) // <- si no hubo intercambios corto el for
    //     {
    //         break;
    //     }
    // }
}

void mostrarNumeros(int numeros[], int LONG)
{
    for (int i = 0; i < LONG; i++)
    {
        printf("%d\t", numeros[i]);
    }
}