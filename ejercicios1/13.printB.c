#include <stdio.h>

int main(){
    for (int i = 1; i <= 9; i++)
    {
        if (i == 1 || i== 5 || i == 9)
        {
            for (int j = 0; j < 6; j++)
            {
                printf("*");
            }
        }else{
            printf("*\t*");
        }
        printf("\n");
    }
}