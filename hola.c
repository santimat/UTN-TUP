#include <stdio.h> // <- standar input output - lib con compilador que permite funciones de entrada salida

int main()
{
    int edad;
    float altura;
    char nombre[25];

    printf("Ingrese su nombre:\n");
    // scanf("%s", nombre); // <- el array de caracteres no lleva &
    fgets(nombre, 25, stdin);
    printf("Ingrese su edad:\n");
    scanf("%d", &edad); // <- el & apunta a la direccion de memoria donde está la variable
    printf("Ingrese su altura:\n");
    scanf("%f", &altura);

    printf("Hola %s \ntu edad es %d \ny tienes una altura de %.2f centimetros", nombre, edad, altura);
    return 0;
}