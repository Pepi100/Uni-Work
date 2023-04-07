package model.user;
import model.Address;

public class Customer extends User{

  private Address address;

    //getters
    public Address getAddress() {
        return address;
    }



    //setters
    public void setAddress(Address address) {
        this.address = address;
    }


    //toString


    @Override
    public String toString() {
        return "Customer{" +
                ", name='" + name + '\'' +
                ", email='" + email + '\'' +
                "address=" + address +
                '}';
    }
}
