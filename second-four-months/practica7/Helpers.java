
public class Helpers {
  public static String capitalize(String name) {
    String[] nombreSpliteado = name.split(" ");

    StringBuilder sb = new StringBuilder("");
    for (int i = 0; i < nombreSpliteado.length; i++) {
      if (!nombreSpliteado[i].trim().isEmpty()) {
        // tomo la primer letra y la paso a mayuscula
        sb.append(nombreSpliteado[i].substring(0, 1).toUpperCase());
        // agrego el resto del texto
        sb.append(nombreSpliteado[i].substring(1));
        // si tengo más de una palabra agrego espacio
        if (nombreSpliteado.length > 1) {
          sb.append(" ");
        }
      }
    }

    // convierto el StringBuilder a string y lo retorno
    return sb.toString().trim();
  }
}
