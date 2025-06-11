#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirMatriz(char tablero[][6])
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

        if (tablero[fila][columna] != 'b')
        {
            tablero[fila][columna] = 'b';
            cont++;
        }

    } while (cont != 3);
}

int verificarCoordenadas(char tablero[][6], int coords[])
{
    if (tablero[coords[0] - 1][coords[1] - 1] == 'b')
    {
        return 1;
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
            if (tablero[i][j] == 'b')
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

        modificarTablero(tableroJ, coords, 'b');
        barcos++;
    } while (barcos != 4);
}

void dispararJugador(char tablero[][6])
{
    int intentos = 0;
    do
    {
        int res = verificarTablero(tablero);
        if (res == 1)
        {
            printf("Haz ganado eres un gigachad! :P \n");
            return;
        }

        int coords[2];
        printf("Ingrese fila\n");
        scanf("%d", &coords[0]);
        printf("Ingrese columna\n");
        scanf("%d", &coords[1]);

        int res = verificarCoordenadas(tablero, coords);
        if (res == 1)
        {
            modificarTablero(tablero, coords, 'X');
        }
        else
        {
            modificarTablero(tablero, coords, 'O');
        }
        intentos++;
    } while (intentos < 4);
}

void disparoMaquinola(char tablero[][6])
{
    int coords[] = {rand() % 6, rand() % 6};
    int res = verificarCoordenadas(tablero, coords);
    if (res == 1)
    {
        printf("La maquina a acertado\n");
        modificarTablero(tablero, coords, 'x');
    }
}

int main()
{
    srand(time(NULL));

    char tableroM[6][6];
    char tableroJ[6][6];

    // tablero de la maquina
    initMatriz(tableroM);
    imprimirMatriz(tableroM);
    initBarcos(tableroM);

    // tablero del jugador
    colocarBarcos(tableroJ);

    iniciarJuego(tableroM, tableroJ);

    return 0;
}