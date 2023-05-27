import service.Service;

import java.sql.*;
import java.util.Scanner;

public class Main {


private static Service service;
    public static void main(String[] args)  {

        service = Service.getInstance();
        int input = -1;
        do{
            System.out.println("Choose an option from the following:");
            System.out.println("1 - Print menu.");
            System.out.println("2 - Insert menu.");
            System.out.println("3 - Update menu.");
            System.out.println("4 - Delete menu.");
            System.out.println("0 - Exit the program.");


            Scanner reader = new Scanner(System.in);
            input = reader.nextInt();

            switch (input){
                case 1 -> {
                    printMenu();
                }
                case 2 -> {
                    insertMenu();
                }
                case 3 -> {
                    updateMenu();
                }
                case 4 -> {
                    deleteMenu();
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

    private static void printMenu() {
        int input = -1;
        do {
            System.out.println("Printing menu:");
            System.out.println("1 - Print products.");
            System.out.println("2 - Print manufacturers.");
            System.out.println("3 - Print customers.");
            System.out.println("4 - Print adresses / NaN.");
            System.out.println("0 - Back.");


            Scanner reader = new Scanner(System.in);
            input = reader.nextInt();

            switch (input) {
                case 1 -> {
                    service.printProducts();
                }
                case 2 -> {
                    service.printManufacturers();
                }
                case 3 -> {
                    service.printCustomers();
                }
                case 4 -> {

                }

                case 0 -> {

                }
                default -> {
                    System.out.println("!!ALERT!! The number you entered is not available, please try again.");
                }

            }
        } while (input != 0);
    }

    private static void insertMenu() {
        int input = -1;
        do {
            System.out.println("Inserting menu:");
            System.out.println("1 - Insert product.");
            System.out.println("2 - Insert manufacturer.");
            System.out.println("3 - Insert users.");
            System.out.println("0 - Back.");


            Scanner reader = new Scanner(System.in);
            input = reader.nextInt();

            switch (input) {
                case 1 -> {
                    service.addProduct();
                }
                case 2 -> {
                    service.addManufacturer();
                }
                case 3 -> {
                    service.addUser();
                }

                case 0 -> {

                }
                default -> {
                    System.out.println("!!ALERT!! The number you entered is not available, please try again.");
                }

            }
        } while (input != 0);
    }

    private static void updateMenu() {
        int input = -1;
        do {
            System.out.println("Printing menu:");
            System.out.println("1 - Update products.");
            System.out.println("2 - Update manufacturers.");
            System.out.println("3 - Update customers.");
            System.out.println("0 - Exit the program.");


            Scanner reader = new Scanner(System.in);
            input = reader.nextInt();

            switch (input) {
                case 1 -> {
                    service.printProducts();
                }
                case 2 -> {
                    service.printManufacturers();
                }
                case 3 -> {
                    service.printCustomers();
                }

                case 0 -> {

                }
                default -> {
                    System.out.println("!!ALERT!! The number you entered is not available, please try again.");
                }

            }
        } while (input != 0);
    }

    private static void deleteMenu() {
        int input = -1;
        do {
            System.out.println("Delete menu:");
            System.out.println("1 - Delete products.");
            System.out.println("2 - Delete manufacturers.");
            System.out.println("3 - Delete customers.");
            System.out.println("0 - Exit the program.");


            Scanner reader = new Scanner(System.in);
            input = reader.nextInt();

            switch (input) {
                case 1 -> {
                    service.deleteProduct();
                }
                case 2 -> {
                    service.deleteManufacturer();
                }
                case 3 -> {
                    service.deleteCustomer();
                }

                case 0 -> {

                }
                default -> {
                    System.out.println("!!ALERT!! The number you entered is not available, please try again.");
                }

            }
        } while (input != 0);
    }


}