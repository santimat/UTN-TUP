// Se tiene la siguiente declaración de struct:
// struct producto {
// int codigo;
// char descripcion[41];
// float precio;
// };
// Definir un array de 6 elementos de tipo producto.
// Implementar las funciones:
//  Cargar vector.
//  Imprimir del vector
//  Mostrar el nombre del artículo con precio mayor.

#include <stdio.h>

typedef struct
{
    int code;
    char desc[41];
    float price;
} Product;

void cargarVector(Product p[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("Producto #%d\n", i + 1);
        printf("Ingrese el codigo del producto:\n");
        scanf("%d", &p[i].code);
        printf("Ingrese la descripcion del producto:\n");
        scanf("%s", p[i].desc);
        printf("Ingrese el precio del producto:\n");
        scanf("%f", &p[i].price);
    }
}

void imprimirVector(Product p[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("Producto #%d", i + 1);
        printf("Codigo del producto: %d\n", p[i].code);
        printf("Descripcion del producto: %s\n", p[i].desc);
        printf("Precio del producto: %.2f\n", p[i].price);
    }
}

void mayorPrecio(Product p[], int length)
{
    int idx = 0, mayor = p[0].price;
    for (int i = 0; i < length; i++)
    {
        if (p[i].price > mayor)
        {
            idx = i;
            mayor = p[i].price;
        }
    }
    printf("Info del producto con mayor precio\n");
    printf("Codigo:%d\n", p[idx].code);
    printf("Descripcion:%s\n", p[idx].desc);
    printf("Precio:%.2f\n", p[idx].price);
}
int main()
{
    int length = 6;
    Product productos[length];
    cargarVector(productos, length);
    imprimirVector(productos, length);
    mayorPrecio(productos, length);
    return 0;
}