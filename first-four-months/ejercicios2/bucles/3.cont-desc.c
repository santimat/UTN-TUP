#include <stdio.h>

int main(){
    int i= 10;
    do{
        printf("%d\n",i);
        i--;
        if (i == 0)
        {
            printf("Terminamos de contar\n");
        }
        
    }while (i > 0);
    
}