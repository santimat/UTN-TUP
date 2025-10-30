import java.time.LocalDate;
import java.util.List;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    GestorArchivos ga = new GestorArchivos("./archivos/lista_personas.csv");
    Scanner scanner = new Scanner(System.in);
    int opcion = 0;
    String[] meses = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre",
        "Octubre",
        "Noviembre", "Diciembre" };
    do {
      System.out.println("====== SISTEMA CUMPLES ======");
      System.out.println("1. Agregar nueva persona");
      System.out.println("2. Ver todas las personas");
      System.out.println("3. Ver cumples por mes");
      System.out.println("4. para salir");
      System.out.print("OPCION: ");

      opcion = scanner.nextInt();
      scanner.nextLine();
      switch (opcion) {
        case 1:
          System.out.print("Ingrese nombre: ");
          String nombre = scanner.nextLine();
          System.out.print("Ingrese apellido: ");
          String apellido = scanner.nextLine();
          System.out.print("Ingrese fecha de nacimiento formato YYYY-MM-DD");
          try {
            LocalDate fecha = LocalDate.parse(scanner.nextLine());
            ga.agregarPersona(new Person(nombre, apellido, fecha));
          } catch (Exception e) {
            System.out.println("Error con el formato de la fecha");
          }
          break;
        case 2:
          List<Person> personas = ga.leerPersonas();
          if (personas.isEmpty()) {
            System.out.println("Aun no hay personas registradas");
            break;
          }
          System.out.println("Personas en CSV");
          for (Person person : personas) {
            System.out.println(person.retornarPersonaConEdad());
          }
          break;
        case 3:
          System.out.print("Ingrese un mes del 1-12: ");
          int mes = scanner.nextInt();
          scanner.nextLine();
          List<Person> personasPorMes = ga.leerPersonas();
          if (personasPorMes.isEmpty()) {
            System.out.println("Aun no hay personas registradas");
            return;
          }

          boolean hayCumples = false;

          System.out.println("CUMPLEAÑOS DEL MES " + mes);
          for (Person person : personasPorMes) {
            if (person.getBornDate().getMonthValue() == mes) {
              System.out.println(person.retornarPersonaConEdad());
              hayCumples = true;
            }
            if (person.getBornDate().equals(LocalDate.now())) {
              System.out.println("FELIZ CUMPLE!!! " + person.getName());
            }
          }

          if (!hayCumples) {
            System.out.println("Nadie cumple añitos en " + meses[mes - 1]);
          }
          break;
        default:
          break;
      }
    } while (opcion != 4);

    scanner.close();
  }
}