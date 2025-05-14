#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[30];
    int edad;
    char date[40];
} Person;

void mostrarPersonas(Person personas[], int persons)
{
    for (int i = 0; i < persons; i++)
    {
        printf("Persona #%d\n", i + 1);
        printf("Nombre: %s\n", personas[i].name);
        printf("Edad %d\n", personas[i].edad);
        printf("Nacimiento: %s\n", personas[i].date);
    }
}

void llenarPersonas(Person personas[], int persons)
{
    for (int i = 0; i < persons; i++)
    {
        printf("Persona %d\n", i + 1);
        printf("Ingrese nombre\n");
        scanf("%s", personas[i].name);
        printf("Ingrese edad\n");
        scanf("%d", &personas[i].edad);
        printf("Ingrese date\n");
        scanf("%s", personas[i].date);
    }
}
int main()
{
    int persons = 2;
    Person personas[persons]; // <- 3 personas
    // strcpy(personas[0].name, "santino");
    // personas[0].edad = 21;
    // strcpy(personas[0].date, "8/12/2003");

    // strcpy(personas[1].name, "juan");
    // personas[1].edad = 22;
    // strcpy(personas[1].date, "8/9/2002");

    // strcpy(personas[2].name, "pedro");
    // personas[2].edad = 48;
    // strcpy(personas[2].date, "8/12/1996");

    llenarPersonas(personas, persons);
    mostrarPersonas(personas, persons);
    return 0;
}