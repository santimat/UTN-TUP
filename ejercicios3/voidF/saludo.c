#include <stdio.h>

void saludo();
void saludo2(char *name);

int main()
{

    // saludo();
    char name[20];
    printf("Ingrese su nombre\n");
    scanf("%s", name);

    saludo2(name);
    return 0;
}

void saludo()
{
    printf("Hola bienvenido a C\n");
}

void saludo2(char *name)
{
    printf("Hola %s bienvenido a C", name);
}