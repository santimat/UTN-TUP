package ej1;
public class Publication {
    private String title;
    private int year;
    private Boolean available;

    public Publication(String title, int year){
        this.title = title;
        this.year = year;
        this.available = true;
    }

    public Boolean lend(){
        if (this.available) {
            this.available = false;
            return true;
        }
        return false;
    }

    public void returnn(){
        this.available = true;
    }

    public void showInfo(){
        System.out.println("title: " + this.title + "\nyear: " + this.year + "\n status: " + this.available);
    }

    public String getTitle(){
        return this.title;
    }

    public int getYear(){
        return this.year;
    }

    public Boolean getAvailable(){
        return this.available;
    }
}
