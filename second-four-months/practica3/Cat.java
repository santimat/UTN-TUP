public class Cat extends Animal {

    private String color;

    public Cat(String name, int age, String specie, String color){
        super(name,age,specie);
        this.color = color;
    }
    public Cat(String name){
        super(name,0,"Cat");
        this.color = "Unknown";
    }

    public String emitSound(){
        return "Miau Miau";
    }

    public String purr(){
        return "The cat " +this.getName() + " is purring";
    }
}