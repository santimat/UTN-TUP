#include <stdio.h>

int main(){
    int edad,mem = 0;

    printf("Ingrese su edad\n");
    scanf("%d", &edad);
    if (edad >= 18)
    {
        printf("Tiene membresia? 1 para si 0 para no\n");
        scanf("%d", &mem);
    }
    if (edad >= 18 && mem )
    {
        printf("Acceso permitido a la sala VIP\n");
    }else if(edad >= 18 && !mem){
        printf("Acceso permitido a la pista comun\n");
    }else{
        printf("Acceso denegado\n");
    }
    return 0;
}