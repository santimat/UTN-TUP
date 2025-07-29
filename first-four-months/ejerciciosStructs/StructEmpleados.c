// Crea una estructura llamada Empleado para almacenar los detalles de un empleado: ID,
// nombre y salario. Escribe un programa en C para ingresar los datos de cinco empleados
// en un array, encontrar el que tiene el salario más alto y mostrar su información.

#include <stdio.h>

typedef struct
{
    int id;
    char name[40];
    float salary;

} Employee;

void pedirDatos(Employee empleados[], int cantidadEmpleados)
{
    for (int i = 0; i < cantidadEmpleados; i++)
    {
        printf("Empleado #%d\n", i + 1);
        printf("Ingrese el id del empleado:\n");
        scanf("%d", &empleados[i].id);
        printf("Ingrese el nombre del empleado:\n");
        scanf("%s", empleados[i].name);
        printf("Ingrese el salario del empleado:\n");
        scanf("%f", &empleados[i].salary);
    }
}

int empleadoConMejorSalario(Employee empleados[], int cantidadEmpleados)
{
    int idx = 0, mayor = 0;

    for (int i = 0; i < cantidadEmpleados; i++)
    {
        if (empleados[i].salary > mayor)
        {
            mayor = empleados[i].salary;
            idx = i;
        }
    }
    return idx;
}

int main()
{
    int cantidadEmpleados = 3;
    Employee empleados[cantidadEmpleados];
    pedirDatos(empleados, cantidadEmpleados);
    int idx = empleadoConMejorSalario(empleados, cantidadEmpleados);
    printf("Informacion del empleado con mejor sueldo\n");
    printf("Id:%d\nNombre:%s\nSalario:%f\n", empleados[idx].id, empleados[idx].name, empleados[idx].salary);
    return 0;
}