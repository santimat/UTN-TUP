// Una empresa cuenta con 200 empleados, divididos en tres categorías A, B y C.
// Por cada empleado se lee su Código, categoría y salario.
// Se solicita elaborar un informe que contenga:
// Importe total de salarios pagados por la empresa.
// Cantidad de empleados que ganan más de $20000.
// Cantidad de empleados que ganan menos de $5000, cuya categoría sea “C”.

// Código del empleado que más gana.
// Sueldo más bajo.
// Importe total de sueldos por cada categoría.
// Salario promedio.
// Mostrar todos los datos de empleado los empleados llamados “Juan”
// Tomar en cuenta que: Los Códigos serán de cuatro dígitos.

#include <stdio.h>

typedef struct
{
    int code;
    char category;
    float salary;
} Employee;

typedef struct
{
    int totalSalaries;
    int numEmployeesOver20000;
    int numEmployeesUnder5000CategoryC;
} Report;

int main()
{

    return 0;
}