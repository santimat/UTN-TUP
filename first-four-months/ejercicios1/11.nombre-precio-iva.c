#include <stdio.h>

int main()
{

    const float IVA = 0.21;
    char nombreP[25] = "";
    float precioP, precioFinalP = 0;
    printf("Ingrese el nombre de su producto:\n");
    fgets(nombreP, 25, stdin);
    printf("Ingrese el precio de su producto:\n");
    scanf("%f", &precioP);
    printf("Producto: %s", nombreP);
    printf("Precio sin IVA: $%2.f\n", precioP);
    precioFinalP = precioP + (precioP * IVA);
    printf("Precio con IVA (21%%): $%2.f", precioFinalP);
    return 0;
}