#include <stdio.h>
int main(){
    int num1, num2, num3 = 0;

    printf("Ingrese un numero\n");
    scanf("%d", &num1);
    printf("Ingrese un segundo numero\n");
    scanf("%d", &num2);
    printf("Ingrese un tercer numero\n");
    scanf("%d", &num3);

    if (num1 == num2 && num1 == num3 && num2 == num3)
    {
        printf("Los numeros son iguales");
    }else if(num1 > num2 && num1 > num3){
        printf("%d, es el numero mayor\n", num1);
    }else if(num2 > num1 && num2 > num3){
        printf("%d, es el numero mayor\n", num2);
    }else{
        printf("%d, es el numero mayor\n", num3);
    }
    return 0;
    
}