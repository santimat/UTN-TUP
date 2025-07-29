#include <stdio.h>
int main()
{
    int num = 0, sum = 0, numMayor = 0, numMenor = 0, pares = 0, impares = 0, cont = 0;
    float promedio = 0;
    do
    {
        printf("Ingrese un numero\n");
        scanf("%d", &num);

        if (num != 0)
        {
            if (cont == 0)
            {
                numMenor = num;
            }

            sum += num;
            cont++;
            promedio = sum / (float)cont;

            if (num > numMayor)
            {
                numMayor = num;
            }
            else if (num < numMenor)
            {
                numMenor = num;
            }

            if (num % 2 == 0)
            {
                pares++;
            }
            else
            {
                impares++;
            }
        }
        else
        {
            printf("La suma total de los numeros ingresados es: %d\n", sum);
            printf("El promedio de los numeros es: %.2f\n", promedio);
            printf("El numero mayor es: %d\n", numMayor);
            printf("El numero menor es: %d\n", numMenor);
            printf("Cantidad de pares: %d\n", pares);
            printf("Cantidad de impares: %d\n", impares);
        }

    } while (num != 0);
}