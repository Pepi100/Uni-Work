package service;
import model.Manufacturer;
import model.product.*;
import model.user.*;
import java.util.ArrayList;
import java.util.Arrays;

import java.util.Scanner;

public class Service {

    private User[] users;
    private Manufacturer[] manufacturers;
    private Product[] products;

    private static Service instance;

    private Service() {}



    public static Service getInstance() {
        if (instance == null) {
            instance = new Service();
        }
        return instance;
    }


    public static void run(){
        int input = -1;
        do{
            System.out.println("Choose an option from the following:");
            System.out.println("1 - Print products.");
            System.out.println("2 - Print users.");
            System.out.println("3 - Print all manufacturers.");
            System.out.println("4 - Add a new product.");
            System.out.println("5 - Add a new manufacturer.");
            System.out.println("7 - Add a new user.");
            System.out.println("0 - Exit the program.");


            Scanner reader = new Scanner(System.in);
            input = reader.nextInt();

            switch (input){
                case 1 -> {

                }
                case 2 -> {

                }
                case 3 -> {

                }
                case 4 -> {

                }
                case 5 -> {

                }
                case 6 -> {

                }
                case 7 -> {

                }
                case 0 -> {

                }
                default -> {
                    System.out.println("!!ALERT!! The number you entered is not available, please try again.");
                }

            }

        }while(input != 0);

        System.out.println("\n\nThank you for choosing our products!");


    }

    private static void addManufacturer(){
        Scanner sc=new Scanner(System.in);
        Manufacturer newMan = new Manufacturer();

        System.out.println("Enter a name for the manufacturer: ");
        String input = sc.nextLine();
        newMan.setName(input);

        System.out.println("Enter an email for the manufacturer: ");
        input = sc.nextLine();
        newMan.setEmail(input);

        System.out.println("Enter a description for the manufacturer: ");
        input = sc.nextLine();
        newMan.setDescription(input);



    }

}
