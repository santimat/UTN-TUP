#include <stdio.h>
void guardarNumeros(int nums[], int largo);
void mostrarMenorYMayor(int nums[], int largo);

int main()
{
    int largo = 5;
    int nums[largo];
    guardarNumeros(nums, largo);
    mostrarMenorYMayor(nums, largo);
    return 0;
}

void guardarNumeros(int nums[], int largo)
{
    for (int i = 0; i < largo; i++)
    {
        printf("Ingrese el #%d numero\n", i + 1);
        scanf("%d", &nums[i]);
    }
}

void mostrarMenorYMayor(int nums[], int largo)
{
    int mayor = nums[0];
    int menor = nums[0];
    for (int i = 1; i < largo; i++)
    {
        if (nums[i] > mayor)
        {
            mayor = nums[i];
        }
        if (nums[i] < menor)
        {
            menor = nums[i];
        }
    }

    printf("Mayor: %d\n", mayor);
    printf("Menor: %d\n", menor);
}