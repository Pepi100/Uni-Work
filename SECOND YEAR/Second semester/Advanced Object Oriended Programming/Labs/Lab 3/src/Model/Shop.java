package Model;

import java.util.Arrays;

public class Shop {

    Produs produse[];

    public Shop() {
        produse = new Produs[0];
    }

    public Produs[] getProduse() {
        return produse;
    }

    public void setProduse(Produs[] produse) {
        this.produse = produse;
    }

    public void addProdus(Produs p){
        Produs arrNew[] = new Produs[produse.length + 1];
        int i;
        for( i =0; i< produse.length;i++){
            arrNew[i] = produse[i];
        }
        arrNew[i] = p;

        produse = arrNew;

    }

    public void afisare(){
        System.out.println(Arrays.toString(produse));
    }


}
