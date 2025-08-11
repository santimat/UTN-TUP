package practica0;
import java.util.ArrayList;
import java.util.Scanner;

public class Calculator {
    static ArrayList<Integer> numbers = new ArrayList<>();

    public static ArrayList<Integer> getNumbers(){
        Scanner scanner = new Scanner(System.in);

        System.out.print("Ingrese el primer numero: ");
        numbers.add(scanner.nextInt());
        System.out.print("Ingrese el segundo numero: ");
        numbers.add(scanner.nextInt());
        
        scanner.close();

        return numbers;
    }

    static int sum(int n1, int n2){
        return n1 + n2;
    }

    static int subtract(int n1, int n2){
        return n1 - n2;
    }

    static int multiply(int n1, int n2){
        return n1 * n2;
    }

    static double divide(int n1, int n2){
        return n1 / n2;
    }

    public static void showResults(){
        int n1 = numbers.get(0);
        int n2 = numbers.get(1);

        System.out.println("Resultado de la suma de " + n1 + " + " + n2);
        System.out.println(sum(n1,n2));
        System.out.println("Resultado de la resta de " + n1 + " - " + n2);
        System.out.println(subtract(n1,n2));
        System.out.println("Resultado de la multiplicacion de " + n1 + " x " + n2);
        System.out.println(multiply(n1,n2));
        System.out.println("Resultado de la división de " + n1 + " / " + n2);
        System.out.println(divide(n1,n2));
    }
}