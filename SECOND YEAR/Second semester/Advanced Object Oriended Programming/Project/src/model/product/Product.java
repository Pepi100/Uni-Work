package model.product;

public abstract class Product {

    protected float price;
    protected Manufacturer brand;
    protected String name;
    private int id;



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

    public int getId() {
        return id;
    }

    //setters


    public void setId(int id) {
        this.id = id;
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
