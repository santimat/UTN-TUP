#include <stdio.h>

int main()
{
    float celsius, fahrenheit = 0;
    printf("Ingrese la temperatura en celsius:\n");
    scanf("%f", &celsius);
    fahrenheit = toFahrenheit(celsius);
    printf("Su temperatura en celsius equivale a %.2f fahrenheit", fahrenheit);
    return 0;
}

float toFahrenheit(celsius)
{
    return (celsius * 5 / 9) + 32;
}