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
#include <ctype.h>

typedef struct
{
    char name[20];
    int code;
    char cat;
    float salary;
} Employee;

typedef struct
{
    float A;
    float B;
    float C;
} TotalSalariesByCategory;

typedef struct
{
    int employeesOver20k;
    int employeesBelow5k_C;
    int bestPaidEmployeeCode;
    float minSalary;
    float totalSalaries;
    TotalSalariesByCategory TotalAmount;
    float averageSalary;
    int employeesNamedJuan[200];

} Report;

void convertToLowercase(char *str)
{
    while (*str != '\0')
    {
        *str = tolower(*str);
        str++;
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
    Report R = {0, 0, e[0].code, e[0].salary, 0};
    R.TotalAmount.A = 0;
    R.TotalAmount.B = 0;
    R.TotalAmount.C = 0;

    int higher = e[0].salary,
        lower = e[0].salary;

    int j = 0; // -> Posicion para el array de empleados llamados Juan
    for (int i = 0; i < size; i++)
    {

        // Suma de los salarios para calcular el promedio
        R.averageSalary += e[i].salary;

        // Total de salarios pagados por la empresa
        R.totalSalaries += e[i].salary;

        // Convertimos el nombre a minuscula
        char tempName[20];
        strcpy(tempName, e[i].name);  // <- Copiamos el nombre, para no modificar el original
        convertToLowercase(tempName); // <- Convertimos el nombre temporal a minuscula

        // Si el nombre es Juan
        if (strcmp(tempName, "juan") == 0)
        {
            // Guarda el codigo
            R.employeesNamedJuan[j] = i;
            j++;
        }
        // Marcamos el final para poder recorrerlo despues
        R.employeesNamedJuan[j] = -1;

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

        // Importe total de salarios por categoría
        switch (tolower(e[i].cat))
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
    }
    // Importe total de salarios divido cantidad de empleados
    R.averageSalary /= size;
    return R;
}
int main()
{
    Employee employees[] = {
        {"Juan", 1, 'A', 25000.0},
        {"Pedro", 2, 'B', 15000.0},
        {"María", 3, 'C', 10000.0},
        {"Antonio", 4, 'A', 20000.0},
        {"Ana", 5, 'B', 12000.0},
        {"Sofía", 6, 'C', 8000.0},
        {"Luis", 7, 'A', 30000.0},
        {"Sandra", 8, 'B', 18000.0},
        {"Fernando", 9, 'C', 6000.0},
        {"Lucía", 10, 'A', 22000.0},
        {"Miguel", 11, 'B', 14000.0},
        {"Natalia", 12, 'C', 9000.0},
        {"Alejandro", 13, 'A', 28000.0},
        {"Elena", 14, 'B', 16000.0},
        {"Gabriel", 15, 'C', 7000.0},
        {"Valeria", 16, 'A', 24000.0},
        {"Ignacio", 17, 'B', 13000.0},
        {"Daniela", 18, 'C', 11000.0},
        {"Rodrigo", 19, 'A', 26000.0},
        {"Laura", 20, 'B', 15000.0},
        {"Pablo", 21, 'C', 10000.0},
        {"Cecilia", 22, 'A', 20000.0},
        {"Santiago", 23, 'B', 12000.0},
        {"Florencia", 24, 'C', 8000.0},
        {"Matías", 25, 'A', 30000.0},
        {"Victoria", 26, 'B', 18000.0},
        {"Lautaro", 27, 'C', 6000.0},
        {"Julieta", 28, 'A', 22000.0},
        {"Bautista", 29, 'B', 14000.0},
        {"Guadalupe", 30, 'C', 9000.0},
        {"Martín", 31, 'A', 28000.0},
        {"Delfina", 32, 'B', 16000.0},
        {"Agustina", 33, 'C', 7000.0},
        {"Tomás", 34, 'A', 24000.0},
        {"Mariana", 35, 'B', 13000.0},
        {"Francisco", 36, 'C', 11000.0},
        {"Lucas", 37, 'A', 26000.0},
        {"Ximena", 38, 'B', 15000.0},
        {"Benjamín", 39, 'C', 10000.0},
        {"Emilia", 40, 'A', 20000.0},
        {"Gabriela", 41, 'B', 12000.0},
        {"Santiago", 42, 'C', 8000.0},
        {"Sebastián", 43, 'A', 30000.0},
        {"Catalina", 44, 'B', 18000.0},
        {"Matías", 45, 'C', 6000.0},
        {"Nicolás", 46, 'A', 22000.0},
        {"Sofía", 47, 'B', 14000.0},
        {"Leticia", 48, 'C', 9000.0},
        {"Aarón", 49, 'A', 28000.0},
        {"Gonzalo", 50, 'B', 16000.0},
        {"Marcelo", 51, 'C', 7000.0},
        {"Elian", 52, 'A', 24000.0},
        {"Eduardo", 53, 'B', 13000.0},
        {"Alexis", 54, 'C', 11000.0},
        {"Sofía", 55, 'A', 26000.0},
        {"Guillermo", 56, 'B', 15000.0},
        {"Florencia", 57, 'C', 10000.0},
        {"María", 58, 'A', 20000.0},
        {"Lucas", 59, 'B', 12000.0},
        {"Cecilia", 60, 'C', 8000.0},
        {"Santiago", 61, 'A', 30000.0},
        {"Mariana", 62, 'B', 18000.0},
        {"Ignacio", 63, 'C', 6000.0},
        {"Daniela", 64, 'A', 22000.0},
        {"Gonzalo", 65, 'B', 14000.0},
        {"Leticia", 66, 'C', 9000.0},
        {"María", 67, 'A', 28000.0},
        {"Gonzalo", 68, 'B', 16000.0},
        {"Marcelo", 69, 'C', 7000.0},
        {"Elian", 70, 'A', 24000.0},
        {"Eduardo", 71, 'B', 13000.0},
        {"Alexis", 72, 'C', 11000.0},
        {"Sofía", 73, 'A', 26000.0},
        {"Guillermo", 74, 'B', 15000.0},
        {"Florencia", 75, 'C', 10000.0},
        {"María", 76, 'A', 20000.0},
        {"Lucas", 77, 'B', 12000.0},
        {"Cecilia", 78, 'C', 8000.0},
        {"Santiago", 79, 'A', 30000.0},
        {"Mariana", 80, 'B', 18000.0},
        {"Ignacio", 81, 'C', 6000.0},
        {"Daniela", 82, 'A', 22000.0},
        {"Gonzalo", 83, 'B', 14000.0},
        {"Leticia", 84, 'C', 9000.0},
        {"María", 85, 'A', 28000.0},
        {"Gonzalo", 86, 'B', 16000.0},
        {"Marcelo", 87, 'C', 7000.0},
        {"Elian", 88, 'A', 24000.0},
        {"Eduardo", 89, 'B', 13000.0},
        {"Alexis", 90, 'C', 11000.0},
        {"Sofía", 91, 'A', 26000.0},
        {"Guillermo", 92, 'B', 15000.0},
        {"Florencia", 93, 'C', 10000.0},
        {"María", 94, 'A', 20000.0},
        {"Lucas", 95, 'B', 12000.0},
        {"Cecilia", 96, 'C', 8000.0},
        {"Santiago", 97, 'A', 30000.0},
        {"Mariana", 98, 'B', 18000.0},
        {"Ignacio", 99, 'C', 6000.0},
        {"Daniela", 100, 'A', 22000.0},
        {"Gonzalo", 101, 'B', 14000.0},
        {"Leticia", 102, 'C', 9000.0},
        {"María", 103, 'A', 28000.0},
        {"Gonzalo", 104, 'B', 16000.0},
        {"Marcelo", 105, 'C', 7000.0},
        {"Elian", 106, 'A', 24000.0},
        {"Eduardo", 107, 'B', 13000.0},
        {"Alexis", 108, 'C', 11000.0},
        {"Sofía", 109, 'A', 26000.0},
        {"Guillermo", 110, 'B', 15000.0},

    };

    int size = sizeof(employees) / sizeof(employees[0]); // <- Tamaño del array

    // reqData(employees, size);

    // Obtenemos el reporte
    Report report = getReport(employees, size);
    printf("Reporte\n");
    printf("Empleados con mas de 20k de sueldo: %d\n", report.employeesOver20k);
    printf("Empleados con menos de 5k y categoria C: %d\n", report.employeesBelow5k_C);
    printf("Codigo del empleado con el salario mas alto: %d\n", report.bestPaidEmployeeCode);
    printf("Salario mas bajo: %.2f\n", report.minSalary);
    printf("Importe total de salarios pagados por la empresa: %.2f\n", report.totalSalaries);
    printf("Importe total de salarios por categoria\n");
    printf("A: %.2f\n", report.TotalAmount.A);
    printf("B: %.2f\n", report.TotalAmount.B);
    printf("C: %.2f\n", report.TotalAmount.C);
    printf("Salario promedio: %.2f\n", report.averageSalary);
    // si en la primer posicion del array de empleados llamados Juan hay un -1, significa que no hay empleados llamados Juan
    if (report.employeesNamedJuan[0] != -1)
    {
        printf("Empleados con el nombre Juan\n");
        int i = 0;
        while (report.employeesNamedJuan[i] != -1)
        {
            printf("Nombre: %s\n", employees[report.employeesNamedJuan[i]].name);
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