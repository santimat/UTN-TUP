package biblio2;

public class Libro {
    private String titulo;
    private String autor;
    private int copias;

    public Libro(String titulo, String autor, int copias) {
        this.titulo = titulo;
        this.autor = autor;
        this.copias = copias;
    }

    public String getTitulo() {
        return this.titulo;
    }

    public String getAutor() {
        return this.autor;
    }

    public int getCopias() {
        return this.copias;
    }

    public void setCopias(int copias) {
        this.copias = copias;
    }

    @Override
    public String toString() {
        return "Libro [titulo: " + this.titulo + ", autor: " + this.autor + ", copias: " + this.copias + "]";
    }
}
