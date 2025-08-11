package practica0;
import java.util.Scanner;
public class Finder {
    
    // Instatiates numbers array with a size of 6
    static int numbers[] = new int[6];

    public static int[] findNumber(int target){
        for(int i = 0; i < numbers.length; i++){
            if (numbers[i] == target) {
                int res[] = {numbers[i], i};
                return res;
            }
        }
        return new int[] {-1, -1}; // Si no lo encuentra
    }

    public static void fillArray(){
        Scanner scanner = new Scanner(System.in);
        for(int i = 0; i < 6; i++){
            System.out.println("Ingrese el numero #" + (i+1));
            numbers[i] = scanner.nextInt();
        }
        scanner.close();
    }
}
