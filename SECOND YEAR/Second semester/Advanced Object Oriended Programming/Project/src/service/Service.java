package service;
import model.Address;
import model.product.Manufacturer;
import model.product.*;
import model.user.*;


import java.util.ArrayList;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Service {
    private static Service instance;
    private static DatabaseConnection DBinstance;

    private Service() {
//        manufacturers = new ArrayList<Manufacturer>();
//        products = new ArrayList<Product>();
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

    //adding
    public static void addManufacturer(){
        Scanner sc=new Scanner(System.in);
        Manufacturer newMan = new Manufacturer();

        int manufacturer_id = -1;
        System.out.println("Inserting a new manufacturer: ");
        System.out.println("Enter a name for the manufacturer: ");
        String input = sc.nextLine();
        newMan.setName(input);

        System.out.println("Enter an email for the manufacturer: ");
        input = sc.nextLine();
        newMan.setEmail(input);


//        manufacturers.add(newMan);
        manufacturer_id = DatabaseConnection.add(newMan);

    }

    public static void addProduct(){
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
        String name = sc.nextLine();

        System.out.println("Enter a price for the product: ");
        float price = sc.nextFloat();


        newProd.setName(name);
        newProd.setPrice(price);


        System.out.println("Now you will need to select a manufacturer for the product: ");


            printManufacturers();
            System.out.println("Select a number from the list above: ");
            int manufacturerId = sc.nextInt();

        if (type == 1){
            //headphones
            System.out.println("Select the type of connectivity : ");
            System.out.println("1 - Wireless.");
            System.out.println("2 - Wired.");
            int option= sc.nextInt();

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

            DatabaseConnection.add((Headphones) newProd, manufacturerId);

        }else{
            System.out.println("Select the type of microphone: ");
            System.out.println("1 - Dynamic.");
            System.out.println("2 - Condenser.");
            int option= sc.nextInt();

          if (option ==1) {
                    ((Microphone) newProd).setCapsule(CapsuleType.DYNAMIC);
                }
                else{
                    ((Microphone) newProd).setCapsule(CapsuleType.CONDENSER);
                }



            System.out.println("Select the type of connectivity : ");
            System.out.println("1 - XRL. ");
            System.out.println("2 - USB. ");
            System.out.println("3 - Jack. ");
            option= sc.nextInt();

            switch (option){
                case 1 -> {
                    ((Microphone) newProd).setConnectivity(MicConnectivityType.XLR);
                }
                case 2 -> {
                    ((Microphone) newProd).setConnectivity(MicConnectivityType.USB);
                }
                default -> {
                    ((Microphone) newProd).setConnectivity(MicConnectivityType.JACK);
                }
            }

            DatabaseConnection.add((Microphone) newProd, manufacturerId);
        }


    }

    public static void addUser()  {
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
        sc.nextLine();

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
            System.out.println("Enter a department: ");
            String dep = sc.nextLine();
            ((Employee) newUser).setDepartment(dep);
            DatabaseConnection.add(((Employee) newUser));

        }




    }

    //deleting



    public static void deleteManufacturer(){
        printManufacturers();
        System.out.printf("Enter the id of the manufacturer you would like to delete: ");
        Scanner sc = new Scanner(System.in);
        int input = sc.nextInt();
        DatabaseConnection.deleteManufacturer(input);
    }

    public static void deleteProduct(){
        printProducts();
        System.out.printf("Enter the id of the product you would like to delete: ");
        Scanner sc = new Scanner(System.in);
        int input = sc.nextInt();
        DatabaseConnection.deleteProduct(input);
    }

    public static void deleteCustomer(){
        printCustomers();
        System.out.printf("Enter the id of the customer you would like to delete: ");
        Scanner sc = new Scanner(System.in);
        int input = sc.nextInt();
        DatabaseConnection.deleteCustomer(input);
    }


    //printing
    public static void printManufacturers(){
        ArrayList<Manufacturer> manufacturers = DatabaseConnection.getManufacturers();
        System.out.println("Here`s a list of all the manufacturers:");
        for (int i = 0; i < manufacturers.size(); i++) {
            System.out.println("  " +(i+1)+ "  " +manufacturers.get(i));
        }
        System.out.println('\n');
    }

    public static void printProducts()  {

        ArrayList<Microphone> mic = DatabaseConnection.getMicrophones();
        ArrayList<Headphones> hed = DatabaseConnection.getHeadphones();




        Comparator<Product> priceCompDesc = new Comparator<Product>() {

            @Override
            public int compare(Product o1, Product o2) {
                float p1=  o1.getPrice();
                float p2=  o2.getPrice();
                return Float.compare(p2, p1);
            }
        };

        Comparator<Product> priceComp = new Comparator<Product>() {
            @Override
            public int compare(Product o1, Product o2) {
                float p1=  o1.getPrice();
                float p2=  o2.getPrice();
                return -1*Float.compare(p2, p1);
            }
        };

        Comparator<Product> nameCompDesc = new Comparator<Product>() {

            @Override
            public int compare(Product o1, Product o2) {
                String p1=  o1.getName();
                String p2=  o2.getName();
                return -1*p1.compareTo(p2);
            }
        };

        Comparator<Product> nameComp = new Comparator<Product>() {

            @Override
            public int compare(Product o1, Product o2) {
                String p1=  o1.getName();
                String p2=  o2.getName();
                return p1.compareTo(p2);
            }
        };

        Comparator<Product> manufacturerComp = new Comparator<Product>() {

            @Override
            public int compare(Product o1, Product o2) {
                String p1=  o1.getBrand().getName();
                String p2=  o2.getBrand().getName();
                return p1.compareTo(p2);
            }
        };
        if(mic.size() >0 || hed.size()>0){

            System.out.println("How would you like the products to be ordered?");
            System.out.println("1 - Price.");
            System.out.println("2 - Price, descending.");
            System.out.println("3 - Name.");
            System.out.println("4 - Name, descending.");
            System.out.println("5 - Manufacturer.");

            Scanner sc = new Scanner(System.in);
            int input = sc.nextInt();

            PriorityQueue<Product> pQueue = null;
            switch (input){
                case 1 ->{
                    pQueue = new PriorityQueue<Product>(priceComp );

                }
                case 2 ->{
                    pQueue = new PriorityQueue<Product>(priceCompDesc );
                }
                case 3 ->{
                    pQueue = new PriorityQueue<Product>(nameComp );

                }
                case 4 ->{
                    pQueue = new PriorityQueue<Product>(nameCompDesc );

                }
                case 5 ->{
                    pQueue = new PriorityQueue<Product>(manufacturerComp );
                }
                default -> {

                }

            }


            pQueue.addAll(mic);
            pQueue.addAll(hed);

            System.out.println(pQueue);


        }

        else
            System.out.println("There are no products at the moment.");
    }

    public static void printCustomers(){
        ArrayList<Customer> customers = DatabaseConnection.getCustomers();
        System.out.println("Here`s a list of all the customers:");
        for (Customer customer : customers) {
            System.out.println(customer);
        }
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


}
