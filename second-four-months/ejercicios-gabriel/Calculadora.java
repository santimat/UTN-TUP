import java.util.ArrayList;
import java.util.List;
public class Calculadora {
 
    private Integer num1;
    private Integer num2;
    private String operacion;

    // Necesitamos List.of() para crear una lista a partir de los elementos que toma como argumento
    ArrayList<String> operacionesPermitidas = new ArrayList<>(List.of("+", "-", "*", "/"));

    public Calculadora(Integer num1, Integer num2, String operacion){
       setNums(num1, num2);
       setOperacion(operacion);
    }

    public void setNums(Integer num1, Integer num2){
        if (num1 == null || num2 == null) {
            throw new IllegalArgumentException("num1 y num2 no pueden estar vacíos");
        }
        this.num1 = num1;
        this.num2 = num2;
    }

    public void setOperacion(String operacion){

        if (operacion.isEmpty() || operacion == null) {
            throw new IllegalArgumentException("La operacion no puede estar vacía");
        }

        // .contains() nos permite 
        if (!operacionesPermitidas.contains(operacion)) {
            throw new IllegalArgumentException("Operacion no permitida");
        }

        this.operacion = operacion;
    }


    public double ejecutarOperacion(){
        switch (this.operacion) {
            case "+":
                return this.num1 + this.num2;
            case "-":
                return this.num1 - this.num2;
            case "*":
                    return this.num1 * this.num2;
            case "/":
                if(this.num2 == 0){
                    throw new ArithmeticException("No podés dividir por cero");
                }
                return this.num1 / this.num2;
            default:
                // Para evitar errores ya que el metodo necesito que se devuelva algo
                return 0;
        }
    }

}
