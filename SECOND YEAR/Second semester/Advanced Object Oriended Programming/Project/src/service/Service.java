package service;
import model.Address;
import model.product.Manufacturer;
import model.product.*;
import model.user.*;


import java.util.ArrayList;

import java.util.Scanner;

public class Service {

//    private static ArrayList<User> users;
    private static ArrayList<Manufacturer> manufacturers;
    private static ArrayList<Product> products;
    private static Service instance;
    private static DatabaseConnection DBinstance;

    private Service() {
        manufacturers = new ArrayList<Manufacturer>();
        products = new ArrayList<Product>();
//        users = new ArrayList<User>();
        try {
            DBinstance = DatabaseConnection.getInstance();
        }catch (Exception e){

        }

    }

    public static Service getInstance() {
        if (instance == null) {
            instance = new Service();
        }
        return instance;
    }


    public static void run()  {
        int input = -1;
        do{
            System.out.println("Choose an option from the following:");
            System.out.println("1 - Print products.");
            System.out.println("2 - Print users.");
            System.out.println("3 - Print all manufacturers.");
            System.out.println("4 - Add a new product.");
            System.out.println("5 - Add a new manufacturer.");
            System.out.println("6 - Add a new user.");
            System.out.println("0 - Exit the program.");


            Scanner reader = new Scanner(System.in);
            input = reader.nextInt();

            switch (input){
                case 1 -> {
                    printProducts();
                }
                case 2 -> {
                    printUsers();
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
                    addUser();
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

    //adding
    private static int addManufacturer(){
        Scanner sc=new Scanner(System.in);
        Manufacturer newMan = new Manufacturer();

        int manufacturer_id = -1;

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

        return manufacturer_id;
    }

    private static void addProduct(){
        Scanner sc=new Scanner(System.in);
        Product newProd;

        System.out.println("Enter a name for the product: ");
        String name = sc.nextLine();

        System.out.println("Enter a price for the product: ");
        float price = sc.nextFloat();




        System.out.println("What type of product would you like to add?");
        System.out.println("1 - Headphones");
        System.out.println("2 - Microphone");

        int type = sc.nextInt();

        if (type == 1){
            newProd = new Headphones();
        }else{
            newProd = new Microphone();
        }


        newProd.setName(name);
        newProd.setPrice(price);


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
            //adding a new manufacturer

            addManufacturer();

            newProd.setBrand(manufacturers.get(manufacturers.size() - 1));

        }

        if (type == 1){
            //headphones
            System.out.println("Select the type of connectivity : ");
            System.out.println("1 - Wireless.");
            System.out.println("2 - Wired.");
            option= sc.nextInt();

            switch (option){
                case 1 -> {
                    ((Headphones) newProd).setConnectivity(ConnectivityType.WIRELESS);
                }
                default -> {
                    ((Headphones) newProd).setConnectivity(ConnectivityType.WIRED);
                }
            }


            System.out.println("Select the type of fit : ");
            System.out.println("1 - On Ear. ");
            System.out.println("2 - Over Ear. ");
            System.out.println("3 - In Ear. ");
            option= sc.nextInt();

            switch (option){
                case 1 -> {
                    ((Headphones) newProd).setFit(FitType.ON_EAR);
                }
                case 2 -> {
                    ((Headphones) newProd).setFit(FitType.OVER_EAR);
                }
                default -> {
                    ((Headphones) newProd).setFit(FitType.IN_EAR);
                }
            }

        }else{
            newProd = new Microphone();

            // TODO
        }


        products.add(newProd);
    }

    private static void addUser()  {
        Scanner sc=new Scanner(System.in);
        User newUser;

        System.out.println("Enter a name: ");
        String name = sc.nextLine();

        System.out.println("Enter an email address: ");
        String email = sc.nextLine();


        System.out.println("What type of user would you like to add?");
        System.out.println("1 - Customer");
        System.out.println("2 - Employee");


        int type = sc.nextInt();

        if (type == 1){
            newUser = new Customer();
        }else{
            newUser = new Employee();
        }


        newUser.setName(name);
        newUser.setEmail(email);


        if (type == 1){
            Address a = readAddress();
            ((Customer) newUser).setAddress(a);
            //ADD Customer to db
            DatabaseConnection.add(((Customer) newUser));

        }else{

            String dep = sc.nextLine();
            ((Employee) newUser).setDepartment(dep);
            DatabaseConnection.add(((Employee) newUser));

        }

//        users.add(newUser);


    }

    //deleting
        //TODO



    //printing
    private static void printManufacturers(){
            if(manufacturers.size() >0)
                System.out.println(manufacturers);
            else
                System.out.println("There are no manufacturers at the moment.");
    }

    private static void printProducts(){
        if(products.size() >0){

            System.out.printf("How would you like the products to be ordered?");
            System.out.println("1 - Price.");
            System.out.println("2 - Price, descending.");
            System.out.println("3 - Name.");
            System.out.println("4 - Name, descending.");
            System.out.println("5 - Manufacturer.");

            Scanner sc = new Scanner(System.in);
            int input = sc.nextInt();




            //TODO

            switch (input){
                case 1 ->{

                }
                case 2 ->{

                }
                case 3 ->{

                }
                case 4 ->{

                }
                case 5 ->{

                }
                default -> {

                }

            }





        }

        else
            System.out.println("There are no products at the moment.");
    }

    private static void printUsers(){
//TODO
    }


    //extra
    private static Address readAddress(){
        Scanner sc=new Scanner(System.in);
        Address newAdd = new Address();

        System.out.println("Enter city: ");
        String input = sc.nextLine();
        newAdd.setCity(input);

        System.out.println("Enter county: ");
        input = sc.nextLine();
        newAdd.setCounty(input);

        System.out.println("Enter street: ");
        input = sc.nextLine();
        newAdd.setStreet(input);

        int input2;

        System.out.println("Enter street number: ");
        input2 = sc.nextInt();
        newAdd.setStreetNumber(input2);


        return newAdd;

    }


    private static void readInitial(){
        //TODO
    }


}
