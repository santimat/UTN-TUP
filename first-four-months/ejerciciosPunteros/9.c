#include <stdio.h>

void leerDatos(int size, int *nums)
{
    int i = 0;
    do
    {
        printf("Ingrese el #%d numero:\n", i + 1);
        scanf("%d", (nums + i));
        i++;
    } while (i < size);
}

void calcularEstadisticas(int size, int *nums, int *suma, float *promedio, int *mayor, int *menor, int *pares, int *impares)
{
    for (int i = 0; i < size; i++)
    {
        (*suma) += *(nums + i);

        if (*(nums + i) > *mayor)
        {
            *mayor = *(nums + i);
        }

        if (*(nums + i) < *menor)
        {
            *menor = *(nums + i);
        }

        if (*(nums + i) % 2 == 0)
        {
            (*pares)++;
        }
        else
        {
            (*impares)++;
        }
    }
    *promedio = (float)(*suma) / size;
}

void imprimirArray(int size, int *nums)
{
    printf("Array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%5d", *(nums + i));
    }
    printf("\n");
}

void imprimirEstadisticas(int size, int *nums, int *suma, float *promedio, int *mayor, int *menor, int *pares, int *impares)
{
    printf("Estadisticas\n");
    printf("Suma total: %d\n", *suma);
    printf("Promedio: %.2f\n", *promedio);
    printf("Mayor: %d\n", *mayor);
    printf("Menor: %d\n", *menor);
    printf("Pares: %d\n", *pares);
    printf("Impares: %d\n", *impares);
}
int main()
{
    int size = 3;
    int nums[size];
    leerDatos(size, nums);
    int suma = 0, mayor = 0, menor = nums[0], pares = 0, impares = 0;
    float promedio = 0;
    imprimirArray(size, nums);
    calcularEstadisticas(size, nums, &suma, &promedio, &mayor, &menor, &pares, &impares);
    imprimirEstadisticas(size, nums, &suma, &promedio, &mayor, &menor, &pares, &impares);
    return 0;
}