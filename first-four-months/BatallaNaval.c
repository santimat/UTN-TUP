#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void limpiarBufferEntrada();
void limpiarConsolaANSI();

void inicializarTablero(char t[][6]);
void cargarBarcosMaquina(char t[][6], int barcos);
void cargarBarcosJugador(char t[][6], int barcos);

void imprimirMatriz(char t[][6], int opt);
int disparoJugador(char t[][6]);
int disparoMaquina(char t[][6]);

void iniciarJuego(char tM[][6], char tJ[][6]);

int main()
{
    srand(time(NULL)); // semilla para numeros aleatorios

    // tablero maquina
    char tableroM[6][6];
    inicializarTablero(tableroM);
    cargarBarcosMaquina(tableroM, 4);

    // tablero jugador
    char tableroJ[6][6];
    inicializarTablero(tableroJ);
    limpiarConsolaANSI();
    cargarBarcosJugador(tableroJ, 4);

    iniciarJuego(tableroM, tableroJ);
    return 0;
}

void limpiarBufferEntrada()
{
    int c;
    // Lee caracteres del buffer hasta encontrar un salto de línea o el fin de archivo
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // No hace nada con el carácter, simplemente lo descarta
    }
}

void limpiarConsolaANSI()
{
    printf("\x1b[2J\x1b[H"); // Limpia la pantalla y posiciona el cursor
}

void imprimirMatriz(char t[][6], int opt)
{
    printf("   1  2  3  4  5  6\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", i + 1);
        for (int j = 0; j < 6; j++)
        {
            if (opt != 1 && t[i][j] == 'B')
            {
                printf(" ~ ");
            }
            else
            {
                printf(" %c ", t[i][j]);
            }
        }
        printf("\n");
    }
}

// llenar de "agua" el tablero
void inicializarTablero(char t[][6])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            t[i][j] = '~'; // <- agua
        }
    }
}

void cargarBarcosMaquina(char t[][6], int barcos)
{
    int n = 0; // cantidad de barcos agregados
    while (n < barcos)
    {
        int fila = rand() % 6, columna = rand() % 6;
        // si no hay un barco
        if (t[fila][columna] != 'B')
        {
            t[fila][columna] = 'B';
            n++;
        }
    }
}

int verificarCoordenadas(char t[][6], int fila, int columna)
{
    // resto 1 porque el usuario va ingresar en rango 1-6
    fila--;
    columna--;

    if (fila > 6 || fila < 0 || columna > 6 || columna < 0)
    {
        return -1; // cordenadas invalidas
    }

    char disparo = t[fila][columna];
    if (disparo == 'B')
    {
        return 1; // barco
    }
    else if (disparo == 'O' || disparo == 'X')
    {
        return 2; // ya marcado o hundido
    }
    // agua
    return 3;
}

int verificarBarcos(char t[][6])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (t[i][j] == 'B')
            {
                return 1; // quedan barcos
            }
        }
    }
    return 0; // no hay barcos
}

void modificarTablero(char t[][6], int fila, int columna, char txt)
{
    t[fila - 1][columna - 1] = txt;
}

void cargarBarcosJugador(char t[][6], int barcos)
{
    int n = 0;
    imprimirMatriz(t, 1);
    do
    {
        int fila = 0, columna = 0;
        printf("Ingrese fila (1-6): ");
        scanf("%d", &fila);
        printf("Ingrese columna (1-6): ");
        scanf("%d", &columna);
        limpiarBufferEntrada();

        int res = verificarCoordenadas(t, fila, columna);
        if (res == -1)
        {
            printf("Coordenadas invalidas, intente de nuevo\n");
        }
        else if (res == 1)
        {
            printf("Coordenada ocupada, intenta con otra\n");
        }
        else
        {
            modificarTablero(t, fila, columna, 'B');
            n++;
        }

    } while (n < barcos);
    imprimirMatriz(t, 1);
}

int disparoJugador(char t[][6])
{
    int exit = 0;
    do
    {
        int quedanBarcos = verificarBarcos(t);
        if (!quedanBarcos)
        {
            printf("El jugador ha ganado");
            return 1;
        }

        int fila, columna;
        printf("Ingresar fila (1-6): ");
        scanf("%d", &fila);
        printf("Ingresar columna (1-6): ");
        scanf("%d", &columna);
        limpiarBufferEntrada();
        int res = verificarCoordenadas(t, fila, columna);
        if (res == -1)
        {
            printf("Coordenada invalida ingrese de nuevo\n");
        }
        else if (res == 1)
        {
            printf("Haz acertado!\n");
            modificarTablero(t, fila, columna, 'X');
            exit = 1;
        }
        else if (res == 2)
        {
            printf("Ya has disparado en esa posicion\n");
        }
        else
        {
            printf("Haz fallado!\n");
            modificarTablero(t, fila, columna, 'O');
            exit = 1;
        }

    } while (exit == 0);
}

int disparoMaquina(char t[][6])
{
    int exit = 0;
    printf("pensando disparo...\n");
    Sleep(550);
    do
    {

        int quedanBarcos = verificarBarcos(t);
        if (!quedanBarcos)
        {
            printf("La maquina ha ganado");
            return 1;
        }

        // sumo uno siguiendo la logica de que el usuario ingresa entre 1-6
        int fila = (rand() % 6) + 1, columna = (rand() % 6) + 1;

        int res = verificarCoordenadas(t, fila, columna);
        if (res == 1)
        {
            printf("La maquina ha acertado\n");
            modificarTablero(t, fila, columna, 'X');
            exit = 1;
        }
        else if (res == 3)
        {
            printf("La maquina ha fallado\n");
            modificarTablero(t, fila, columna, 'O');
            exit = 1;
        }

    } while (exit == 0);
}

void iniciarJuego(char tM[][6], char tJ[][6])
{
    printf("Ingrese enter para iniciar\n");
    getchar();

    int intentos = 0;
    int ganador = 0;
    do
    {
        limpiarConsolaANSI();
        printf("Tablero del jugador\n");
        imprimirMatriz(tJ, 1); // opt = 1, se muestran los barcos
        printf("\n");
        printf("Tablero de la maquina\n");
        imprimirMatriz(tM, 2); // opt != 1, ocultar barcos

        // intentos pares va el usuario
        if (intentos == 0 || intentos % 2 == 0)
        {
            printf("Turno del jugador\n");
            if (disparoJugador(tM) == 1)
            {
                ganador = 1;
            }
        }
        else // impares la maquina
        {
            printf("Turno de la maquina\n");
            if (disparoMaquina(tJ) == 1)
            {
                ganador = 2;
            }
        }
        // si hubo un ganador se termina el bucle
        if (ganador != 0)
        {
            break;
        }

        intentos++;

        Sleep(2000);

    } while (1);

    printf("Gracias por jugar!! :p");
}