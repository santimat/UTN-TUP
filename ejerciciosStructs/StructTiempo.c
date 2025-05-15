// Define una estructura llamada Tiempo con los miembros: horas, minutos y segundos.
// Escribe un programa en C que permita ingresar dos tiempos, los sume y muestre el
// resultado en formato de hora correcta.

#include <stdio.h>
#include <string.h>

typedef struct
{
    int horas;
    int minutos;
    int segundos;
} Time;

void leerTiempos(Time tiempos[])
{

    for (int i = 0; i < 2; i++)
    {
        printf("Tiempo #%d\n", i + 1);
        printf("Ingrese las horas\n");
        scanf("%d", &tiempos[i].horas);
        printf("Ingrese los minutos\n");
        scanf("%d", &tiempos[i].minutos);
        printf("Ingrese los segundos\n");
        scanf("%d", &tiempos[i].segundos);
    }
}

void normalizar(Time *t)
{
    if (t->segundos >= 60)
    {
        // sumamos la cantidad de minutos que obtenemos con los segundos totales
        t->minutos += t->segundos / 60;
        // agregamos los segundos restando
        t->segundos = t->segundos % 60;
    }
    if (t->minutos >= 60)
    {
        t->horas += t->minutos / 60;
        t->minutos = t->minutos % 60;
    }
}

Time sumarTiempos(Time tiempos[], Time *tiempoResultado)
{
    tiempoResultado->horas = tiempos[0].horas + tiempos[1].horas;
    tiempoResultado->minutos = tiempos[0].minutos + tiempos[1].minutos;
    tiempoResultado->segundos = tiempos[0].segundos + tiempos[1].segundos;
}
int main()
{
    Time tiempos[2];
    Time tiempoResultado;
    leerTiempos(tiempos);
    sumarTiempos(tiempos, &tiempoResultado);
    normalizar(&tiempoResultado);

    printf("%dh %dm %ds", tiempoResultado.horas, tiempoResultado.minutos, tiempoResultado.segundos);
    return 0;
}