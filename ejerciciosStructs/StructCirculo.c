// Define una estructura llamada Circulo para representar un círculo con un único miembro:
// radio. Escribe un programa en C para calcular el área y el perímetro de dos círculos y
// mostrar los resultados.
// Pista:
// Área = π * radio²
// Perímetro = 2 * π * radio
// Usa M_PI de math.h o define #define PI 3.1416.

#include <stdio.h>
#include <string.h>
#include <math.h>

#define PI 3.1416

typedef struct
{
    float radio;
} Circle;

typedef struct
{
    float perimetro;
    float area;
} Resolves;

void pedirRadios(Circle c[])
{
    for (int i = 0; i < 2; i++)
    {
        printf("Circulo #%d\n", i + 1);
        printf("Ingrese el radio\n");
        scanf("%f", &c[i].radio);
    }
}

void calcularPerimetroYArea(Circle c[], Resolves r[])
{
    for (int i = 0; i < 2; i++)
    {
        r[i].perimetro = 2 * PI * c[i].radio;
        r[i].area = PI * (c[i].radio * c[i].radio);
    }
}

int main()
{
    Circle circulos[2];
    pedirRadios(circulos);
    Resolves resultados[2];
    calcularPerimetroYArea(circulos, resultados);

    printf("Primer circulo\n");
    printf("Area:%.2f\n", resultados[0].area);
    printf("Perimetro:%.2f\n", resultados[0].perimetro);
    printf("Segundo circulo\n");
    printf("Area:%.2f\n", resultados[1].area);
    printf("Perimemtro:%.2f\n", resultados[1].perimetro);
    return 0;
}