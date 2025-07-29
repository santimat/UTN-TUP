#include <stdio.h>

int main(){
    int time = 0;


    printf("Ingrese la hora (entre 0 y 23)");
    scanf("%d", &time);

    if (time >= 6 && time <= 11)
    {
        printf("Es de manana");
    }else if(time >= 12 && time <= 17){
        printf("Es de tarde");
    }else if(time>= 18 && time<= 23){
        printf("Es de noche");
    }else if(time >= 0 && time<= 5){
        printf("Es de madrugada");
    }else{
        printf("Hora no valida");
    }
    return 0;
}