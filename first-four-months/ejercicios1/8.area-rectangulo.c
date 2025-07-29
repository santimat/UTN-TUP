#include <stdio.h>

int main()
{
    float base, altura, area = 0;
    printf("Ingrese la base y altura del triangulo separados por coma:\n");
    scanf("%f,%f", &base, &altura);
    area = base * altura;
    printf("El area del rectangulo es: %.2f", area);
    return 0;
}