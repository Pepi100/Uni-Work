import service.Service;

import java.sql.*;

public class Main {
    public static void main(String[] args) {
        try {

            Class.forName("oracle.jdbc.OracleDriver");
            Connection con=DriverManager.getConnection(
                    "jdbc:oracle:thin:@localhost:1521:xe","test","test1234");





        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        Service service = Service.getInstance();
        Service.run();


    }
}