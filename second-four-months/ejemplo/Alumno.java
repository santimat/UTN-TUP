package ejemplo;

public class Alumno{
    public int legajo;
    public String nombre;
    public String apellido;

    // public Alumno(int legajo, String nombre, String apellido){
    //     this.legajo = legajo;
    //     this.nombre = nombre;
    //     this.apellido = apellido;
    // }
    
    public void showData(){
        System.out.println("Datos del alumno");
        System.out.println("Legajo: " + this.legajo);
        System.out.println("Nombre: " + this.nombre);
        System.out.println("Apellido: " + this.apellido);
    }
}