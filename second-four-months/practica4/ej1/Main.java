package ej1;
public class Main{
    public static void main(String[] args) {
        Book book1 = new Book("Deja de ser tu", 2012, "Joe Dispenza", 352);
        
        Book book2 = new Book("El mundo de sofia", 1991, "Josteein Gaarder", 518);

        Magazine magazine = new Magazine("National Geographic", 2024, 2, "September");

        book1.showInfo();
        System.out.println("\n");
        book2.showInfo();
        System.out.println("\n");
        magazine.showInfo();
        System.out.println("\n");


        book2.lend();

        if(!book2.lend()){
            System.out.println("Book lended");
        }
        book2.showInfo();

        book2.returnn();
    }
}