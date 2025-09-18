import java.util.ArrayList;
import java.util.List;

public class Main {
  public static void main(String[] args) {
    ArrayList<String> nombres = new ArrayList<>(List.of("Santino", "Pepe", "Juan"));

    int id = nombres.indexOf("Santino");
    nombres.remove(id);

    for (String nombre : nombres) {
      System.out.println(nombre);
    }
  }
}
