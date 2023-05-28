package model.product;

import java.util.Scanner;

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

    public void read(){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter a name for the manufacturer: ");
        String input = sc.nextLine();
        setName(input);

        System.out.println("Enter an email for the manufacturer: ");
        input = sc.nextLine();
        setEmail(input);
    }

    @Override
    public String toString() {
        return "Manufacturer " + manufacturer_id +
                "   " + name +
                "   " + email ;
    }
}
