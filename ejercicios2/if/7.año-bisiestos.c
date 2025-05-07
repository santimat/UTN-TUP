#include <stdio.h>
int main(){
    int year = 0;
    printf("Ingrese un year\n");
    scanf("%d", &year);

    if (year % 4 == 0)
    {
        printf("%d es bisiesto\n", year);
    }else{
        printf("%d no es bisiesto\n",year);
    }
    return 0;
    
}