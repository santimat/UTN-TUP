#include <stdio.h>
#include <string.h>

// Con el typedef podemos crear un alias para una estructura, de esta forma evitamos el uso de la palabra struct al crear la estructura

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    char name[30];
    int age;
    float height;
    Date birthday;
} Person;

int isEqual(Person p1, Person p2)
{
    // strcmp es para comprar strings, si retorna 0 es porque son iguales, comparamos si el name, la edad y la altura son iguales
    // strcmp lo coloque a lo ultimo porque las comparaciones entre primitivos son más rapidas, de esta forma podemos mejorar el rendimiento
    return p1.age == p2.age && p1.height == p2.height && strcmp(p1.name, p2.name) == 0; // <- retorna 0 o 1
}

void birthday(Date today, Person *person)
{
    // si el mes actual y el dia actual son iguales al mes y dia del cumpleaños de la persona
    if (today.month == person->birthday.month && today.day == person->birthday.day)
    {
        // aumentamos su edad en 1
        person->age++;
    }
}
int main()
{
    Date today = {8, 12, 2025};
    Person person = {
        "Santino",
        21,
        1.75,
        {8,
         12,
         2003}}; // <- struct dentro de una struct};
    Person person2 = {"Santino", 22, 1.75};

    if (isEqual(person, person2) != 0)
    {
        printf("Las personas son iguales\n");
    }
    else
    {
        printf("Las personas son diferentes\n");
    }
    printf("Antes del cumpleaños %d\n", person.age);
    birthday(today, &person);
    printf("Despues del cumpleaños %d\n", person.age);
    return 0;
}