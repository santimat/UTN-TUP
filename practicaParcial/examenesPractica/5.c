#include <stdio.h>

void pedirTam(int *largo);
void pedirValores(int valores[], int largo);
float calcularPromedio(int valores[], int largo);

int main()
{
    int largo = 0;
    pedirTam(&largo);
    int valores[largo];
    pedirValores(valores, largo);

    float promedio = calcularPromedio(valores, largo);
    printf("El promedio de los elementos del array es de %.2f", promedio);
    return 0;
}

void pedirTam(int *largo)
{
    printf("Ingrese el largo de un array de enteros\n");
    scanf("%d", largo);
}

void pedirValores(int valores[], int largo)
{
    for (int i = 0; i < largo; i++)
    {
        printf("Ingrese el #%d valor\n", i + 1);
        scanf("%d", &valores[i]);
    }
}

float calcularPromedio(int valores[], int largo)
{
    int sum = 0;
    for (int i = 0; i < largo; i++)
    {
        sum += valores[i];
    }
    return (float)sum / largo;
}