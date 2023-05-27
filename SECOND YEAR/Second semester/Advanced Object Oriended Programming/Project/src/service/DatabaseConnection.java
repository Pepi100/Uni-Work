package service;

import model.Address;
import model.product.Headphones;
import model.product.Manufacturer;
import model.product.Microphone;
import model.product.Product;
import model.user.*;
import oracle.jdbc.OraclePreparedStatement;

import java.sql.*;

public class DatabaseConnection {


//singleton class
    private static final String DB_DRIVER = "oracle.jdbc.OracleDriver";
    private static final String DB_URL = "jdbc:oracle:thin:@localhost:1521:xe";
    private static final String DB_USER = "test";
    private static final String DB_PASS = "test1234";

    private static Connection con;
    private static DatabaseConnection instance;

    private DatabaseConnection(){
        try {

            Class.forName(DB_DRIVER);
            con= DriverManager.getConnection(DB_URL,DB_USER,DB_PASS);

        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    public static int add(Address a)  {

        String sql = "INSERT INTO address (city, country, street, streetNumber) VALUES (?, ?, ?, ?) returning ADDRESS_ID into ?";
        int id = -1;
        OraclePreparedStatement opstmt = null;
        try {
            opstmt = (OraclePreparedStatement)con.prepareStatement(sql);
            opstmt.setString(1, a.getCity());
            opstmt.setString(2, a.getCounty());
            opstmt.setString(3, a.getStreet());
            opstmt.setInt(4, a.getStreetNumber());
            opstmt.registerReturnParameter(5, Types.INTEGER);
            opstmt.execute();
            ResultSet rs = opstmt.getReturnResultSet();
            rs.next();
            id = rs.getInt(1);
//            System.out.print(id);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }


        return id;
    }

    public static int add(User u)  {

        String sql = "INSERT INTO \"USER\" (NAME, EMAIL) VALUES (?, ?) returning USER_ID into ?";
        int id = -1;
        OraclePreparedStatement opstmt = null;
        try {
            opstmt = (OraclePreparedStatement)con.prepareStatement(sql);
            opstmt.setString(1, u.getName());
            opstmt.setString(2, u.getEmail());
            opstmt.registerReturnParameter(3, Types.INTEGER);
            opstmt.execute();
            ResultSet rs = opstmt.getReturnResultSet();
            rs.next();
            id = rs.getInt(1);
//            System.out.print(id);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }


        return id;
    }

    public static void add(Customer c){

        //adding address into database
        int address_id = add(c.getAddress());
        int user_id = add((User) c);


        String sql = "INSERT INTO customer (USER_ID, ADDRESS_ID) VALUES (?, ?)";
        PreparedStatement pstmt = null;
        try{

            pstmt = con.prepareStatement(sql);
            pstmt.setInt(1, user_id);
            pstmt.setInt(2, address_id);
            pstmt.executeUpdate();
        }catch (SQLException e){

        }


    }

    public static void add(Employee c){

        //adding address into database
        int user_id = add((User) c);


        String sql = "INSERT INTO EMPLOYEE (USER_ID, DEPARTMENT) VALUES (?, ?)";
        PreparedStatement pstmt = null;
        try{

            pstmt = con.prepareStatement(sql);
            pstmt.setInt(1, user_id);
            pstmt.setString(2, c.getDepartment());
            pstmt.executeUpdate();
        }catch (SQLException e){

        }


    }

    public static int add(Manufacturer m)  {

        String sql = "INSERT INTO MANUFACTURER (NAME, EMAIL) VALUES ( ?, ?) returning MANUFACTURER_ID into ?";
        int id = -1;
        OraclePreparedStatement opstmt = null;
        try {
            opstmt = (OraclePreparedStatement)con.prepareStatement(sql);
            opstmt.setString(1, m.getName());
            opstmt.setString(2, m.getEmail());
            opstmt.registerReturnParameter(3, Types.INTEGER);
            opstmt.execute();
            ResultSet rs = opstmt.getReturnResultSet();
            rs.next();
            id = rs.getInt(1);
//            System.out.print(id);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }


        return id;
    }

    public static int add(Product p)  {

        int manufacturer_id = add(p.getBrand());
        String sql = "INSERT INTO PRODUCT (MANUFACTURER_ID, PRICE, NAME) VALUES (?, ?,?) returning PRODUCT_ID into ?";
        int id = -1;
        OraclePreparedStatement opstmt = null;
        try {
            opstmt = (OraclePreparedStatement)con.prepareStatement(sql);
            opstmt.setInt(1, manufacturer_id );
            opstmt.setFloat(2, p.getPrice());
            opstmt.setString(3, p.getName());
            opstmt.registerReturnParameter(4, Types.INTEGER);
            opstmt.execute();
            ResultSet rs = opstmt.getReturnResultSet();
            rs.next();
            id = rs.getInt(1);
//            System.out.print(id);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }


        return id;
    }

    public static void add(Headphones h){

        //adding product into database
        int prod_id = add((Product) h);


        String sql = "INSERT INTO HEADPHONES (PRODUCT_ID, FITTYPE, CONNECTIVITYTYPE) VALUES (?, ?,?)";
        PreparedStatement pstmt = null;
        try{

            pstmt = con.prepareStatement(sql);
            pstmt.setInt(1, prod_id);
            pstmt.setString(2, h.getFit().toString());
            pstmt.setString(3, h.getConnectivity().toString());
            pstmt.executeUpdate();
        }catch (SQLException e){

        }


    }

    public static void add(Microphone m){

        //adding product into database
        int prod_id = add((Product) m);


        String sql = "INSERT INTO MICROPHONE (PRODUCT_ID, CAPSULE, MICCONNECTIVITYTYPE) VALUES (?, ?,?)";
        PreparedStatement pstmt = null;
        try{

            pstmt = con.prepareStatement(sql);
            pstmt.setInt(1, prod_id);
            pstmt.setString(2, m.getCapsule().toString());
            pstmt.setString(3, m.getConnectivity().toString());
            pstmt.executeUpdate();
        }catch (SQLException e){

        }


    }


    public static DatabaseConnection getInstance() {
        if (instance == null) {
            instance = new DatabaseConnection();
        }
        return instance;
    }
}
