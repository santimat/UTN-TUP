package practica1;
public class Main {
    public static void main(String[] args) {
        // Movie fullMovie = new Movie("The matrix", "Lana Wachoski", 136, false);
        // Movie noStageMovie = new Movie("Avengers", "Joss Whedon", 143);
        // Movie basicMovie = new Movie("Titanes del pacifico","Guillermo del toro");

        // System.out.println(fullMovie);
        // System.out.println(noStageMovie);
        // System.out.println(basicMovie);

        // basicMovie.markAsWatched();
        // System.out.println(basicMovie);

        BankAccount acc1 = new BankAccount("santino", "23124", 100000, true);
        BankAccount acc2 = new BankAccount("juan", "231122");
        BankAccount acc3 = new BankAccount("gustavo");

        acc1.deposit(3000);
        acc2.withdraw(100);
        acc3.setActive(true);
        acc1.setActive(false);
        System.out.println(acc1);
        System.out.println(acc2);
        System.out.println(acc3);
        System.out.println(acc1.isVipAcc());
    }    
}
