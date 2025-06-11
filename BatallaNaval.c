#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirMatriz(char tablero[][6], int opt)
{
    if (opt == 1)
    {

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                printf("%c ", tablero[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {

                if (tablero[i][j] == 'B')
                {
                    printf("-");
                }
                printf("%c ", tablero[i][j]);
            }
            printf("\n");
        }
    }
}

void initMatriz(char tablero[][6])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            tablero[i][j] = '-';
        }
    }
}

int initBarcos(char tablero[6][6])
{
    int cont = 0;
    do
    {
        int fila = rand() % 6;
        int columna = rand() % 6;

        if (tablero[fila][columna] != 'B')
        {
            tablero[fila][columna] = 'B';
            cont++;
        }

    } while (cont != 3);
}

int verificarCoordenadas(char tablero[][6], int coords[])
{
    int disparo = tablero[coords[0] - 1][coords[1] - 1];
    if (disparo == 'B')
    {
        return 1;
    }
    else if (disparo = '-')
    {
        return 2;
    }

    return 0;
}

void modificarTablero(char tablero[][6], int coords[], int txt)
{
    tablero[coords[0] - 1][coords[1] - 1] = txt;
}

int verificarTablero(char tablero[][6])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tablero[i][j] == 'B')
            {
                return 1;
            }
        }
    }
    return 0;
}

void colocarBarcos(char tableroJ[][6])
{
    int barcos = 0;
    do
    {
        int coords[2]; // pos 0 fila, pos 1 columna

        printf("Ingrese la fila donde desea colocar el barco\n");
        scanf("%d", &coords[0]);

        printf("Ingrese la columna\n");
        scanf("%d", &coords[1]);

        int res = verificarCoordenadas(tableroJ, coords);
        if (res == 1)
        {
            printf("Coordenada ocupada, reintente\n");
            continue;
        }

        modificarTablero(tableroJ, coords, 'B');
        barcos++;
    } while (barcos != 4);
}

void dispararJugador(char tablero[][6])
{
    int coords[2];
    printf("Ingrese fila\n");
    scanf("%d", &coords[0]);
    printf("Ingrese columna\n");
    scanf("%d", &coords[1]);

    int res = verificarCoordenadas(tablero, coords);
    if (res == 1)
    {
        printf("Acertaste\n");
        modificarTablero(tablero, coords, 'X');
    }
    else if (res == 2)
    {
        printf("AGUA\n");
        modificarTablero(tablero, coords, 'O');
    }
    else
    {
        printf("Ya haz dado en esa posicion\n");
    }
}

void disparoMaquina(char tablero[][6])
{
    int coords[] = {rand() % 6, rand() % 6};
    int res = verificarCoordenadas(tablero, coords);
    if (res == 1)
    {
        printf("La maquina a acertado\n");
        modificarTablero(tablero, coords, 'X');
    }
    else if (res == 2)
    {
        printf("La maquina a fallado\n");
        modificarTablero(tablero, coords, 'O');
    }
}

void iniciarJuego(char tableroJ[][6], char tableroM[][6])
{
    do
    {
        int coords[2];
        printf("Turno del jugador\n");
        printf("Fila: \n");
        scanf("%d", &coords[0]);
        printf("Columna: \n");
        scanf("%d", &coords[1]);

    } while ();
}

int main()
{
    srand(time(NULL));

    char tableroM[6][6];
    char tableroJ[6][6];

    // tablero de la maquina
    initMatriz(tableroM);
    initBarcos(tableroM);

    // tablero del jugador
    colocarBarcos(tableroJ);

    iniciarJuego(tableroM, tableroJ);

    return 0;
}