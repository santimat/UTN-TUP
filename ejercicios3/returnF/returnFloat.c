#include <stdio.h>
float returnArea(float base, float altura);
int main()
{
    float base, altura = 0;
    printf("Ingrese la base del triangulo\n");
    scanf("%f", &base);
    printf("Ingrese la altura del triangulo\n");
    scanf("%f", &altura);

    printf("El area de su triangulo es: %.1f", returnArea(base, altura));

    return 0;
}

float returnArea(float base, float altura)
{
    return ((base * altura) / 2);
}