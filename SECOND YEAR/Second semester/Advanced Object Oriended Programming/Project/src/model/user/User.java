package model.user;
import model.Address;

public abstract class User {
    protected String name;
    protected String email;

    //setters

    public void setName(String name) {
        this.name = name;
    }

    public void setEmail(String email) {
        this.email = email;
    }


    //getters

    public String getName() {
        return name;
    }

    public String getEmail() {
        return email;
    }
}
