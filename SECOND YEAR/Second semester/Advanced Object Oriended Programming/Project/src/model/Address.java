package model;

import java.util.Scanner;

public class Address {
    private String city;
    private String county;
    private String street;
    private int streetNumber;

    private int address_id;

    //constructor


    public Address() {
    }

    public Address(String city, String county, String street, int streetNumber) {
        this.city = city;
        this.county = county;
        this.street = street;
        this.streetNumber = streetNumber;
    }


    //setters

    public String getCity() {
        return city;
    }

    public String getCounty() {
        return county;
    }

    public String getStreet() {
        return street;
    }

    public int getStreetNumber() {
        return streetNumber;
    }

    public int getAddress_id() {
        return address_id;
    }

//setters


    public void setAddress_id(int address_id) {
        this.address_id = address_id;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public void setCounty(String county) {
        this.county = county;
    }

    public void setStreet(String street) {
        this.street = street;
    }

    public void setStreetNumber(int streetNumber) {
        this.streetNumber = streetNumber;
    }

    //toString

    public void read(){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter city: ");
        String input = sc.nextLine();
        setCity(input);

        System.out.println("Enter county: ");
        input = sc.nextLine();
        setCounty(input);

        System.out.println("Enter street: ");
        input = sc.nextLine();
        setStreet(input);

        int input2;

        System.out.println("Enter street number: ");
        input2 = sc.nextInt();
        setStreetNumber(input2);

    }


    @Override
    public String toString() {
        return "Address{" +
                "city='" + city + '\'' +
                ", county='" + county + '\'' +
                ", street='" + street + '\'' +
                ", streetNumber=" + streetNumber +
                ", address_id=" + address_id +
                '}';
    }
}
