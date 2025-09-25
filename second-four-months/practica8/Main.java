import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.util.ArrayList;

public class Main {
  public static void main(String[] args) {
    String archivoEntrada = "./archives/lista_compras.txt";
    String archivoSalida = "./archives/resumen_compras.txt";

    ArrayList<String> productos = new ArrayList<>();

    // Leer productos
    try (BufferedReader reader = new BufferedReader(new FileReader(archivoEntrada))) {

      String linea;
      while ((linea = reader.readLine()) != null) {
        if (!linea.trim().isEmpty()) {
          productos.add(linea.trim());
        }
      }
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }

    // for (int i = 0; i < productos.size(); i++) {
    // System.out.println((i + 1) + ". " + productos.get(i));
    // }

    try (BufferedWriter writer = new BufferedWriter(new FileWriter(archivoSalida))) {
      writer.write("Resumen");
      writer.newLine();
      writer.write("Total de productos " + productos.size());
      writer.newLine();

      for (int i = 0; i < productos.size(); i++) {
        writer.write((i + 1) + ". " + productos.get(i));
        writer.newLine();
      }

      writer.write("Primer producto: " + productos.get(0));
      writer.newLine();
      writer.write("Ultimo productoo: " + productos.get(productos.size() - 1));
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }
  }
}