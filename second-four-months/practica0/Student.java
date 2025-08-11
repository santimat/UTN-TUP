package practica0;
import java.util.Scanner;

public class Student{
    int file;
    String name;
    String lastname;

    public void showInfo(){
        System.out.println("=========== Student Information ===========");
        System.out.println("File: " + this.file);
        System.out.println("Name: " + this.name);
        System.out.println("Lastname: " + this.lastname);
        System.out.println("Fullname: " + this.name + " " + this.lastname);
    }

    public void getInfo(){
        System.out.println("=========== Student Information ===========");
        Scanner scanner = new Scanner(System.in);

        System.out.print("File: ");
        this.file = scanner.nextInt();

        // Clears buffer
        scanner.nextLine();

        System.out.print("Name: ");
        this.name = scanner.nextLine();

        System.out.print("Lastname: ");
        this.lastname = scanner.nextLine();

        scanner.close();
    }
}
