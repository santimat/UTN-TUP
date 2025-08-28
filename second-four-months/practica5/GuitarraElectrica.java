package practica5;

public class GuitarraElectrica extends InstrumentoCuerda implements Electrico,Afinable{

    private boolean encendida;
    private boolean afinada;
    public GuitarraElectrica(String nombre, String marca, double precio,int cantidadCuerdas){
        super(nombre, marca, precio, cantidadCuerdas);
        this.encendida = false;
        this.afinada = false;
    }

    @Override
    public void tocar(){
        // Ejecutamos el metodo heredado
        super.tocar();
    }

    @Override
    public void mostrarInfo() {
        super.mostrarInfo();
    }

    @Override
    public void encender() {
        this.encendida = true;        
    }

    @Override
    public void apagar() {
        this.encendida = false;        
    }

    @Override
    public boolean estaEncendido() {
        return this.encendida;
    }

    @Override
    public void afinar() {
        super.afinar();
        this.afinada = true;
    }

    @Override
    public void afinarAutomaticamente() {
        System.out.println("Afinando guitara....");
        // Hacer una pasa de 1000 milisegundos = 1 segundo
        try {
            Thread.sleep(1000);
        } catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println("Guitarra afinada");
        this.afinada = true;
    }
    @Override
    public boolean estaAfinado() {
        return this.afinada;
    }
}
