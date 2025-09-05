package practica5;

public class InstrumentoViento extends Instrumento{
    private String material;

    public InstrumentoViento(String nombre, String marca, double precio, String material){
        super(nombre,marca,precio);
        this.material = material;
    }

    public void tocar(){
        super.tocar();
    }

    public void mostrarInfo(){
        super.mostrarInfo();
        System.out.println("\nMaterial: " + this.material);
    }

    public String getMaterial(){
        return this.material;
    }
}
    
