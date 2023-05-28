package model.user;
import model.Address;
import service.DatabaseConnection;

import java.util.Scanner;

public class Customer extends User{

    private Address address;
    private int customer_id;

    //getters
    public Address getAddress() {
        return address;
    }

    public int getCustomer_id() {
        return customer_id;
    }

    //setters
    public void setAddress(Address address) {
        this.address = address;
    }

    public void setCustomer_id(int customer_id) {
        this.customer_id = customer_id;
    }
//toString
    public void read(){
        Scanner sc=new Scanner(System.in);

        System.out.println("Enter a name: ");
        String name = sc.nextLine();

        System.out.println("Enter an email address: ");
        String email = sc.nextLine();

        setName(name);
        setEmail(email);

        Address a = new Address();
        a.read();
        setAddress(a);


    }

    @Override
    public String toString() {
        return "Customer " + user_id +
                "   " + name +
                "   " + email;
    }
}
