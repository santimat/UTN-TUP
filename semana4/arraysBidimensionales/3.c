#include <stdio.h>
#include <string.h>

void fillMatrix(int alumnos[][3]);
void showMatrix(int alumnos[][3]);

int main()
{
    int alumnos[3][3];
    fillMatrix(alumnos);
    showMatrix(alumnos);
}

void fillMatrix(int alumnos[][3])
{
    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            printf("Programacion\n");
            break;
        case 1:
            printf("Alimentos\n");
            break;
        case 2:
            printf("Seguridad e higiene\n");
            break;
        }
        for (int j = 0; j < 3; j++)
        {
            printf("Cantidad de alumnos en %do\n", j + 1);
            scanf("%d", &alumnos[i][j]);
        }
    }
}

void showMatrix(int alumnos[][3])
{
    int totalGeneral = 0;
    int carreraMayor = 0;
    for (int i = 0; i < 3; i++)
    {
        int totalAlumnos = 0;
        int totalPeryear = 0;
        int mayorAlumnos = 0;
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", alumnos[i][j]);
            totalAlumnos += alumnos[i][j];
            totalPeryear += alumnos[j][i];
            totalGeneral += alumnos[i][j];
            if (totalAlumnos > mayorAlumnos)
            {
                mayorAlumnos = totalAlumnos;
                carreraMayor = i;
            }
        }
        switch (i)
        {
        case 0:
            printf("<-- Total de alumnos en programacion %d\n", totalAlumnos);
            printf("En primero hay un total de %d alumnos\n", totalPeryear);
            break;
        case 1:
            printf("<-- Total de alumnos en alimentos %d\n", totalAlumnos);
            printf("En segundo hay un total de %d alumnos\n", totalPeryear);
            break;
        case 2:
            printf("<-- Total de alumnos en seguridad e higiene %d\n", totalAlumnos);
            printf("En tercero hay un total de %d alumnos\n", totalPeryear);
            break;
        }
        printf("\n");
    }
    char msg[] = "La carrera con mas alumnos es la de ";
    switch (carreraMayor)
    {
    case 0:
        strcat(msg, "programacion");
        printf("%s\n", msg);
        break;
    case 1:
        strcat(msg, "alimentos");
        printf("%s\n", msg);
        break;
    case 2:
        strcat(msg, "seguridad e higiene");
        printf("%s\n", msg);
        break;
    }
    printf("\n");
    printf("El total general de alumnos es %d\n", totalGeneral);
}

// En un centro universitario hay 3 carreras: Programación, Alimentos y Seguridad e
// higiene. Cada carrera tiene 3 años.
// Crea una matriz de 3x3 que almacene la cantidad de alumnos por año y carrera.
// Luego mostrala como tabla y calculá:
// • La cantidad total de alumnos por carrera (suma por fila).
// • La cantidad total por año (suma por columna).
// • La carrera con mayor cantidad de alumnos.
// • El total general de estudiantes.