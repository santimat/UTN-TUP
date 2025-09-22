import java.util.Scanner;

public class Main {
  public static void main(String[] arg) {
    Scanner scanner = new Scanner(System.in);

    boolean exit = true;
    do {
      System.out.println("1: Agregar un contacto");
      System.out.println("2: Buscar telefono por nombre");
      System.out.println("3: Eliminar contacto por nombre");
      System.out.println("4: Mostrar todos los contactos");
      System.out.println("Cualquier otra tecla para salir");
      String nombre;
      switch (scanner.nextLine()) {
        case "1":
          System.out.println("Ingrese nombre:");
          nombre = scanner.nextLine();
          System.out.println("Ingrese numero de telefono:");
          String telefono = scanner.nextLine();
          try {
            Agenda.agregarContacto(nombre, telefono);
          } catch (Exception e) {
            System.out.println(e.getMessage());
          }
          break;
        case "2":
          System.out.println("Ingrese el nombre del contacto que desea buscar: ");
          nombre = scanner.nextLine();
          try {
            System.out.println(Agenda.buscarTelefono(nombre));
          } catch (Exception e) {
            System.out.println(e.getMessage());
          }
          break;
        case "3":
          System.out.println("Ingrese el nombre del contacto que desea eliminar");
          nombre = scanner.nextLine();
          try {
            Agenda.eliminarContacto(nombre);
          } catch (Exception e) {
            System.out.println(e.getMessage());
          }
          break;
        case "4":
          try {
            Agenda.mostrarContactos();
          } catch (Exception e) {
            System.out.println(e.getMessage());
          }
          break;
        default:
          exit = false;
          break;
      }
    } while (exit);

    scanner.close();
  }
}