// Genera 1000 números aleatorios entre 1 y 10 (inclusive).
// Utiliza un array para almacenar la frecuencia con la que aparece cada número.
// Recorre los números generados y actualiza el contador de frecuencia correspondiente.
// Muestra la frecuencia de cada número (cuántas veces apareció el 1, cuántas veces apareció el 2, etc.).

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarArray(int nums[], int largo);
void calcularFrecuencias(int nums[], int largo);
void mostrarFrecuencias();

int frecuencia[10];
int main()
{
    srand(time(NULL));

    int largo = 1000, nums[largo];

    cargarArray(nums, largo);

    calcularFrecuencias(nums, largo);

    mostrarFrecuencias();
    return 0;
}

void cargarArray(int nums[], int largo)
{
    for (int i = 0; i < largo; i++)
    {
        nums[i] = rand() % 10 + 1;
    }
}

void calcularFrecuencias(int nums[], int largo)
{
    for (int i = 0; i < largo; i++)
    {
        int indice = nums[i] - 1;
        frecuencia[indice]++;
    }
}

void mostrarFrecuencias()
{
    for (int i = 0; i < 10; i++)
    {
        printf("Cantidad de veces que sale el numero %d: %d\n", i + 1, frecuencia[i]);
    }
}