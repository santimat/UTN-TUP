#include <stdio.h>

int main(){

    int num1,num2 = 0;
    int opcion = 0;
    int exit = 0;
    printf("Ingrese un numero\n");
    scanf("%d",&num1);
    printf("Ingrese otro numero\n");
    scanf("%d",&num2);
    do
    {
        printf("1 -> para sumar dos numeros\n");
        printf("2 -> para restar dos numeros\n");
        printf("3 -> para multiplicar dos numeros\n");
        printf("4 -> para dividir dos numeros\n");
        printf("Presione cualquier otro caracter para salir\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("%d + %d = %d\n", num1,num2, num1 + num2);
            break;
        case 2:
            printf("%d - %d = %d\n", num1,num2, num1 - num2);
            break;
        case 3:
            printf("%d x %d = %d\n", num1, num2, num1 * num2);
            break;
        case 4:
            printf("%d / %d = %d\n", num1,num2, num1 / num2);
            break;
        default:
            printf("Saliendo...\n");
            exit = 1;
            break;
        }
    } while (exit != 1);
    
}