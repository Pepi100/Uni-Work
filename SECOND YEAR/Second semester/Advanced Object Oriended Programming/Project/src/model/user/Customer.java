package model.user;
import model.Address;

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


    @Override
    public String toString() {
        return "Customer{" +
                "address=" + address +
                ", customer_id=" + customer_id +
                ", name='" + name + '\'' +
                ", email='" + email + '\'' +
                ", user_id=" + user_id +
                '}';
    }
}
