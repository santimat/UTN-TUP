package biblio2;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Libro libro1 = new Libro("Deja de ser tu", "Joe Dispenza", 2);
        Libro libro2 = new Libro("El mundo de sofía", "Joestein Gaarder", 3);
        Libro libro3 = new Libro("La felicidad", "Gabriel Rolon", 1);
        Libro libro4 = new Libro("1984", "Orwell", 2);

        ArrayList<Libro> libros = new ArrayList<Libro>(List.of(libro1, libro2, libro3, libro4));

        // Creamos la biblioteca
        Biblioteca biblioteca = new Biblioteca(libros);
        biblioteca.mostrarInventario();
    }
}