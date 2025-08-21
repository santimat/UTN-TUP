package ej1;
public class Book extends Publication {

    private String author;
    private int pages;

    public Book(String title, int year, String author, int pages){
        super(title, year);
        this.author = author;
        this.pages = pages;
    }

    public void showInfo(){
        super.showInfo();
        System.out.println("\nAuthor: " + this.author + "\nPages: " + this.pages);
    }

    public String getAuthor(){
        return this.author;
    }
}
