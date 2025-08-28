package practica5;

public class Instrumento {
    private String nombre;
    private String marca;
    private double precio;

    public Instrumento(String nombre, String marca, double precio){
        this.nombre = nombre;
        this.marca = marca;
        this.precio = precio;
    }

    public void tocar(){
        System.out.println("Tocando " + this.nombre + " de la marca " + this.marca);
    }

    public void afinar(){
        System.out.println("Afinando " + this.nombre);
    }

    public void mostrarInfo(){
        System.out.println("Nombre: " + this.nombre + "\nMarca: " + this.marca + "\nPrecio: " + this.precio);
    }

    public String getNombre() {
        return this.nombre;
    }

    public String getMarca() {
        return this.marca;
    }

    public double getPrecio() {
        return this.precio;
    }
}
