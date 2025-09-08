import java.util.ArrayList;
import java.util.List;
public class Main {

    public static void main(String[]args){

        // Ejercicio calculadora
        Calculadora calculator = new Calculadora(2, 4, "+");
        double res = calculator.ejecutarOperacion();
        System.out.println(res);

        // Ejercicio gestor de listas
        ArrayList<Integer> array = new ArrayList();
        ArrayList<Integer> elementos = new ArrayList(List.of("1", "2", "3", "4", "5"));

    }
}