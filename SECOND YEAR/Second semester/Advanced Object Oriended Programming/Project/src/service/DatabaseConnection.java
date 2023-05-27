package service;

import model.Address;
import model.product.*;
import model.user.*;
import oracle.jdbc.OraclePreparedStatement;

import java.sql.*;
import java.util.ArrayList;
import java.util.Vector;

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

    //Create
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
            System.out.println(e.toString());
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

//    Read

    public static ArrayList<Manufacturer> getManufacturers(){
        ArrayList<Manufacturer> list = new ArrayList<Manufacturer>();

        String sql = "SELECT name, email , MANUFACTURER_ID FROM MANUFACTURER";
        try {

            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(sql);

            while(rs.next()){
                Manufacturer m= new Manufacturer(rs.getString("name"), rs.getString("email"));
                m.setManufacturer_id(rs.getInt("MANUFACTURER_ID"));
                list.add(m);
            }

        }catch (SQLException e){

        }


        return list;


    }

    public static ArrayList<Customer> getCustomers(){
        ArrayList<Customer> list = new ArrayList<Customer>();

        String sql = "SELECT name, email, STREET, CITY, STREETNUMBER, COUNTRY, u.USER_ID as userid, CUSTOMER_ID, A2.ADDRESS_ID as aid from \"USER\" u " +
                "JOIN CUSTOMER C2 on u.USER_ID = C2.USER_ID " +
                "JOIN ADDRESS A2 on C2.ADDRESS_ID = A2.ADDRESS_ID ";
        try {

            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(sql);

            while(rs.next()){
                Customer c= new Customer();
                c.setName(rs.getString("name"));
                c.setEmail(rs.getString("email"));
                c.setCustomer_id(rs.getInt("CUSTOMER_ID"));
                c.setUser_id(rs.getInt("userid"));
                Address a= new Address(rs.getString("CITY"),
                        rs.getString("COUNTRY"),
                        rs.getString("STREET"),
                        rs.getInt("STREETNUMBER"));
                a.setAddress_id(rs.getInt("aid"));
                c.setAddress(a);
                list.add(c);
            }

        }catch (SQLException e){
            System.out.printf(String.valueOf(e));
        }


        return list;


    }

    public static ArrayList<Headphones> getHeadphones(){
        ArrayList<Headphones> list = new ArrayList<Headphones>();

        String sql = "SELECT p.name as pname, price, fittype, connectivitytype, m.name AS mname, email, M.MANUFACTURER_ID as mid, HEADPHONES_ID, p.PRODUCT_ID as pid from PRODUCT p " +
                    "JOIN HEADPHONES H on p.PRODUCT_ID = H.PRODUCT_ID "+
                    "JOIN MANUFACTURER M on p.MANUFACTURER_ID = M.MANUFACTURER_ID";
        try {

            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(sql);

            while(rs.next()){
                Headphones c= new Headphones();
                c.setName(rs.getString("pname"));
                c.setPrice(rs.getFloat("price"));
                c.setProduct_id(rs.getInt("pid"));
                c.setHeadphones_id(rs.getInt("HEADPHONES_ID"));
                c.setFit(FitType.valueOf(rs.getString("fittype")));
                c.setConnectivity(ConnectivityType.valueOf(rs.getString("connectivitytype")));
                Manufacturer a= new Manufacturer(rs.getString("mname"),
                        rs.getString("email"));
                a.setManufacturer_id(rs.getInt("mid"));
                c.setBrand(a);
                list.add(c);
            }

        }catch (SQLException e){
            System.out.printf("A murit getHeadphone");
        }


        return list;


    }
    public static ArrayList<Microphone> getMicrophones()  {
        ArrayList<Microphone> list = new ArrayList<Microphone>();

        String sql = "SELECT p.name AS pname, price, CAPSULE, MICCONNECTIVITYTYPE, m.name AS mname, email, M.MANUFACTURER_ID as mid, MICROPHONE_ID, p.PRODUCT_ID as pid from PRODUCT p " +
                "JOIN Microphone H on p.PRODUCT_ID = H.PRODUCT_ID "+
                "JOIN MANUFACTURER m on p.MANUFACTURER_ID = m.MANUFACTURER_ID";
        try {

            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery(sql);


            while(rs.next()){

                Microphone c= new Microphone();
                c.setName(rs.getString("pname"));
                c.setPrice(rs.getFloat("price"));
                c.setProduct_id(rs.getInt("pid"));
                c.setMicrophone_id(rs.getInt("MICROPHONE_ID"));
                c.setCapsule(CapsuleType.valueOf(rs.getString("CAPSULE")));
                c.setConnectivity(MicConnectivityType.valueOf(rs.getString("MICCONNECTIVITYTYPE")));
                Manufacturer a= new Manufacturer(rs.getString("mname"),
                        rs.getString("email"));
                a.setManufacturer_id(rs.getInt("mid"));
                c.setBrand(a);
                list.add(c);
            }

        }catch (SQLException e){
            System.out.printf("dieded");
        }


        return list;



    }

    //delete

    public static void deleteManufacturer(int id){
        String sql = "DELETE FROM MANUFACTURER where MANUFACTURER_ID =  ?";
        OraclePreparedStatement opstmt = null;

        PreparedStatement pstmt = null;
        try{

            pstmt = con.prepareStatement(sql);
            pstmt.setInt(1, id);
            pstmt.executeUpdate();
        }catch (SQLException e){
            System.out.println(e.toString());
        }
    }

    public static void deleteProduct(int id) {
        String sql = "DELETE FROM PRODUCT where product_id =  ?";
        OraclePreparedStatement opstmt = null;

        PreparedStatement pstmt = null;
        try{

            pstmt = con.prepareStatement(sql);
            pstmt.setInt(1, id);
            pstmt.executeUpdate();
        }catch (SQLException e){
            System.out.println(e.toString());
        }
    }

    public static void deleteCustomer(int id) {
        String sql = "DELETE FROM CUSTOMER where CUSTOMER_ID =  ?";
        OraclePreparedStatement opstmt = null;

        PreparedStatement pstmt = null;
        try{

            pstmt = con.prepareStatement(sql);
            pstmt.setInt(1, id);
            pstmt.executeUpdate();
        }catch (SQLException e){
            System.out.println(e.toString());
        }
    }

    public static void deleteAddress(int id){
        String sql = "DELETE FROM ADDRESS where ADDRESS_ID =  ?";
        OraclePreparedStatement opstmt = null;

        PreparedStatement pstmt = null;
        try{

            pstmt = con.prepareStatement(sql);
            pstmt.setInt(1, id);
            pstmt.executeUpdate();
        }catch (SQLException e){
            System.out.println(e.toString());
        }
    }


