#include <stdio.h>

typedef struct
{
    int record;
    char name[30];
    float salary;
} Employee;

void showEmployees(Employee e[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d - %s - $%.2f\n", e[i].record, e[i].name, e[i].salary);
    }
}

void sortEmployees(Employee e[], int size)
{
    // se comienza en 1 porque se asume que el primero esta ordenado
    for (int i = 1; i < size; i++)
    {
        Employee key = e[i];
        int j = i - 1; // <- el valor de la izquierda

        // Mientras el valor de j sea mayor o gual a 0 y el valor de la key sea menor al valor actual
        while (j >= 0 && key.record < e[j].record)
        {
            // desplazamos el numero a la derecha
            e[j + 1] = e[j];
            j--;
        }

        // en la ultima iteracion del while j entra valiendo 0 y al restarle 1 termina en -1, por eso se suma una
        e[j + 1] = key; // <- almacenamos el empleado en el lugar correcto
    }
}

int binarySearch(Employee e[], int size, int target)
{
    int left = 0;
    int rigt = size - 1;

    while (left <= rigt)
    {
        // Calcular el medio
        int mid = left + (rigt - left) / 2;

        if (e[mid].record == target)
        {
            return mid;
        }
        else if (e[mid].record < target)
        {
            left = mid + 1;
        }
        else
        {
            rigt = mid - 1;
        }
    }
    return -1;
}

void searchEmployee(Employee e[], int size, int target)
{
    sortEmployees(e, size);

    int res = binarySearch(e, size, target);
    if (res == -1)
    {
        printf("No se pudo encontrar el empleado solicitado\n");
    }
    else
    {
        printf("Empleado encontrado:\n");
        printf("%d - %s - %.2f\n", e[res].record, e[res].name, e[res].salary);
    }
}

void increaseSalaries(Employee e[], int size, float porcentage)
{
    for (int i = 0; i < size; i++)
    {
        e[i].salary += e[i].salary * (porcentage / 100);
    }
}

int main()
{
    Employee employees[] = {
        {1, "Juan Perez", 35000.0},
        {2, "Maria Gomez", 42000.5},
        {3, "Carlos Ruiz", 39000.75},
        {4, "Ana Torres", 41000.0},
        {5, "Luis Fernandez", 37000.25}};

    int size = sizeof(employees) / sizeof(employees[0]);

    showEmployees(employees, size);

    searchEmployee(employees, size, 4);

    increaseSalaries(employees, size, 10);
    printf("Luego de aumentar los sueldos\n");
    showEmployees(employees, size);

    return 0;
}