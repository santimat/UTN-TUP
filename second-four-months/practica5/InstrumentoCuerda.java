package practica5;

public class InstrumentoCuerda extends Instrumento {
    private int cantidadCuerdas;
    
    public InstrumentoCuerda(String nombre, String marca, double precio, int cantidadCuerdas){
        super(nombre, marca, precio);
        this.cantidadCuerdas = cantidadCuerdas;
    }

    @Override
    public void tocar(){
        System.out.println("Tocando las " + this.cantidadCuerdas + " cuerdas de " + this.getNombre());
    }

    @Override
    public void mostrarInfo(){
        super.mostrarInfo();
        System.out.println("\nCuerdas: " + this.cantidadCuerdas);
    }

    public int getCantidadCuerdas(){
        return this.cantidadCuerdas;
    }
}