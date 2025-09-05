package practica5;
import java.util.ArrayList;

public class Main{
    public static void main(String[] args) {
        ArrayList<Instrumento> orquesta = new ArrayList<>();

        InstrumentoCuerda guitarraAcustica = new InstrumentoCuerda("Guitarra acustica", "Yamaha", 300, 6);
        InstrumentoViento violin = new InstrumentoViento("Violin", "Corina", 400, "Metal");
        GuitarraElectrica guitarraElectrica = new GuitarraElectrica("Guitarra electrica", "Gibson", 600, 5);
        InstrumentoViento flauta = new InstrumentoViento("Flauta", "Yamaha", 300, "Plastico");
        
    }
}