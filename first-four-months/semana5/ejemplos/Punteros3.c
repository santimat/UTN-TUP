#include <stdio.h>

int main()
{
    int nums[3] = {1, 2, 3};
    int *p = nums;
    printf("Contenido del array: %d\n", *p);
    printf("Direccion de memoria del array: %p\n", p);
    return 0;
}
