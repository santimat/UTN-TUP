// Como importar paquetes locales
// package university.model; archivo en ruta "university/model"

// Import es para importar clases
import java.util.Scanner;
// import java.util.*; <- importamos todas las clases del package
public class Main{
    public static void main(String[] args) {
        // Creamos un scanner para leer datos de la consola
        // System.in es de inputStream
        Scanner scanner = new Scanner(System.in);

        System.out.println("Ingrese un texto");
        // next.Line(), es para leer una linea completa
        String text = scanner.nextLine();
        System.out.println(text);

        // next.Int(), es para leer un int
        int age = scanner.nextInt();
        System.out.println(age);

        // next.double(), leer un numero decimal
        double measure = scanner.nextDouble();
        System.out.println(measure);

        // Cerrar scanner
        scanner.close();

        // final, es para crear constantes
        final int MAX_ALUMNOS = 30; // No se puede reescribir
    }
}