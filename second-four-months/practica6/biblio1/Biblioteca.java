package biblio1;

import java.util.ArrayList;

public class Biblioteca {
    private ArrayList<Libro> libros;

    public Biblioteca(ArrayList<Libro> libros) {
        this.libros = libros;
    }

    public void prestarLibro(String titulo) throws LibroNoEncontradoException {
        for (Libro libro : this.libros) {
            if (libro.getTitulo().equalsIgnoreCase(titulo)) {
                if (libro.getDisponible()) {
                    libro.setDisponible(false);
                    System.out.println("Libro " + titulo + " prestado con exito");
                    return;
                } else {
                    throw new LibroYaPrestadoException("El libro ya está prestado");
                }
            }
        }
        throw new LibroNoEncontradoException("El libro no fue encontrado");
    }

    public void devolverLibro(String titulo) throws LibroNoEncontradoException {
        for (Libro libro : this.libros) {
            if (libro.getTitulo().equalsIgnoreCase(titulo)) {
                if (!libro.getDisponible()) {
                    libro.setDisponible(true);
                    System.out.println("Libro " + titulo + " devuelto con exito");
                    return;
                } else {
                    throw new LibroYaPrestadoException("El libro ya fue devuelto");
                }
            }
        }
        throw new LibroNoEncontradoException("El libro no fue encontrado");
    }
}
