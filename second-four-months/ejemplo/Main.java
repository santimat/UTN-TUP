// Importamos todas las clases de la carpeta ejemplo
package ejemplo;

// Import al scanner
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Nueva instancia de alumno
        Alumno alumno1 = new Alumno();   

        // Instanciar scanner
        Scanner scanner = new Scanner(System.in);
        
        // Pedimos los datos y llenamos la instancia de Alumno
        System.out.println("Ingrese su legajo");
        alumno1.legajo = scanner.nextInt();

        System.out.println("Ingrese su nombre");
        alumno1.nombre = scanner.nextLine();

        System.out.println("Ingrese su apellido");
        alumno1.apellido = scanner.nextLine();

        // Cerrar el scanner
        scanner.close();

        // Funcion para mostrar la informacion del alumno
        alumno1.showData();
    }
}
