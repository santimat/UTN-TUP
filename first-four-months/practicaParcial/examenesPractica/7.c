// pedir al usuario 8 numeros y guardarlos en un array, luego calcular el promedio de los numeros impares
#include <stdio.h>

int main()
{

    int largo = 8;
    int nums[largo];
    int i = 0;
    do
    {
        int num = 0;
        printf("Ingrese el #%d numero\n", i + 1);
        scanf("%d", &num);
        if (num > 0 && num < 101)
        {
            nums[i] = num;
            i++;
        }
        else
        {
            printf("El numero debe estar entre 1 y 100\n");
        }

    } while (i < largo);

    int suma = 0;
    int impares = 0;
    for (int i = 0; i < largo; i++)
    {
        if (nums[i] % 2 != 0)
        {
            suma += nums[i];
            impares++;
        }
    }
    float promedio = (float)suma / impares;
    printf("El promedio de los numeros impares es %2.f\n", promedio);
}