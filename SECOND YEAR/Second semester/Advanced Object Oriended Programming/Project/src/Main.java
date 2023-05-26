import service.Service;

import java.sql.*;

public class Main {
    public static void main(String[] args) {
        try {

            Class.forName("oracle.jdbc.OracleDriver");
            Connection con=DriverManager.getConnection(
                    "jdbc:oracle:thin:@localhost:1521:xe","test","test1234");

            String query = "INSERT INTO address ( city,country, street, \"NUMBER\") VALUES ( 'Bucuresti','Romania','Alexandru Macedon', 29)";
            Statement pstmt = con.prepareStatement(query);
            ResultSet rs = pstmt.executeQuery(query);



        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        Service service = Service.getInstance();
        Service.run();


    }
}