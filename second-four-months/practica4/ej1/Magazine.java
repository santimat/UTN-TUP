package ej1;
public class Magazine extends Publication {

    private int number;
    private String month;

    public Magazine(String title, int year, int number, String month){
        super(title, year);
        this.number = number;                
        this.month = month;                
    }

    public void showInfo(){
        super.showInfo();
        System.out.println("\nNumber: " + this.number + "\nMonth: " + this.month);
    }

    public int getNumber(){
        return this.number;
    }
}
