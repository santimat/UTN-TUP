#include <stdio.h>

int main()
{
    int rows = 0;
    printf("Ingrese la altura de la piramide\n");
    scanf("%i", &rows);

    // Por la forma en la que se lee el codigo, primero inicializa el for de las filas, dentro de cada fila, primero vamos a imprimir los espacios necesarios, una vez esten los espacios, pasamos a imprimir los asteriscos correspondientes para cada fila.

    // Bucle que se va a ejecutar por cada columna, este agregaria los saltos de linea
    for (int i = 1; i <= rows; i++)
    {
        // Este calculo va a imprimir los espacios, en la primera vuelta imprime 4 espacios, en la segunda 3 y asi se le va restando el iterador del primer for, de esta forma por cada fila tenemos un espacio menos
        for (int j = 1; j <= rows - i; j++)
        {
            printf(" "); // <- espacio en blanco para centrar los asteriscos
        }

        // Bucle para imprimir los asteriscos
        // i -> el numero de fila actual
        // * 2 -> porque por cada fila se agregan dos asteriscos
        // - 1 -> porque i inicializa en 1, entonces sería en la primer vuelta (1 * 2) - 1 = 1, en la segunda (2 * 2) - 1 = 3, en la tercera (3 * 2) - 1 = 5
        for (int l = 1; l <= (i * 2) - 1; l++)
        {
            printf("*"); // <- imprimimos los asteriscos
        }
        printf("\n"); // <- new line
    }
    return 0;
}
