#include <stdio.h>
// int trunca la parte con coma, ej 2.5 -> 2

int binarySearch(int size, int nums[], int target)
{
    // Tanto izquierda y derecha van a ir cambiando a medida que partimos la busqueda
    // La izquierda arranca en 0 porque va a ser el principio
    int izquierda = 0;
    // El final del array
    int derecha = size - 1;

    while (izquierda <= derecha)
    {
        // Calculamos el medio del array
        // A izquierda le sumamos la diferencia entre la posicion final y la de inicio, para evitar desbordamientos
        int medio = izquierda + (derecha - izquierda) / 2;

        if (nums[medio] == target)
        {
            // Retornamos el medio porque solo queremos saber si el numero está o no
            return medio;
        }
        // restamos y sumamos 1 a medio, porque anteriormente ya revisamos en esa posicion
        else if (nums[medio] < target)
        {
            izquierda = medio + 1; // si el numero del medio es menor al target tenemos que buscar del medio para la derecha
        }
        else
        {
            derecha = medio - 1; // si el numero del medio es mayor al target buscamos del medio para la izquierda
        }
    }
    // En caso de que no exista el target
    return -1;
}
int main()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // Calculamos el tamaño del array, sizeof nos devuelve la cantida de bytes total que ocupan todos los elementos, y lo dividimos por el valor en bytes de uno de sus elementos.
    // por ejemplo un int tiene un tamaño de 4 bytes, por lo que el sizeof del array numeros serían 40 bytes, al dividir 40 por 4 nos da 10 que sería la cantidad de elementos que tenemos en nuestro array
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int target = 5;
    int found = binarySearch(size, numbers, target);
    if (found != -1)
    {
        printf("El %d se encuentra en la posicion %d\n", target, found);
    }
    else
    {
        printf("El %d no se encuentra el array\n", target);
    }
    return 0;
}