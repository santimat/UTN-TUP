#include <stdio.h>
#include <string.h>

typedef struct
{
    char title[100];
    char isbn[10];
    char author[50];
    char editorial[50];
    int belowed; // 0 = not belowed, 1 = belowed
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
        int mid = left + (right - left);

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
    b[0].belowed = 0;

    strcpy(b[1].title, "Clean Code");
    strcpy(b[1].isbn, "2456");
    strcpy(b[1].author, "Robert C. Martin");
    strcpy(b[1].editorial, "Prentice Hall");
    b[1].belowed = 1;

    strcpy(b[2].title, "The Pragmatic Programmer");
    strcpy(b[2].isbn, "1111");
    strcpy(b[2].author, "Andrew Hunt");
    strcpy(b[2].editorial, "Addison-Wesley");
    b[2].belowed = 0;

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
    scanf("%d", &newBook.belowed);

    b[*size] = newBook;
    (*size)++;
    sortBooks(b, size);
}

void showBooks(Book b[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("ISBN: %s\n", b[i].isbn);
        printf("Titulo: %s\n", b[i].title);
        printf("Autor: %s\n", b[i].author);
        printf("Editorial: %s\n", b[i].editorial);
        if (b[i].belowed == 1)
        {
            printf("Libro prestado\n");
        }
        else
        {
            printf("Libro disponible\n");
        }
        printf("===========================\n");
    }
}

void lendBook(Book b[], int size)
{
    sortBooks(b, &size);
    char target[4];
    int option = 0;
    showBooks(b, size);
    printf("Ingrese el ISBN del libro que desea prestar:\n");
    scanf("%s", target);
    printf("Ingrese 1 para prestar, 2 para marcar como disponible\n");
    scanf("%d", &option);
    int bookIdx = binarySearch(b, size, target);

    if (b[bookIdx].belowed == 0 && option == 1)
    {
        b[bookIdx].belowed = 1;
        printf("Libro prestado!\n");
    }
    else if (b[bookIdx].belowed == 1 && option == 2)
    {
        b[bookIdx].belowed = 0;
        printf("Marcado como disponible!\n");
    }
    else
    {
        printf("El libro ya se encuentra prestado\n");
    }
}

void updateBook()
{
}

void searchBook()
{
}

void showMenu(Book b[], int *size)
{
    int option = 0;
    do
    {
        printf("Seleccione una opcion\n");
        printf("1. Crear un libro\n");
        printf("2. Listar todos los libros\n");
        printf("3. Prestar un libro\n");
        printf("4. Modificar un libro\n");
        printf("5. Buscar un libro por isbn\n");
        printf("6. Salir\n");
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
            // updateBook();
            break;
        case 5:
            // searchBook();
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