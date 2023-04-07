package model;

public class Manufacturer {

    private String name;
    private String email;
    private String description;

    //getters
    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }

    public String getDescription() {
        return description;
    }

    //setters
    public void setName(String name) {
        this.name = name;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    //constructor


    public Manufacturer() {

        this.name = "";
        this.email = "";
        this.description = "";
    }

    public Manufacturer(String name, String email, String description) {
        this.name = name;
        this.email = email;
        this.description = description;
    }
}