//    update

    public static void update(int id, Manufacturer m){
        String sql = "UPDATE manufacturer SET NAME = ?, EMAIL = ? where MANUFACTURER_ID = ?";


        PreparedStatement pstmt = null;
            try{

            pstmt = con.prepareStatement(sql);
            pstmt.setString(1, m.getName());
            pstmt.setString(2, m.getEmail());
            pstmt.setInt(3, id);
            pstmt.executeUpdate();
        }catch (SQLException e){
            System.out.println(e.toString());
        }
    }

    public static void update(int id, Address a){
        String sql = "UPDATE ADDRESS SET CITY =?, COUNTRY = ?, STREET =? , STREETNUMBER = ? where ADDRESS_ID = ?";


        PreparedStatement pstmt = null;
        try{

            pstmt = con.prepareStatement(sql);
            pstmt.setString(1, a.getCity());
            pstmt.setString(2, a.getCounty());
            pstmt.setString(3, a.getStreet());
            pstmt.setInt(4, a.getStreetNumber());
            pstmt.setInt(5, id);
            pstmt.executeUpdate();
        }catch (SQLException e){
            System.out.println(e.toString());
        }
    }

    public static void update(int id, Customer a){
        String sql = "UPDATE ADDRESS SET CITY =?, COUNTRY = ?, STREET =? , STREETNUMBER = ? where ADDRESS_ID = ?";


        PreparedStatement pstmt = null;
        try{

            pstmt = con.prepareStatement(sql);
//            pstmt.setString(1, a.getCity());
//            pstmt.setString(2, a.getCounty());
//            pstmt.setString(3, a.getStreet());
//            pstmt.setInt(4, a.getStreetNumber());
//            pstmt.setInt(5, id);
            pstmt.executeUpdate();
        }catch (SQLException e){
            System.out.println(e.toString());
        }
    }





    // singleton
    public static DatabaseConnection getInstance() {
        if (instance == null) {
            instance = new DatabaseConnection();
        }
        return instance;
    }


}
