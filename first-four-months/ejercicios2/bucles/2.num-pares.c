#include <stdio.h>
int main(){
    int pares = 0, cont = 0;
    while (cont <= 20)
    {
        if (cont % 2 == 0)
        {
            printf("%d es par\n", cont);
            pares++;
        }
        cont++;
        
    }
    printf("Cantidad de pares: %d",pares);
}