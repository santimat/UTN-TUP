#include <stdio.h>
#include <string.h>

typedef struct
{
    char title[100];
    char isbn[10];
    char author[50];
    char editorial[50];
    int borrowed; // 0 = not borrowed, 1 = borrowed
} Book;

void sortBooks(Book b[], int *size)
{
    for (int i = 1; i < *size; i++)
    {
        Book key = b[i];
        int j = i - 1;

        while (j >= 0 && strcmp(b[j].isbn, key.isbn) > 0)
        {
            b[j + 1] = b[j];
            j--;
        }
        b[j + 1] = key;
    }
}

int binarySearch(Book b[], int size, char target[])
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (strcmp(b[mid].isbn, target) == 0)
        {
            return mid;
        }
        else if (strcmp(b[mid].isbn, target) < 0)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    // En caso de que no se encuentre
    return -1;
}

void initLibrary(Book b[], int *size)
{
    strcpy(b[0].title, "C Programming Language");
    strcpy(b[0].isbn, "1234");
    strcpy(b[0].author, "Brian W. Kernighan");
    strcpy(b[0].editorial, "Prentice Hall");
    b[0].borrowed = 0;

    strcpy(b[1].title, "Clean Code");
    strcpy(b[1].isbn, "2456");
    strcpy(b[1].author, "Robert C. Martin");
    strcpy(b[1].editorial, "Prentice Hall");
    b[1].borrowed = 1;

    strcpy(b[2].title, "The Pragmatic Programmer");
    strcpy(b[2].isbn, "1111");
    strcpy(b[2].author, "Andrew Hunt");
    strcpy(b[2].editorial, "Addison-Wesley");
    b[2].borrowed = 0;

    *size = 3;
}

void createBook(Book b[], int *size)
{
    Book newBook;
    printf("Ingrese el ISBN del libro (4 digitos): ");
    scanf(" %[^\n]", newBook.isbn);

    printf("Ingrese el titulo: ");
    scanf(" %[^\n]", newBook.title);

    printf("Ingrese el autor: ");
    scanf(" %[^\n]", newBook.author);

    printf("Ingrese la editorial: ");
    scanf(" %[^\n]", newBook.editorial);

    printf("Ingrese el estado del libro\n");
    printf("1. Prestado\n");
    printf("2. Disponible\n");
    scanf("%d", &newBook.borrowed);

    b[*size] = newBook;
    (*size)++;
}

void showBooks(Book b[], int size)
{
    sortBooks(b, &size);
    for (int i = 0; i < size; i++)
    {
        printf("══════════════════════════════════════\n");
        printf("ISBN: %s\n", b[i].isbn);
        printf("Titulo: %s\n", b[i].title);
        printf("Autor: %s\n", b[i].author);
        printf("Editorial: %s\n", b[i].editorial);
        printf("Estado: %s\n", b[i].borrowed ? "Prestado" : "Disponible"); // <- operador ternario
        printf("══════════════════════════════════════\n");
    }
}

void lendBook(Book b[], int size)
{
    showBooks(b, size);

    char target[5];
    printf("Ingrese el ISBN del libro que desea modificar su estado:\n");
    scanf("%s", target);

    int option = 0;
    printf("╔══════════════════════════════════════╗\n");
    printf("║          Modificar estado            ║\n");
    printf("║══════════════════════════════════════║\n");
    printf("║    1. Prestar libro                  ║\n");
    printf("║    2. Marcar como disponible         ║\n");
    printf("╚══════════════════════════════════════╝\n");
    scanf("%d", &option);

    int bookIdx = binarySearch(b, size, target);

    if (b[bookIdx].borrowed == 0 && option == 1)
    {
        b[bookIdx].borrowed = 1;
        printf("Libro prestado!\n");
    }
    else if (b[bookIdx].borrowed == 1 && option == 2)
    {
        b[bookIdx].borrowed = 0;
        printf("Marcado como disponible!\n");
    }
    else
    {
        printf("El libro ya se encuentra prestado\n");
    }
}

void updateBook(Book b[], int size)
{
    showBooks(b, size);

    char target[5];
    printf("Ingrese el ISBN del libro que desea modificar\n");
    scanf("%s", target);
    int bookIdx = binarySearch(b, size, target);

    int option = 0;
    do
    {
        printf("╔══════════════════════════════════════╗\n");
        printf("║          Modificar libro             ║\n");
        printf("║══════════════════════════════════════║\n");
        printf("║       1. Titulo                      ║\n");
        printf("║       2. Autor                       ║\n");
        printf("║       3. Editorial                   ║\n");
        printf("║       4. Salir                       ║\n");
        printf("╚══════════════════════════════════════╝\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Ingrese el nuevo titulo\n");
            scanf(" %[^\n]", b[bookIdx].title);
            printf("Titulo modificado\n");
            break;
        case 2:
            printf("Ingrese el nuevo autor\n");
            scanf(" %[^\n]", b[bookIdx].author);
            printf("Autor modificado\n");
            break;
        case 3:
            printf("Ingrese la nueva editorial\n");
            scanf(" %[^\n]", b[bookIdx].editorial);
            printf("Editorial modificado\n");
            break;
        }

    } while (option != 4);
}

void searchBook(Book b[], int size)
{
    printf("Ingrese el ISBN, del libro que desea buscar\n");
    char target[10];
    scanf("%s", target);

    int bookIdx = binarySearch(b, size, target);
    // -1 si no se encuentra
    if (bookIdx != -1)
    {
        printf("ISBN: %s\n", b[bookIdx].isbn);
        printf("Titulo: %s\n", b[bookIdx].title);
        printf("Autor: %s\n", b[bookIdx].author);
        printf("Editorial: %s\n", b[bookIdx].editorial);
        printf("Estado: %s\n", b[bookIdx].borrowed ? "Prestado" : "Disponible");
    }
    else
    {
        printf("Libro no encontrado\n");
    }
}

void showMenu(Book b[], int *size)
{
    int option = 0;
    do
    {
        printf("╔══════════════════════════════════════╗\n");
        printf("║         BIBLIOTECA DE LIBROS         ║\n");
        printf("║══════════════════════════════════════║\n");
        printf("║    1. Agregar un libro               ║\n");
        printf("║    2. Mostrar libros                 ║\n");
        printf("║    3. Prestar un libro               ║\n");
        printf("║    4. Modificar un libro             ║\n");
        printf("║    5. Buscar un libro por isbn       ║\n");
        printf("║    6. Salir                          ║\n");
        printf("╚══════════════════════════════════════╝\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            createBook(b, size);
            break;
        case 2:
            showBooks(b, *size);
            break;
        case 3:
            lendBook(b, *size);
            break;
        case 4:
            updateBook(b, *size);
            break;
        case 5:
            searchBook(b, *size);
            break;
        }
    } while (option != 6);
}

int main()
{
    int size = 0;
    Book books[100];
    initLibrary(books, &size);
    showMenu(books, &size);

    return 0;
}