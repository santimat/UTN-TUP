#include <stdio.h>
int main(){
    int edad = 0;
    printf("Ingrese su edad\n");
    scanf("%d",&edad);

    if (edad >= 18)
    {
        printf("Podes votar\n");
    }else if(edad >= 16 && edad <= 17){
        printf("Podes votar con permiso de tus padres\n");
    }else if(edad < 16){
        printf("No podes votar\n");
    }
    return 0;       
}
