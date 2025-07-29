// Una fábrica de tornillos nos ha solicitado desarrollar un programa en C que permita
// obtener e imprimir las estadísticas de una determinada muestra de tornillos. Para ello nos
// indican que cada tornillo viene caracterizado por su longitud y su diámetro y que ambas
// medidas deben almacenarse en un registro o struct con dos campos.
// Desarrollar un programa en C que:
// a) Solicite al usuario los datos de una muestra de tornillos (longitud y diámetro) y los
// almacene en un array.
// b) A partir de los datos introducidos calcule y muestre por pantalla la media de las
// longitudes y la media de los diámetros.
// Nota: El tamaño de la muestra se definirá como una constante denomina
// TAMANIO_MUESTRA.

#include <stdio.h>

#define SAMPLE_SIZE 2

typedef struct
{
    float length;
    float diameter;
} Screw;

void pedirDatos(Screw t[])
{
    for (int i = 0; i < SAMPLE_SIZE; i++)
    {
        printf("Tornillo #i\n", i + 1);
        printf("Ingrese la longitud del tornillo:\n");
        scanf("%f", &t[i].length);
        printf("Ingrese el diametro del tornillo:\n");
        scanf("%f", &t[i].diameter);
    }
}

Screw calcularMedia(Screw t[])
{
    Screw tornilloMedia;
    for (int i = 0; i < SAMPLE_SIZE; i++)
    {
        tornilloMedia.length += t[i].length;
        tornilloMedia.diameter += t[i].diameter;
    }
    tornilloMedia.length = tornilloMedia.length / (float)SAMPLE_SIZE;
    tornilloMedia.diameter = tornilloMedia.diameter / (float)SAMPLE_SIZE;
    return tornilloMedia;
}
int main()
{
    Screw tornillos[SAMPLE_SIZE];
    pedirDatos(tornillos);
    Screw mediaTornillo = calcularMedia(tornillos);
    printf("La longitud de media de los tornillos es de %.2f\n", mediaTornillo.length);
    printf("El diametro de media de los tornillos es de %.2f\n", mediaTornillo.diameter);
    return 0;
}