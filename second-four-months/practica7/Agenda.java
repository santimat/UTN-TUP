import java.util.HashMap;

public class Agenda {
  private static HashMap<String, String> agenda = new HashMap<>();

  public static void agregarContacto(String nombre, String telefono) throws AgendaException {
    if (agenda.containsKey(nombre.toLowerCase().trim())) {
      throw new AgendaException("El contacto ya existe.");
    }
    if (nombre.isEmpty()) {
      throw new AgendaException("El nombre no puede estar vacío.");
    }
    if (telefono.length() >= 7) {
      throw new AgendaException("El numero de telefono debe contener al menos 7 caracteres.");
    }
    agenda.put(nombre.toLowerCase().trim(), telefono.toLowerCase());
  }

  public static String buscarTelefono(String nombre) throws AgendaException {
    if (!agenda.containsKey(nombre.toLowerCase().trim())) {
      throw new AgendaException("El contacto no existe en la agenda.");
    }
    return agenda.get(nombre.toLowerCase().trim());
  }

  public static void eliminarContacto(String nombre) throws AgendaException {
    if (agenda.remove(nombre.toLowerCase().trim()) == null) {
      throw new AgendaException("El contacto que desea eliminar no existe.");
    }
    System.out.println("Contacto: " + nombre + " eliminado correctamente.");
  }

  public static void mostrarContactos() throws AgendaException {
    if (agenda.size() == 0) {
      throw new AgendaException("La agenda está vacía");
    }
    for (String key : agenda.keySet()) {
      System.out.println(key + ": " + agenda.get(key));
    }
  }

}
