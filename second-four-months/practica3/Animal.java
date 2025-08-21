public class Animal {
    private String name;
    private int age;
    private String specie;

    public Animal(String name, int age, String specie){
        this.name = name;
        this.age = age;
        this.specie = specie;
    }

    public Animal(String name, String specie){
        // Hago uso del constructor de arriba
        this(name,0,specie);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        if (name.isEmpty() || name == null) {
            this.name = "a generic name";
            return;
        }
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        if (age < 0) {
            this.age = 0;
            return;
        }
        this.age = age;
    }

    public String getSpecie() {
        return specie;
    }

    public void setSpecie(String specie) {
        this.specie = specie;
    }

    public String emitSound(){
        return "generic sound";
    }
    // Sobreescribo toString() heredado del object
    @Override
    public String toString() {
        return "Animal{\nname: " +this.name+ ",\nage: "+ this.age+",\nspecie: " +this.specie+",\n}";
    }    
    
}
