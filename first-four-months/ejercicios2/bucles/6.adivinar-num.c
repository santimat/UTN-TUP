#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    // numero random del 0 al 101 = entre 0 y 100
    int random = rand() % 101;
    int intento = 0;
    int intentos = 1;
    int record = 0;
    int respuesta= 0;

    while (intentos <= 5)
    {
        printf("Adivine el numero entre 0 y 100, en 5 intentos\n");
        scanf("%d", &intento);

        if (intento == random)
        {
            printf("Haz acertado\n");
            record = intentos;
            intentos = 6;
        }else if(intento > random){
            printf("un poco mas abajo\n");
        }else if(intento < random){
            printf("un poco mas alto\n");
        }

        if (intentos == 5)
        {
            printf("No te quedan mas intentos\n");
            printf("Presiona 1 para volver a jugar, 2 para ver tu record, cualquier otro caracter para salir\n");
            scanf("%d",&respuesta);
            switch (respuesta)
            {
            case 1:
                intentos = 1;
                break;
            case 2:
                if (record == 0)
                    {
                    printf("Aun no has logrado acertar el numero\n");
                }else{
                    printf("Tu record es de %d intentos\n",record);
                }
                break;
            default:
                printf("Adios!\n");
                intentos = 6;
                break;
            }
            
        }else{
            printf("Intento numero %d\n",intentos);
        }
        intentos++;
    }
}