package model.product;

public class Manufacturer {

    private String name;
    private String email;

    private int manufacturer_id;


    //getters
    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }

    public int getManufacturer_id() {
        return manufacturer_id;
    }

    //setters


    public void setManufacturer_id(int manufacturer_id) {
        this.manufacturer_id = manufacturer_id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setEmail(String email) {
        this.email = email;
    }


    //constructor


    public Manufacturer() {

        this.name = "";
        this.email = "";
    }

    public Manufacturer(String name, String email) {
        this.name = name;
        this.email = email;

    }

    @Override
    public String toString() {
        return "Manufacturer{" +
                "name='" + name + '\'' +
                ", email='" + email + '\'' +
                ", manufacturer_id=" + manufacturer_id +
                '}';
    }
}
