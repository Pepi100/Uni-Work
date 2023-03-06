package Service;
import Model.*;

public class ShopService {
    Shop shop;


    public Shop getShop() {
        return shop;
    }

    public void setShop(Shop shop) {
        this.shop = shop;
    }

    public void addProdus(Produs p){
        shop.addProdus(p);
    }

    public void afisare(){
        shop.afisare();
    }
}
