import java.util.regex.Matcher;
import java.util.regex.Pattern;

interface Animal{
    void addOne();
    int getTotal();
}

class Dog implements Animal{

    static int count = 0;

    @Override
    public void addOne() {
        count++;
    }

    @Override
    public int getTotal() {
        return count;
    }
}
class Cat implements Animal{

    static int count = 0;

    @Override
    public void addOne() {
        count++;
    }

    @Override
    public int getTotal() {
        return count;
    }
}

class Zebra implements Animal{

    static int count = 0;

    @Override
    public void addOne() {
        count++;
    }

    @Override
    public int getTotal() {
        return count;
    }
}
public class TestPointer {


    public static void main(String[] args) {
        Animal[] myAnimals = new Animal[]{new Dog(),new Cat(),new Zebra()};
        doIt(myAnimals);
        doIt(myAnimals);

    }

    private static void doIt(Animal[] myAnimals) {
        long start = System.currentTimeMillis();
        for (int i = 0; i < 10_000_000 ; i++) {
            for (Animal myAnimal : myAnimals) {
                myAnimal.addOne();
            }
        }
        long end = System.currentTimeMillis();
        System.out.println("time = " + (end-start));
    }
}

