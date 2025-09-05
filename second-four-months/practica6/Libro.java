public class Libro {
    private String titulo;
    private String autor;
    private boolean disponible;

    public Libro(String titulo, String autor, boolean disponible){
        this.titulo = titulo;
        this.autor = autor;
        this.disponible = disponible;
    }
    public String getTitulo(){
        return this.titulo;
    }
    public String getAutor(){
        return this.autor;
    }
    public boolean getDisponible(){
        return this.disponible;
    }
    public void setDisponible(boolean disponible){
        this.disponible = disponible;
    }

    @Override
    public String toString() {
        return "Libro [titulo: " + this.titulo + ", autor: " + this.autor + ", disponible: " + this.disponible +"]";
    }
}    
