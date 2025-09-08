package biblio1;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Libro libro1 = new Libro("Deja de ser tu", "Joe Dispenza", false);
        Libro libro2 = new Libro("El mundo de sofía", "Joestein Gaarder", true);
        Libro libro3 = new Libro("La felicidad", "Gabriel Rolon", false);
        Libro libro4 = new Libro("1984", "Orwell", true);

        ArrayList<Libro> libros = new ArrayList<Libro>(List.of(libro1, libro2, libro3, libro4));

        // Creamos la biblioteca
        Biblioteca biblioteca = new Biblioteca(libros);

        try {
            biblioteca.prestarLibro("Deja de ser tu");
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

        try {
            biblioteca.devolverLibro("La felicidad");
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

    }
}