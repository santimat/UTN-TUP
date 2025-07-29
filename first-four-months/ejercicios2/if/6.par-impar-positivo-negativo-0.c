#include <stdio.h>
int main(){
    int num = 0;

    printf("Ingrese un numero\n");
    scanf("%d", &num);

    if (num % 2 == 0 && num > 0 )
    {
        printf("numero par y positivo\n");

    }else if (num % 2 == 0 && num < 0){
        printf("numero par y negativo\n");

    }else if (num % 2 != 0 && num > 0){
        printf("numero impar y positivo\n");

    }else if (num % 2 != 0 && num < 0){
        printf("numero impar y negativo\n");
    }
    return 0;
}