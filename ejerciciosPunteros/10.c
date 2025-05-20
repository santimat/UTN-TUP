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
#include <string.h>

typedef struct
{
    char name[20];
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
    int employeesNamedJuan[200];

} Report;

void convertMinus(char *str)
{
    int i = 0;
    while (*(str + i) != '\0')
    {
        if (*(str + i) >= 'A' && *(str + i) <= 'Z')
        {
            *(str + i) += 32;
        }
        i++;
    }
}

void reqData(Employee e[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Empleado #%d\n", i + 1);
        printf("Ingrese el nombre del empleado:\n");
        scanf("%s", e[i].name);
        printf("Ingrese el codigo del empleado:\n");
        scanf("%d", &e[i].code);
        printf("Ingrese la categoria del empleado:\n");
        scanf(" %c", &e[i].cat);
        printf("Ingrese el salario del empleado:\n");
        scanf("%f", &e[i].salary);
    }
}

Report getReport(Employee e[], int size)
{
    Report R = {
        0,
        0,
        e[0].code,
        0};

    int higher = e[0].salary, lower = e[0].salary;
    for (int i = 0; i < size; i++)
    {

        // Suma de los salarios para calcular el promedio
        R.averageSalary += e[i].salary;
        convertMinus(e[i].name);
        // Si el nombre es Juan
        int j = 0;
        if (strcmp(e[i].name, "juan") == 0)
        {
            // Guarda el codigo
            R.employeesNamedJuan[j] = i;
            j++;
        }

        // Empleados +2k de sueldo
        if (e[i].salary > 20000)
        {
            R.employeesOver20k++;
        }

        // Empleados -5k y cat C
        if (e[i].salary < 5000 && e[i].cat == 'C')
        {
            R.employeesBelow5k_C++;
        }

        // Empleado con el salario más alto
        if (e[i].salary > higher)
        {
            R.bestPaidEmployeeCode = e[i].code;
            higher = e[i].salary;
        }

        // Salario más bajo
        if (e[i].salary < lower)
        {
            R.minSalary = e[i].salary;
            lower = e[i].salary;
        }

        convertMinus(&e[i].cat);
        // Importe total de salarios por categoría
        switch (e[i].cat)
        {
        case 'a':
            R.TotalAmount.A += e[i].salary;
            break;
        case 'b':
            R.TotalAmount.B += e[i].salary;
            break;
        case 'c':
            R.TotalAmount.C += e[i].salary;
            break;
        }
        // Importe total de salarios divido cantidad de empleados
        R.averageSalary /= size;

        return R;
    }
}
int main()
{
    int size = 5;
    Employee employees[size];
    reqData(employees, size);
    Report report = getReport(employees, size);
    printf("Reporte\n");
    printf("Empleados con mas de 20k de sueldo: %d\n", report.employeesOver20k);
    printf("Empleados con menos de 5k y categoria C: %d\n", report.employeesBelow5k_C);
    printf("Codigo del empleado con el salario mas alto: %d\n", report.bestPaidEmployeeCode);
    printf("Salario mas bajo: %.2f\n", report.minSalary);
    printf("Importe total de salarios por categoria\n");
    printf("A: %.2f\n", report.TotalAmount.A);
    printf("B: %.2f\n", report.TotalAmount.B);
    printf("C: %.2f\n", report.TotalAmount.C);
    printf("Salario promedio: %.2f\n", report.averageSalary);
    if (report.employeesNamedJuan[0] != 0)
    {
        printf("Empleados con el nombre Juan\n");
        int i = 0;
        while (report.employeesNamedJuan[i] != 0)
        {
            printf("Codigo: %d\n", employees[report.employeesNamedJuan[i]].code);
            printf("Categoria: %c\n", employees[report.employeesNamedJuan[i]].cat);
            printf("Salario: %.2f\n", employees[report.employeesNamedJuan[i]].salary);
            i++;
        }
    }
    else
    {
        printf("No hay empleados con el nombre Juan\n");
    }

    return 0;
}