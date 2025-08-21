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
        String text = "Title: " + this.getTitle() + "\nYear: " + this.getYear() + "\nAuthor: " + this.author + "\nPages: " +this.pages + "\nStatus: ";
        if (this.getAvailable()) {
            text += "Available";
        }else{
            text += "Lended";
        }
        System.out.println(text);
    }

    public String getAuthor(){
        return this.author;
    }
}
