package model.product;

public abstract class Product {

    protected float price;
    protected Manufacturer brand;
    protected String name;




    // getters
    public float getPrice() {
        return price;
    }

    public Manufacturer getBrand() {
        return brand;
    }

    public String getName() {
        return name;
    }


    //setters
    public void setPrice(float price) {
        this.price = price;
    }

    public void setBrand(Manufacturer brand) {
        this.brand = brand;
    }

    public void setName(String name) {
        this.name = name;
    }






}
