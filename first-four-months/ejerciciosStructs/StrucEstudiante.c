// Crea una estructura llamada Estudiante con los miembros: nombre, edad y legajo.
// Declara e inicializa dos estudiantes y muestra su información por pantalla.

#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[40];
    int age;
    int legajo;

} Student;
int main()
{
    Student e1 = {"santino", 21, 16433};
    Student e2 = {"valen", 20, 254230};

    printf("Primer alumno\n");
    printf("Nombre:%s\nEdad:%d\nLegajo:%d\n", e1.name, e1.age, e1.legajo);
    printf("Segundo alumno\n");
    printf("Nombre:%s\nEdad:%d\nLegajo:%d\n", e2.name, e2.age, e2.legajo);

    return 0;
}