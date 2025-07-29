#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarArray(int nums[], int longitud);
void invertirArray(int nums[],int numsInvertido[], int longitud);
void mostrarArrays(int nums[], int longitud);

int main(){
    srand(time(NULL));

    int longitud = 7;
    int nums[longitud];
    cargarArray(nums, longitud);

    int numsInvertidos[longitud];
    invertirArray(nums,numsInvertidos, longitud);

    printf("Array original\n");
    mostrarArrays(nums, longitud);
    printf("Array invertido\n");
    mostrarArrays(numsInvertidos, longitud);

    return 0;
}

void cargarArray(int nums[], int longitud)
{
    for (int i = 0; i < longitud; i++)
    {
        int ran = rand() % 101;;
        nums[i] = ran;
    }
}

void invertirArray(int nums[],int numsInvertidos[], int longitud)
{
    int j = 0;
    for (int i = longitud - 1; i >= 0; i--)
    {
        numsInvertidos[j] = nums[i];
        j++;
    }
}

void mostrarArrays(int nums[], int longitud)
{
    for (int i = 0; i < longitud; i++)
    {
        printf(" %d |", nums[i]);
    }
    printf("\n");
}