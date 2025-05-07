#include <stdio.h>

int main(){
    float temp = 0;

    printf("Ingrese la temperatura\n");
    scanf("%f", &temp);

    if (temp >= 15 && temp < 30)
    {
        printf("Clima templado\n");
    }else if(temp > 30){
        printf("Hace mucho calor\n");
    }else{
        printf("Hace frio\n");
    }
    return 0;
}