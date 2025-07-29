#include <stdio.h>

int main(){
    int num = 0;
    printf("Ingrese el numero del cual quiere obtener la tabla\n");
    scanf("%d",&num);
    for (int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n",num, i, num * i);
    }
    
}