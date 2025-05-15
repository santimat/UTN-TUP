// Para la gestión de los libros de una pequeña biblioteca es preciso conocer su título, su
// autor,y año de edición y si está prestado o no.
// Escribir un programa en C que:
// a) Defina una estructura denominada fichaLibro que permita almacenar los datos de
// cualquier libro
// b) Declarare e inicialice dos variables del tipo fichaLibro
// c) Compruebe si las variables declaradas representan ejemplares de un mismo libro o de
// libros distintos.

#include <stdio.h>
#include <string.h>

typedef struct
{
    char title[60];
    char author[40];
    int loaned;
} Book;

int areSame(Book b1, Book b2)
{
    return strcmp(b1.title, b2.title);
}

int main()
{
    // Dos variables inicializadas de tipo Book
    Book book1 = {"El principito", "Antoine de Saint-Exupery", 1};
    Book book2 = {"Cien años de soledad", "Gabriel Garcia Marquez", 0};
    if (areSame(book1, book2) == 0)
    {
        printf("Son los mismos libros");
    }
    else
    {
        printf("Son distintos");
    }

    return 0;
}