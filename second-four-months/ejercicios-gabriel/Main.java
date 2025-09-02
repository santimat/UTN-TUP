public class Main {

    public static void main(String[]args){

        Calculadora calculator = new Calculadora(2, 4, "+");
        double res = calculator.ejecutarOperacion();
        System.out.println(res);
    }
}