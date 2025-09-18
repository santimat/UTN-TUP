import java.util.ArrayList;

public class GestorLista{
    
    // Permite agregar elementos recibidos por un array
    public static void agregarElementos(ArrayList array,ArrayList elementos){
        for (int i = 0; i < elementos.size(); i++) {
            array.add(elementos.get(i));
        }
    }

    public static void eliminarElemento(ArrayList array,int indice){
        if(indice < 0 || indice >= array.size){
            throw new IndexOutOfBoundsException("Indice invalido");
        }else{
            array.remove(indice);
        }
    }
}