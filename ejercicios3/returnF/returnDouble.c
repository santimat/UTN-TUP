#include <stdio.h>
double returnArea(double radio);

int main()
{
    double radio = 0;
    printf("Ingrese el radio del circulo\n");
    scanf("%lf", &radio);

    printf("El radio del circulo es: %.2lf", returnArea(radio));
}

double returnArea(double radio)
{
    return (3.1416 * (radio * radio));
}