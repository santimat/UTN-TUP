package biblio2;

import java.util.ArrayList;

public class Biblioteca {
    private ArrayList<Libro> libros;

    public Biblioteca(ArrayList<Libro> libros) {
        this.libros = libros;
    }

    public void prestarLibro(String titulo) throws LibroNoEncontradoException, NoCopiasException {
        for (Libro libro : libros) {
            // si el titulo del libro es igual al titulo que recibimos por parametro
            if (libro.getTitulo().equalsIgnoreCase(titulo)) {
                int copias = libro.getCopias();
                if (copias >= 1) {
                    libro.setCopias(copias - 1);
                    System.out.println("El libro " + titulo + " fue prestado con éxito");
                    return;
                } else {
                    // si se ejecuta el throw se corta la ejecución
                    throw new NoCopiasException("No hay más copias disponibles de ese libro");
                }
            }
        }
        // Si el codigo llega hasta acá significa que el libro no se encontró
        throw new LibroNoEncontradoException("El libro " + titulo + " no pudo ser encontrado");
    }

    public void devolverLibro(String titulo) throws LibroNoEncontradoException, NoCopiasException {
        for (Libro libro : libros) {
            // si el titulo del libro es igual al titulo que recibimos por parametro
            if (libro.getTitulo().equalsIgnoreCase(titulo)) {
                int copias = libro.getCopias();
                libro.setCopias(copias + 1);
                System.out.println("El libro " + titulo + " fue devuelto con éxito");
                return;
            }
        }
        // Si el codigo llega hasta acá significa que el libro no se encontró
        throw new LibroNoEncontradoException("El libro " + titulo + " no pudo ser encontrado");
    }

    public void mostrarInventario() {
        for (Libro libro : libros) {
            System.out.println(libro.getTitulo() + " - " + libro.getAutor() + " - " + "(copias disponibles: "
                    + libro.getCopias() + ")");
        }
    }

}
