package service;
import model.Manufacturer;
import model.product.*;
import model.user.*;

import java.lang.reflect.Array;
import java.sql.SQLOutput;
import java.util.ArrayList;
import java.util.Arrays;

import java.util.Scanner;

public class Service {

    private static ArrayList<User> users;
    private static ArrayList<Manufacturer> manufacturers;
    private static ArrayList<Product> products;

    private static Service instance;

    private Service() {
        manufacturers = new ArrayList<Manufacturer>();
        products = new ArrayList<Product>();
        users = new ArrayList<User>();

    }

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
                    printManufacturers();
                }
                case 4 -> {
                    addProduct();
                }
                case 5 -> {
                    addManufacturer();
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

        manufacturers.add(newMan);
    }

    private static void printManufacturers(){
            if(manufacturers.size() >0)
                System.out.println(manufacturers);
            else
                System.out.println("There are no manufacturers at the moment.");
    }

    private static void addProduct(){
        Scanner sc=new Scanner(System.in);
        Product newProd;

        System.out.println("What type of product would you like to add?");
        System.out.println("1 - Headphones");
        System.out.println("2 - Microphone");

        int type = sc.nextInt();

        if (type == 1){
            newProd = new Headphones();
        }else{
            newProd = new Microphone();
        }

        System.out.println("Enter a name for the product: ");
        newProd.setName(sc.nextLine());

        System.out.println("Enter a price for the product: ");
        newProd.setPrice(sc.nextFloat());


        System.out.println("Now you will need to select a manufacturer for the product: ");
        System.out.println("1 - Select from the current list.");
        System.out.println("2 - Add a new manufacturer.");

        int option = sc.nextInt();

        if(option == 1){
            printManufacturers();
            System.out.println("Select a number from the list above: ");
            int manufacturerNumber = sc.nextInt();
            newProd.setBrand(manufacturers.get(manufacturerNumber - 1));

        }else{


        }

        if (type == 1){
            //headphones
            System.out.println("Select the type of connectivity : ");
            System.out.println("1 - Wireless. ");
            System.out.println("2 - Wired. ");
            option= sc.nextInt();

            switch (option){
                case 1 -> {
                    ((Headphones) newProd).setConnectivity(ConnectivityType.Wireless);
                }
                default -> {
                    ((Headphones) newProd).setConnectivity(ConnectivityType.Wired);
                }
            }


            System.out.println("Select the type of fit : ");
            System.out.println("1 - On Ear. ");
            System.out.println("2 - Over Ear. ");
            System.out.println("3 - In Ear. ");
            option= sc.nextInt();

            switch (option){
                case 1 -> {
                    ((Headphones) newProd).setFit(FitType.On_Ear);
                }
                case 2 -> {
                    ((Headphones) newProd).setFit(FitType.Over_Ear);
                }
                default -> {
                    ((Headphones) newProd).setFit(FitType.In_Ear);
                }
            }

        }else{
            newProd = new Microphone();
        }


        products.add(newProd);
    }

}
