#include <stdio.h>
#include <stdlib.h>

void guardarNombres(char equipos[][20]);
void guadarPuntos(int puntos[][4], char equipos[][20]);
void calcularTotales(int puntos[][4], int totales[]);
void mostrarTabla(int puntos[][4], char equipos[][20], int totales[]);
void mostrarGanador(int totales[], char equipos[][20]);
void calcularDiferencia(int puntos[][4], int indices[]);

int main()
{
    int puntos[2][4];
    char equipos[2][20];
    int totales[2] = {0, 0};
    int indices[2] = {0, 0};

    guardarNombres(equipos);
    guadarPuntos(puntos, equipos);
    calcularTotales(puntos, totales);

    mostrarTabla(puntos, equipos, totales);
    mostrarGanador(totales, equipos);
    calcularDiferencia(puntos, indices);
    printf("El cuarto con mayor diferencia fue el #%d", indices[0]);
    printf("El cuarto con la diferencia mas pareja fue el #%d", indices[1]);
    return 0;
}

void guardarNombres(char equipos[][20])
{
    for (int i = 0; i < 2; i++)
    {
        printf("Ingrese el nombre del #%d equipo\n", i + 1);
        scanf("%s", equipos[i]);
    }
}

void guadarPuntos(int puntos[][4], char equipos[][20])
{
    for (int i = 0; i < 2; i++)
    {
        printf("Equipo: %s\n", equipos[i]);
        for (int j = 0; j < 4; j++)
        {
            printf("Ingrese los puntos del #%d cuarto\n", j + 1);
            scanf("%d", &puntos[i][j]);
        }
    }
}

void calcularTotales(int puntos[][4], int totales[])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            totales[i] += puntos[i][j];
        }
    }
}

void mostrarTabla(int puntos[][4], char equipos[][20], int totales[])
{
    printf("\t");
    for (int i = 0; i < 4; i++)
    {
        printf("%15d", i + 1);
    }
    printf("%15s", "Total");

    printf("\n");
    for (int i = 0; i < 2; i++)
    {
        printf("%15s", equipos[i]);
        for (int j = 0; j < 4; j++)
        {
            printf("%15d", puntos[i][j]);
        }
        printf("%15d", totales[i]);
        printf("\n");
    }
}

void mostrarGanador(int totales[], char equipos[][20])
{
    if (totales[0] > totales[1])
    {
        printf("El ganador es el equipo %s\n", equipos[0]);
    }
    else
    {
        printf("El ganador es el equipo %s\n", equipos[1]);
    }
}
void calcularDiferencia(int puntos[][4], int indices[])
{
    int mayor = 0, menor = 10000;

    for (int i = 0; i < 4; i++)
    {
        int res = abs(puntos[0][i] - puntos[1][i]);
        if (res > mayor)
        {
            mayor = res;
            indices[0] = i + 1;
        }
        if (res < menor)
        {
            menor = res;
            indices[1] = i + 1;
        }
    }
}