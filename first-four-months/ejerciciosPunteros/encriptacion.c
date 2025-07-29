#include <stdio.h>

void encriptar(char *name)
{

    int i = 0;
    while (*(name + i) != '\0')
    {
        if (*(name + i) >= 'a' && *(name + i) <= 'n')
        {
            *(name + i) -= 3;
        }
        else if (*(name + i) >= 'o' && *(name + i) <= 'z')
        {
            *(name + i) += 3;
        }
        i++;
    }
}

void desencriptar(char *name)
{
    int i = 0;
    while (*(name + i) != '\0')
    {
        if (*(name + i) >= 'a' && *(name + i) <= 'n')
        {
            *(name + i) += 3;
        }
        else if (*(name + i) >= 'o' && *(name + i) <= 'z')
        {
            *(name + i) -= 3;
        }
        i++;
    }
}
int main()
{
    char name[] = "santino";

    printf("Nombre normal: %s", name);
    encriptar(name);

    printf("\nNombre encriptado: %s", name);

    desencriptar(name);

    return 0;
}