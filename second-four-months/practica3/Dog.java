public class Dog extends Animal {

    private String breed;

    public Dog(String name, int age, String specie, String breed){
        super(name,age,specie);
        this.breed = breed;
    }

    public Dog(String name, int age){
        super(name,age, "Dog");
        this.breed = "Unknown";
    }

    public String emitSound(){
        return "Guau Guau";
    }

    public String play(){
        return "The dog " + this.getName() + " is playing";
    }
}