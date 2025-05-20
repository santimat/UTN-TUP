// Queremos guardar los nombres y las edades y nota de 40 alumnos de un curso:
// a) Realiza un programa que introduzca el nombre y la edad de cada alumno
// El proceso de lectura de datos terminará cuando se introduzca como nombre un asterisco
// (*)
// b) Al finalizar se mostrará los siguientes datos:
// Cantidad de alumnos que tienen más de 30 años, el promedio de las notas de todos los
// alumnos.

#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[20];
    int age;
    float note;
} Student;

void reqData(Student s[], int size)
{
    int i = 0;
    do
    {
        char tempName[20];

        printf("Alumno #%d\n", i + 1);
        printf("Ingrese el nombre del alumno:\n");
        scanf("%s", tempName);

        // si el nombre ingresado es asterisco
        if (strcmp(tempName, "*") == 0)
        {
            break; // <- termina el bucle
        }
        else // <- si no es asterisco
        {
            // guarda el nombre
            strcpy(s[i].name, tempName);
        }
        printf("Ingrese la edad del alumno:\n");
        scanf("%d", &s[i].age);
        printf("Ingrese la nota del alumno:\n");
        scanf("%f", &s[i].note);
        i++;
    } while (i < 40);
}

void showData(Student s[], int size)
{
    int studentsOver30 = 0;
    float notesSum = 0;

    for (int i = 0; i < size; i++)
    {
        if (s[i].age > 30)
        {
            studentsOver30++;
        }
        notesSum += s[i].note;
    }

    printf("Alumnos con mas de 30 anios: %d\n", studentsOver30);
    printf("Promedio de notas: %.2f\n", notesSum / size);
}
int main()
{
    Student students[] = {
        {"Juan", 25, 8.5},
        {"Maria", 32, 9.0},
        {"Carlos", 28, 7.5},
        {"Ana", 35, 9.2},
        {"Luis", 29, 6.8},
        {"Eva", 31, 8.1},
        {"Pedro", 24, 7.9},
        {"Sofia", 27, 8.3},
        {"Mateo", 22, 7.0},
        {"Lucia", 30, 8.7},
        {"Julia", 26, 7.4},
        {"Miguel", 33, 8.0},
        {"Laura", 21, 7.9},
        {"Victor", 34, 8.6},
        {"Elena", 28, 7.2},
        {"Manuel", 31, 8.5},
        {"Clara", 23, 8.0},
        {"Adrian", 27, 7.8},
        {"Carmen", 25, 8.1},
        {"Ramon", 29, 7.5},
        {"Isabel", 30, 8.4},
        {"Pablo", 32, 6.9},
        {"Rosa", 26, 8.3},
        {"Javier", 28, 7.6},
        {"Sara", 24, 8.2},
        {"Raul", 31, 7.7},
        {"Cristina", 20, 8.8},
        {"Alberto", 29, 7.1},
        {"Beatriz", 33, 6.7},
        {"Francisco", 22, 8.0},
        {"Alicia", 27, 7.3},
        {"Oscar", 30, 8.9},
        {"Patricia", 34, 7.4},
        {"Fernando", 25, 8.7},
        {"Monica", 28, 6.5},
        {"Ivan", 31, 8.6},
        {"Teresa", 32, 7.0},
        {"Andres", 23, 8.1},
        {"Silvia", 26, 7.9},
        {"Roberto", 29, 8.2}};

    // obtenemos la longitud de la array diviendo el tamaño completo en bytes del array de alumnos, divido por lo que ocupa cada elemento.
    int size = sizeof(students) / sizeof(students[0]);
    // reqData(students, size);
    showData(students, size);
    return 0;
}