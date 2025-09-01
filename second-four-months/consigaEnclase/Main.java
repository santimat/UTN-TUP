package consigaEnclase;
import java.util.ArrayList;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        // Instanciamos el scanner
        Scanner scanner = new Scanner(System.in);
        // Creamos el array list de tipo Videojuego
        ArrayList<Videojuego> videojuegos = new ArrayList<>();
        
        // Bucle hasta 4 para agregar 4 juegos
        for(int i = 0; i < 4; i++){
            // Instancia del videojuego para agregar al array
            Videojuego videojuego = new Videojuego(null, null);

            // Pedimos datos y los asignamos con los setters
            System.out.println("Ingrese el nombre del #" + (i + 1) + " videojuego");
            videojuego.setNombre(scanner.nextLine());
            System.out.println("Ingrese el genero del #" + (i + 1) + " videojuego");
            videojuego.setGenero(scanner.nextLine());

            videojuegos.add(videojuego);
        }                           

        // Mostramos videojuegos con for each
        // creamos variable temporal llamada videojuego e iteramos dentro del array videojuegos
        int i = 1; // indice
        for (Videojuego videojuego : videojuegos) {
            System.out.println("Juego nro: "+ i);
            System.out.println("Nombre: "+ videojuego.getNombre());
            System.out.println("Genero: "+ videojuego.getGenero());
            System.out.println();
            i++;
        }

        // Eliminar juegos de x genero
        // Al eliminar más de un videojuego es importante hacerlo con un bucle inverso, sino se rompen los indices
        // size - 1 porque .size() retorna el largo del array y los indices comienzan en 0
        for(i = videojuegos.size() - 1; i >= 0 ; i--){
            if (videojuegos.get(i).getGenero().equals("deporte")) {
                videojuegos.remove(i);
            }
        }

        for (int j = 0; j < videojuegos.size(); j++) {
            System.out.println("Juego nro: " + (j + 1));
            System.out.println("Nombre: " + videojuegos.get(j).getNombre());
            System.out.println("Genero: " + videojuegos.get(j).getGenero());
            System.out.println();
        }

        // boolean flag = false;
        // System.out.println("Ingrese el nombre del juego que desea buscar: ");
        // String nombreJuego = scanner.nextLine();
        // for (Videojuego videojuego : videojuegos) {
        //     // Obtenemos el nombre del videojuego y comparamos que si es igual al nombre del usuario ignorando mayusculas y minusculas
        //     if (videojuego.getNombre().equalsIgnoreCase(nombreJuego)) {
        //         System.out.println(videojuego);
        //         flag = true;
        //         break;
        //     }
        // }
        // if(!flag){
        //     System.out.println("Videojuego "+ nombreJuego +" no encontrado");
        // }

        // Juegos en total
        // System.out.println(videojuegos.size());

        // System.out.println("Ingrese el nombre del videojuego que desea eliminar");
        // nombreJuego = scanner.nextLine();
        // flag = false;
        // for(i = 0; i < videojuegos.size(); i++){
        //     // get(indice) es para obtener elemento del array
        //     if (videojuegos.get(i).getNombre().equalsIgnoreCase(nombreJuego)) {
        //         // .remove() retorna el elemento eliminado
        //         System.out.println("Video juego eliminado: " + videojuegos.remove(i).getNombre());
        //         flag = true;
                
        //     }
        // }
        // if(!flag){
        //     System.out.println("no se pudo eliminar el videojuego: " + nombreJuego);
        // }

        // System.out.println("Ingrese el genero a mostrar");
        // String genero = scanner.nextLine();
        // flag= false;
        // for (Videojuego videojuego : videojuegos) {
        //     if (videojuego.getGenero().equalsIgnoreCase(genero)) {
        //         System.out.println(videojuego);
        //         flag= true;
        //     }
        // }
        // if (!flag) {
        //     System.out.println("No hay ningun juego con ese genero");
        // }

        // Cerramos scanner
        scanner.close();
    }
}
