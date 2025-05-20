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
    char cat;
    float salary;
} Employee;

typedef struct
{
    int A;
    int B;
    int C;
} TotalSalariesByCategory;

typedef struct
{
    int employeesOver20k;
    int employeesBelow5k_C;
    int bestPaidEmployeeCode;
    float minSalary;
    TotalSalariesByCategory TotalAmount;
    float averageSalary;
} Report;

void reqData(Employee e[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Empleado #i\n", i + 1);
        printf("Ingrese el codigo del empleado;\n");
        scanf("%d", &e[i].code);
        printf("Ingrese la categoria del empleado;\n");
        scanf("%c", e[i].cat);
        printf("Ingrese el salario del empleado;\n");
        scanf("%f", e[i].salary);
    }
}

Report getReport(Employee e[], int size)
{
    Report R = {
        0,
        0,
        e[0].code,
        {0, 0, 0},
        0};

    int higher = e[0].salary, lower = e[0].salary;
    for (int i = 0; i < size; i++)
    {
        if (e[i].salary > 20000)
        {
            R.employeesOver20k++;
        }
        if (e[i].salary < 5000 && e[i].cat == "C")
        {
            R.employeesBelow5k_C++;
        }
        if (e[i].salary > higher)
        {
            R.bestPaidEmployeeCode = e[i].code;
            higher = e[i].salary;
        }
        if (e[i].salary < lower)
        {
            R.minSalary = e[i].salary;
            lower = e[i].salary;
        }
    }
}
int main()
{
    int size = 5;
    Employee employees[size];
    reqData(employees, size);

    return 0;
}