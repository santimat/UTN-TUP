#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{

    char name[50];
    char phone[15];
    char email[50];
    int cat; // 1 -> familia, 2 -> trabajo, 3 -> amigos
} Contact;

void addContact(Contact c[], int pos, int *size)
{
    Contact newContact;
    printf("Ingrese el nombre del contacto:\n");
    scanf("%s", newContact.name);
    printf("Ingrese el numero de telefono:\n");
    scanf("%s", newContact.phone);
    printf("Ingrese el email del contacto\n");
    scanf("%s", newContact.email);
    int cat = 0;

    printf("Ingrese la categoria:\n");
    printf("1. Familiar");
    printf("2. Trabajo");
    printf("3. Amigos");
    scanf("%d", &cat);
    while (cat != 1 && cat != 2 && cat != 3)
    {
        printf("Categoria invalida ingrese de nuevo\n");
        scanf("%d", &cat);
    }
    newContact.cat = cat;

    c[pos] = newContact;
    (*size)++;
}

void showContact(Contact c)
{
    printf("╔══════════════════════════════════════╗\n");
    printf("    Nombre: %s\n", c.name);
    printf("    Telefono: %s \n", c.phone);
    printf("    Email: %s\n", c.email);
    switch (c.cat)
    {
    case 1:
        printf("    Familiar\n");
        break;
    case 2:
        printf("    Trabajo\n");
        break;
    case 3:
        printf("    Amigo\n");
        break;
    }
    printf("╚══════════════════════════════════════╝ \n");
}

void showByCat(Contact c[], int size)
{
    int cat = 0;
    printf("Ingrese la categoria que desea buscar\n");
    scanf("%d", &cat);
    while (cat != 1 && cat != 2 && cat != 3)
    {

        printf("Categoria invalida ingrese de nuevo\n");
        scanf("%d", &cat);
    }

    for (int i = 0; i < size; i++)
    {
        if (c[i].cat == cat)
        {
            showContact(c[i]);
        }
    }
}

void bubbleSort(Contact c[], int size)
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (
                strcmp(c[j].name, c[j + 1].name) > 0)
            {
                Contact temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

int amountPCat(Contact c[], int size)
{
    int cat = 0;
    printf("Ingrese la categoria que desea buscar\n");
    scanf("%d", &cat);
    while (cat != 1 && cat != 2 && cat != 3)
    {

        printf("Categoria invalida ingrese de nuevo\n");
        scanf("%d", &cat);
    }

    int amount = 0;
    for (int i = 0; i < size; i++)
    {
        if (c[i].cat == cat)
        {
            amount++;
        }
    }
    printf("Hay %d contactos en la categoria buscada\n", amount);
}

void showMenu(Contact c[], int size)
{
    int option = 0;
    do
    {
        printf("╔══════════════════════════════════════════╗\n");
        printf("                     MENU               \n");
        printf("    1. Mostrar todos los contactos\n");
        printf("    2. Buscar por categoria\n");
        printf("    3. Ordenar y mostrar por nombre\n");
        printf("    4. Contar contactos por categoria\n");
        printf("    5. Salir\n");
        printf("╚══════════════════════════════════════════╝ \n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            for (int i = 0; i < size; i++)
            {
                showContact(c[i]);
            }
            break;
        case 2:
            showByCat(c, size);
            break;
        case 3:
            bubbleSort(c, size);
            for (int i = 0; i < size; i++)
            {
                showContact(c[i]);
            }
            break;
        case 4:
            amountPCat(c, size);
            break;
        default:
            printf("Cerrando...");
            break;
        }
    } while (option != 5);
}

int main()
{
    Contact contacts[10];
    Contact c1 = {"Juan", "123456789", "juan@mail.com", 1};
    Contact c2 = {"Ana", "987654321", "ana@mail.com", 2};
    Contact c3 = {"Luis", "555555555", "luis@mail.com", 3};
    Contact c4 = {"Maria", "444444444", "maria@mail.com", 1};
    Contact c5 = {"Pedro", "333333333", "pedro@mail.com", 2};

    contacts[0] = c1;
    contacts[1] = c2;
    contacts[2] = c3;
    contacts[3] = c4;
    contacts[4] = c5;

    int size = 5;
    showMenu(contacts, size);
    return 0;
}