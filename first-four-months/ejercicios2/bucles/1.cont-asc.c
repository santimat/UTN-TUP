#include <stdio.h>

int main(){
    int res = 0;
    for (int i = 0; i <= 10; i++)
    {
        printf("%i\n", i);
        res += i;
    }
    printf("La suma es: %d\n", res);
}