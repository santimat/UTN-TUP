import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class GestorArchivos {
  private String rutaArchivo;

  public GestorArchivos(String rutaArchivo) {
    this.rutaArchivo = rutaArchivo;
    this.crearArchivoSiNoExiste();
  }

  private void crearArchivoSiNoExiste() {
    File archivo = new File(this.rutaArchivo);
    if (!archivo.exists()) {
      try (BufferedWriter fw = new BufferedWriter(new FileWriter(this.rutaArchivo, true))) {
        fw.write("nombre,apellido,fecha");
        fw.newLine();
        System.out.println("Archivo creado");
      } catch (IOException e) {
        System.out.println("Error al crear el archivo " + e.getMessage());
      }
    }
  }

  public List<Person> leerPersonas() {
    List<Person> personas = new ArrayList<>();
    try (BufferedReader fr = new BufferedReader(new FileReader(this.rutaArchivo))) {
      fr.readLine();

      String linea;
      while ((linea = fr.readLine()) != null) {
        String[] partes = linea.split(",");
        if (partes.length != 3) {
          System.out.println("Linea mal formateada");
          continue;
        }
        try {
          LocalDate fecha = LocalDate.parse(partes[2]);
          // nombre, apellido, fechaNac
          personas.add(new Person(partes[0], partes[1], fecha));
        } catch (Exception e) {
          System.out.println("Error con el formato: " + e.getMessage());
        }
      }
    } catch (IOException e) {
      System.out.println("Error al leer el archivo " + e.getMessage());
    }
    return personas;
  }

  public void agregarPersona(Person p) {
    try (BufferedWriter fw = new BufferedWriter(new FileWriter(this.rutaArchivo, true))) {
      fw.write(p.toStringCSV());
      fw.newLine();
    } catch (IOException e) {
      System.out.println("Error al escribr el archivo: " + e.getMessage());
    }
  }
}
