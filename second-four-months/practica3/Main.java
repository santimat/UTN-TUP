public class Main{
    public static void main(String[] args){

        Dog fullDog = new Dog("talo", 5, "Dog",  "German shepherd");
        Dog basicDog = new Dog("toto", 3);

        Cat fullCat = new Cat("bigotes", 2, "Cat", "black");
        Cat basicCat = new Cat("chisito");

        System.out.println(fullDog);
        System.out.println(fullCat);
        System.out.println(basicDog);
        System.out.println(basicCat);

        System.out.println(fullDog.emitSound());
        System.out.println(fullDog.play());

        System.out.println(fullCat.emitSound());
        System.out.println(fullCat.purr());
    }
}