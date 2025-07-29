#include <stdio.h>

int main(){
    int lado1,lado2,lado3 = 0;

    printf("Ingrese el lado de un triangulo\n");
    scanf("%i",&lado1);

    printf("Ingrese el otro lado de un triangulo\n");
    scanf("%i",&lado2);

    printf("Ingrese el ultimo lado de un triangulo\n");
    scanf("%i",&lado3);


    if (lado1 == lado2 && lado1 == lado3 && lado2 == lado3)
    {
        printf("Triangulo equilatero\n");
    }else if(lado1 == lado2 && (lado1 + lado2) > lado3){
        printf("Triangulo isoceles\n");
    }else if (lado1 != lado2 && lado1 != lado3 && lado2 != lado3){
        printf("Triangulo escaleno\n");
    }else{
        printf("Triangulo no valido\n");
    }
    return 0;
}