import java.util.Arrays;
import Model.*;
import Service.*;

public class Main {
    public static void main(String[] args) {
        int [] vector = {1,3,2, 3,4};
        int vector2[] = {1,2,34};

        int vector3[] = new int[4];

//        System.out.println(Arrays.toString(vector2));
        Arrays.sort(vector);
        System.out.println(Arrays.toString(vector));

        //binary search
        //merge doar pe vectori sortati anterior
//        System.out.println( Arrays.binarySearch(vector, 3) );


        //final acces modifier

        Produs p = new Produs("Nume", 22);

        //System.out.println(p);


        ShopService s = new ShopService();
        Shop sh = new Shop();
        sh.addProdus(p);
        s.setShop(sh);
        s.addProdus(p);

        s.afisare();

        s.addProdus(p);
        System.out.println("Afisare 2\n\n\n");
        s.afisare();

    }
}
