package model.product;

public abstract class Product {

    protected float price;
    protected Manufacturer brand;
    protected String name;
    protected int product_id;



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

    public int getProduct_id() {
        return product_id;
    }

//setters


    public void setProduct_id(int product_id) {
        this.product_id = product_id;
    }

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
