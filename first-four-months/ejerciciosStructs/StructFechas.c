// Define una estructura llamada Fecha con los miembros: día, mes y año. Escribe un
// programa en C que permita ingresar dos fechas y calcular la diferencia en días entre ellas.

#include <stdio.h>
#include <math.h>

typedef struct
{
    int day;
    int month;
    int year;

} Date;

void ingresarFechas(Date f[])
{
    for (int i = 0; i < 2; i++)
    {
        printf("Fecha #%d\n", i + 1);
        printf("Ingrese el dia\n");
        scanf("%d", &f[i].day);
        printf("Ingrese el mes\n");
        scanf("%d", &f[i].month);
        printf("Ingrese el year\n");
        scanf("%d", &f[i].year);
    }
}

int calcularDif(Date f[])
{
    int days[2];
    for (int i = 0; i < 2; i++)
    {
        days[i] = (f[i].month * 30) + (f[i].year * 365) + f[i].day;
    }

    return abs(days[0] - days[1]);
}
int main()
{
    Date fechas[2];
    ingresarFechas(fechas);
    int dif = calcularDif(fechas);

    printf("La diferencia de días es de %d", dif);
    return 0;
}